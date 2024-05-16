#include "VideoTester.h"
#include <iostream>
#include <opencv2/highgui.hpp>

VideoTester::VideoTester(std::string fileName)
{

	if (!video.open(fileName)) {
		std::cerr << "Error: Unable to open video file." << std::endl;
	}

	imageTester = new ImageTester();

}

VideoTester::~VideoTester()
{
    delete imageTester;
    video.release();
}

void VideoTester::testVideo()
{
    cv::Mat frame;
    while (video.read(frame)) {
        // Verificar si se ha llegado al final del video
        if (frame.empty()) {
            std::cout << "Fin del video." << std::endl;
            break;
        }
        //imageTester->testImage(frame);
        //cv::waitKey();

       
    }

}
