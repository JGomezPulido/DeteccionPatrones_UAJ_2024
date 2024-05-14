#pragma once
#include "ImgPreProcessor.h"
#include "PatternDetector.h"
#include "Analyzer.h"
#include <string>
class ImageTester
{
private:
	std::string pathFile;
	ImgPreProcessor* preProcessor;
	PatternDetector* patternDetector;
	Analyzer* analyzer;

public:
	ImageTester(std::string fileName);
	~ImageTester();
	void testImage();

};

