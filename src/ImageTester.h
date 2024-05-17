#pragma once
#include <string>
#include "opencv2/core.hpp"
#include <unordered_map>
class ImgPreProcessor;
class StraightPatternDetector;
class Analyzer;
struct LineInfo;
typedef std::unordered_multimap<int, LineInfo> PatternMap;

class ImageTester
{
private:
	cv::Mat image;
	std::string pathFile;
	ImgPreProcessor* preProcessor;
	StraightPatternDetector* patternDetector;
	Analyzer* analyzer;

public:
	ImageTester(std::string fileName);
	ImageTester(cv::Mat imagen);
	ImageTester();
	ImageTester(const cv::Mat& initialImage,
				ImgPreProcessor* preProcess, StraightPatternDetector* patternDetect, Analyzer* analyzer)
				: image(initialImage), 
				preProcessor(preProcess), patternDetector(patternDetect), analyzer(analyzer) {} //overloading

	~ImageTester();
	void testImage();
	bool isImageDangerous(const cv::Mat& imageParam);
	bool testFrame(const cv::Mat& imageParam, double& brightness, int& flash, PatternMap& movement);


};

