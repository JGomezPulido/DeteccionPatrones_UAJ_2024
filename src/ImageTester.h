#pragma once
#include <string>

class ImgPreProcessor;
class PatternDetector;
class Analyzer;

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

