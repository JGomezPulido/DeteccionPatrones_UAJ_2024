#include "ImageTester.h"
#include "ImgPreProcessorBW.h"
#include "Analyzer.h"
#include "StraightPatternDetector.h"


ImageTester::ImageTester(std::string fileName)
{
	// Leer la imagen
	image = imread(samples::findFile(fileName), IMREAD_GRAYSCALE);					
	// Check if image is loaded fine

	if (image.empty()) {	
		// Comunicar que no se ha encontrado la imagen
		std::cerr << "Error: Failed to load or process image." << std::endl;
	}
	preProcessor = new ImgPreProcessorBW(image);	
	patternDetector = new StraightPatternDetector();
	analyzer = new Analyzer();
}

ImageTester::ImageTester(cv::Mat imagen)
{
	image = imagen;
	preProcessor = new ImgPreProcessorBW(image);
	patternDetector = new StraightPatternDetector();
	analyzer = new Analyzer();
}

ImageTester::ImageTester()
{
	preProcessor = new ImgPreProcessorBW();
	patternDetector = new StraightPatternDetector();
	analyzer = new Analyzer();
}

ImageTester::~ImageTester()
{
	delete preProcessor;
	delete patternDetector;
	delete analyzer;
}

void ImageTester::testImage()
{
	if(isImageDangerous(image))
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

bool ImageTester::testFrame(const cv::Mat& imageParam, double& brightness, int& flash, PatternMap& movement){
	
	cv::Mat ogImage = imageParam.clone();
	
	// Procesamos la imagen y guardamos el material
	Mat img = preProcessor->processImage(imageParam);

	// Detectamos las lineas en la imagen
	patternDetector->detectLines(img);

	// Detectamos el patron de lineas en la imagen
	patternDetector->detectPattern();

	// Se analiza el frame teniendo en cuenta los valores de brillo, flash y movimiento del anterior frame
	return analyzer->analyze(ogImage, patternDetector->getPossiblePatterns(), brightness, flash, movement);

}


