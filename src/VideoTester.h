#pragma once
#include <string>
#include "ImageTester.h"
class VideoTester
{

private:
	std::string pathFile;
	ImageTester* imageTester;

public:
	VideoTester(std::string fileName);
	~VideoTester();
	void testVideo();

};

