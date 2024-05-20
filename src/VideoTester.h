#pragma once
#include <string>
#include "ImageTester.h"
#include <opencv2/videoio.hpp>

class VideoTester
{

private:
	std::string fileName;
	ImageTester* imageTester = nullptr;
	cv::VideoCapture video;

public:
	VideoTester(std::string pathFile);
	~VideoTester();
	bool init(double maxBr, double brDiff, double maxLF, int threshold, double minLenght, double maxGap);
	void testVideo();
};

