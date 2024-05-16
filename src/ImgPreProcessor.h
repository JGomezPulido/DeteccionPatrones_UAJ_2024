#pragma once
#include "opencv2/imgcodecs.hpp"
using namespace cv;

class ImgPreProcessor
{
	protected:
		std::string imagePath;
		Mat destino;
		Mat source;

	public:
	ImgPreProcessor(std::string fileName);
	ImgPreProcessor(Mat image);
	ImgPreProcessor();

	virtual ~ImgPreProcessor() = 0;
	virtual cv::Mat processImage(Mat image) = 0;

	inline Mat getDest() { return destino; };
};

