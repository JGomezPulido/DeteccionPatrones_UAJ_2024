#pragma once
#include <string>
#include "ImageTester.h"
#include <opencv2/videoio.hpp>

class VideoTester
{

private:
	std::string pathFile;
	ImageTester* imageTester;
	cv::VideoCapture video;

public:
	VideoTester(std::string fileName);
	~VideoTester();
	void testVideo();

};

