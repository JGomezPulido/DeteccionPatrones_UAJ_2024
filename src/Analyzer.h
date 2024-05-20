#pragma once
#include "StraightPatternDetector.h"
#include <opencv2/opencv.hpp>

class Analyzer
{
private:

	double maxBrightness;
	double brightnessDiff;
	double maxLinesFlash;
	bool dangerousPattern;

	bool analyzeBrightness(const cv::Mat& frame);
	bool analyzeBrightness(double& brightness, const cv::Mat& frame2);
	bool analyzeFlash(int& nLineasF1, int nLineasF2);
public:

	Analyzer(double maxBr, double brDiff, double maxLF);
	~Analyzer();
	bool analyze(const cv::Mat& ogImg);
	bool analyze(const cv::Mat& ogImg, const PatternMap& pattern, double& brightness, int& flash);
};

