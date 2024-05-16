#pragma once
#include "opencv2/imgproc.hpp"

class PatternDetector
{
	public:
	virtual void detectLines(const cv::Mat& destino) = 0;
	virtual bool detectPattern() = 0;
};

