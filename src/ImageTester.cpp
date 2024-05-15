#include "ImageTester.h"

ImageTester::ImageTester(std::string fileName)
{
	pathFile = fileName;
	preProcessor = new ImgPreProcessorBW(fileName);
	patternDetector = new PatternDetector();
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
	// Procesamos la imagen y guardamos el material
	Mat img = preProcessor->processImage();

	// Detectamos las lineas en la imagen
	patternDetector->detectLines(img, preProcessor->getCdst().clone(), preProcessor->getCdstP());

	// Detectamos el patron de lineas en la imagen
	patternDetector->detectPattern();

	// Analizamos el patron de lineas
	analyzer->analyzeImage();
}


