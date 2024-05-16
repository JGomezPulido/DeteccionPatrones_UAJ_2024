#pragma once
#include "opencv2/imgproc.hpp"
using namespace cv;

class PatternDetector
{
	protected:
		std::vector<Vec2f> lines;
		std::vector<Vec4i> linesP;

	public:
	virtual void detectLines(Mat destino) = 0;
	virtual void detectPattern() = 0;
};

