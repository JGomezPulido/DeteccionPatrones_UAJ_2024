#pragma once
#include "ImgPreProcessor.h"

class ImgPreProcessorBW : public ImgPreProcessor
{
public:
	 cv::Mat processImage() override;
	 ImgPreProcessorBW(std::string fileName) :ImgPreProcessor(fileName) {};
	 ~ImgPreProcessorBW() {};
private: 
	Mat destNoNoise;
};

