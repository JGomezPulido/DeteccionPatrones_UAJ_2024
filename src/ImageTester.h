#pragma once
#include <string>
#include "opencv2/core.hpp"

class ImgPreProcessor;
class PatternDetector;
class Analyzer;

class ImageTester
{
private:
	cv::Mat image;
	std::string pathFile;
	ImgPreProcessor* preProcessor;
	PatternDetector* patternDetector;
	Analyzer* analyzer;

public:
	ImageTester(std::string fileName);
	~ImageTester();
	void testImage();

};

