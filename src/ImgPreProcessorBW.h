#pragma once
#include "ImgPreProcessor.h"

class ImgPreProcessorBW : public ImgPreProcessor
{
public:
	 cv::Mat processImage(const Mat& image) override;
	 ImgPreProcessorBW() : ImgPreProcessor() {};

	 ImgPreProcessorBW(std::string fileName) :ImgPreProcessor(fileName) {};
	 ImgPreProcessorBW(const Mat& image) : ImgPreProcessor(image) {};	

	 ~ImgPreProcessorBW() {};
private: 
	Mat destNoNoise;

	void lessNoise(Mat source);
};

