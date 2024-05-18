#pragma once
#include <string>
#include "ImageTester.h"
#include <opencv2/videoio.hpp>

class VideoTester
{

private:
	std::string fileName;
	ImageTester* imageTester;
	cv::VideoCapture video;

public:
	VideoTester(std::string pathFile);
	~VideoTester();
	bool init();
	void testVideo();

};

