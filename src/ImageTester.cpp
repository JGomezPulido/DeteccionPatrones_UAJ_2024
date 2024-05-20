#include "ImageTester.h"
#include "ImgPreProcessorBW.h"
#include "Analyzer.h"
#include "StraightPatternDetector.h"
#include "checkML.h"

ImageTester::ImageTester(std::string pathFile) : fileName(pathFile) {}

ImageTester::ImageTester(double maxBr, double brDiff, double maxLF, int threshold, double minLenght,double maxGap)
{
	preProcessor = new ImgPreProcessorBW();
	patternDetector = new StraightPatternDetector(threshold, minLenght, maxGap);
	analyzer = new Analyzer(maxBr, brDiff,maxLF);
}

ImageTester::~ImageTester()
{
	delete preProcessor;
	delete patternDetector;
	delete analyzer;
}

bool ImageTester::init(double maxBr, double brDiff, double maxLF, int threshold, double minLenght, double maxGap)
{
	// Leer la imagen
	try {
		image = imread(samples::findFile(fileName), IMREAD_GRAYSCALE);
	}
	catch (Exception e) {
		// Comunicar que no se ha encontrado la imagen
		std::cout << e.what();
		std::cerr << "ERROR: Failed to load or process image." << std::endl;
		return false;
	}

	preProcessor = new ImgPreProcessorBW(image);
	patternDetector = new StraightPatternDetector(threshold, minLenght, maxGap);
	analyzer = new Analyzer(maxBr,brDiff,maxLF);

	return true;
}

void ImageTester::testImage()
{
	if (isImageDangerous(image))
		std::cout << "La imagen es peligrosa" << std::endl;
	else
		std::cout << "La imagen no es peligrosa" << std::endl;

}

bool ImageTester::isImageDangerous(const cv::Mat& imageParam)
{
	cv::Mat ogImage = imageParam.clone();

	// Procesamos la imagen y guardamos el material
	Mat img = preProcessor->processImage(imageParam);

	// Detectamos las lineas en la imagen
	patternDetector->detectLines(img);


	// Si hay mucho brillo y un patron de lineas en la imagen, se considera peligrosa la imagen	
	return patternDetector->detectPattern() && analyzer->analyze(ogImage);
}

bool ImageTester::testFrame(const cv::Mat& imageParam, double& brightness, int& flash) {


	if (imageParam.channels() != 1) {
		// Adaptamos la imagen a escala de grises
		cvtColor(imageParam, imageParam, COLOR_BGR2GRAY);
	}

	cv::Mat ogImage = imageParam.clone();


	// Procesamos la imagen y guardamos el material
	Mat img = preProcessor->processImage(imageParam);

	// Detectamos las lineas en la imagen
	patternDetector->detectLines(img);

	// Detectamos el patron de lineas en la imagen
	patternDetector->detectPattern();

	// Se analiza el frame teniendo en cuenta los valores de brillo, flash y movimiento del anterior frame
	return analyzer->analyze(ogImage, patternDetector->getPossiblePatterns(), brightness, flash);

}


