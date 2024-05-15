#pragma once
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
using namespace cv;

class PatternDetector
{
	private:
		std::vector<Vec2f> lines;
		std::vector<Vec4i> linesP;

	public:
	PatternDetector();
	~PatternDetector();
	virtual void detectLines(Mat destino);
	virtual void detectPattern();
};

