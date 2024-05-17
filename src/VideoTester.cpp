#include "VideoTester.h"
#include <iostream>
#include <opencv2/highgui.hpp>

VideoTester::VideoTester(std::string fileName)
{

    if (!video.open(fileName)) {
		std::cerr << "ERROR: Unable to open video file." << std::endl;
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

    //video.read(frame);
    //imageTester->testImage(frame);

    while (video.read(frame)) {
        // Verificar si se ha llegado al final del video
        if (frame.empty()) {
            std::cout << "Fin del video." << std::endl;
            break;
        }
        //cv::imshow("video", frame);
        //cv::waitKey();
        imageTester->testImage(frame);

    }


}
