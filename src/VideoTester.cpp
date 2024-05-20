#include "VideoTester.h"
#include <iostream>
#include <opencv2/highgui.hpp>
#include "checkML.h"

VideoTester::VideoTester(std::string pathFile) : fileName(pathFile) {}

VideoTester::~VideoTester()
{
    delete imageTester;
    video.release();
}

bool VideoTester::init(double maxBr, double brDiff, double maxLF, int threshold, double minLenght, double maxGap)
{
    if (!video.open(fileName)) {
        std::cerr << "ERROR: Unable to open video file." << std::endl;
        return false;
    }

    imageTester = new ImageTester(maxBr, brDiff, maxLF, threshold, minLenght, maxGap);

    return true;
}

void VideoTester::testVideo()
{
    cv::Mat frame;
    int nFrame = 0;
    int lastDangerousFrame = 0;
    int i = 0;
    double brightness = 0;
    int flash = 0;
    bool dangerousPattern = false;
    bool videoPeligroso = false;

    while (video.read(frame)) {
        // Verificar si ha llegado al final del video
        if (frame.empty()) {
            std::cout << "Fin del video." << std::endl;
            break;
        }
        
        dangerousPattern = imageTester->testFrame(frame, brightness, flash);
       
        if (dangerousPattern) {
            if (i == 0)
            {
                lastDangerousFrame = nFrame;
            }
            else if (i == -1) {
                i = nFrame - lastDangerousFrame;
            }
            if (!videoPeligroso) {
                videoPeligroso = true;
            }
            i++;
        }
        else {
            if (i >= 5)
            {
                std::cout << "El video es peligroso entre los frames " << lastDangerousFrame << " y " << nFrame << std::endl;   
            }
            if (i == -1) {
                i = 0;
            }
			else if (i != 0) {
				i = -1;
			}
        }
        nFrame++;
    }
    if (i > 5)  
    {
        std::cout << "El video es peligroso entre los frames " << lastDangerousFrame << " y " << nFrame << std::endl;   
    }
    if(videoPeligroso)
    {
		std::cout << "El video es peligroso." << std::endl;
	}
	else
	{
		std::cout << "El video no es peligroso." << std::endl;
	}
    std::cout << "Fin del video." << std::endl; 
}