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
	ImageTester(cv::Mat imagen);
	ImageTester();
	ImageTester(const cv::Mat& initialImage,
				ImgPreProcessor* preProcess, PatternDetector* patternDetect, Analyzer* analyzer) 
				: image(initialImage), 
				preProcessor(preProcess), patternDetector(patternDetect), analyzer(analyzer) {} //overloading

	~ImageTester();
	void testImage();
	void testImage(const cv::Mat& imageParam);


};

