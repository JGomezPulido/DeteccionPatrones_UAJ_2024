#pragma once
#include "opencv2/imgcodecs.hpp"
using namespace cv;

class ImgPreProcessor
{
	private:
		std::string imagePath;
		Mat destino, cdst, cdstP;
		Mat source;

	public:
	ImgPreProcessor(std::string fileName);
	~ImgPreProcessor();
	virtual cv::Mat processImage();

};

