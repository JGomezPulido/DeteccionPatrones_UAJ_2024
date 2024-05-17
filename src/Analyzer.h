#pragma once
#include "StraightPatternDetector.h"
#include <opencv2/opencv.hpp>

class Analyzer
{
private:

	int maxBrightness;	
	bool dangerousPattern;

	bool analyzeBrightness(cv::Mat frame);
	bool analyzeBrightness(double brightness, cv::Mat frame2);
	bool analyzeMovement(const PatternMap& patternF1, const PatternMap& patternF2);
	bool analyzeFlash(int nLineasF1, int nLineasF2);
	public:

	Analyzer();
	~Analyzer();
	bool analyze(cv::Mat ogImg);
	bool analyze(cv::Mat ogImg, const PatternMap& pattern, double& brightness, int& flash, PatternMap& movement);
};

