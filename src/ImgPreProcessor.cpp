#include "ImgPreProcessor.h"

ImgPreProcessor::ImgPreProcessor(std::string fileName)
{
	imagePath = fileName;
}

ImgPreProcessor::ImgPreProcessor(Mat image)
{
	source = image;
}

ImgPreProcessor::ImgPreProcessor()
{
}

ImgPreProcessor::~ImgPreProcessor()
{
}


