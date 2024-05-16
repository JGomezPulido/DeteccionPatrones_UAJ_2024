#pragma once

#include <opencv2/opencv.hpp>


class Analyzer
{
private:

	int maxBrightness;	
	bool dangerousPattern;
	bool dangerousBrightness(cv::Mat frame);

	public:

	Analyzer();

	~Analyzer();

	virtual void analyzeImage(cv::Mat image);
};

