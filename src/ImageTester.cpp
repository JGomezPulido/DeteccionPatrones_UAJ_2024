#include "ImageTester.h"
#include "ImgPreProcessorBW.h"
#include "StraightPatternDetector.h"
#include "Analyzer.h"

ImageTester::ImageTester(std::string fileName)
{
	// Loads an image
	// Hacer un try catch para manejar excepciones si no encuentra la imagen
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
	testImage(image);

}

void ImageTester::testImage(const cv::Mat& imageParam)
{

	// Analizamos el brillo de la imagen	
	analyzer->analyzeImage(imageParam);

	// Procesamos la imagen y guardamos el material
	Mat img = preProcessor->processImage(imageParam);

	// Detectamos las lineas en la imagen
	patternDetector->detectLines(img);

	// Detectamos el patron de lineas en la imagen
	patternDetector->detectPattern();
}


