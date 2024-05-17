#include "VideoTester.h"
#include <iostream>
#include <opencv2/highgui.hpp>
#include "StraightPatternDetector.h"



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
    int nFrame = 0;
    double brightness = 0;
    int flash = 0;
    PatternMap movement = PatternMap();
    bool dangerousPattern = false;
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
        
        dangerousPattern = imageTester->testFrame(frame, brightness, flash, movement);
       
        if (dangerousPattern)
            nFrame++;
        
    }

    // Mirar el numero de frames minimo para que se considere el video peligroso
    if(nFrame > 5)
        std::cout << "El video puede ser peligroso" << std::endl;
    else
        std::cout << "El video deberia ser seguro" << std::endl;



}
