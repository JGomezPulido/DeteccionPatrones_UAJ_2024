#pragma once
#include "opencv2/imgcodecs.hpp"
using namespace cv;

class ImgPreProcessor
{
	protected:
		std::string imagePath;
		Mat destino, cdst, cdstP;
		Mat source;

	public:
	ImgPreProcessor(std::string fileName);
	virtual ~ImgPreProcessor() = 0;
	virtual cv::Mat processImage() = 0;
	inline Mat getDest() { return destino; };
	inline Mat getCdst() { return cdst; };
	inline Mat getCdstP() { return cdstP; };
};

