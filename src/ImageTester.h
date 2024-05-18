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
	std::string fileName;
	ImgPreProcessor* preProcessor = nullptr;
	StraightPatternDetector* patternDetector = nullptr;
	Analyzer* analyzer = nullptr;

public:
	ImageTester(std::string fileName);
	ImageTester(double maxBr, double brDiff, double maxLF);
	ImageTester(const cv::Mat& initialImage) : image(initialImage) {} //overloading

	~ImageTester();
	bool init(double maxBr, double brDiff, double maxLF);
	void testImage();
	bool isImageDangerous(const cv::Mat& imageParam);
	bool testFrame(const cv::Mat& imageParam, double& brightness, int& flash);


};

