#include <iostream>
#include "ImageTester.h"
#include "opencv2/highgui.hpp"

#include "Menu.h"
#include "VideoTester.h"
using namespace std;

// En este main, escribimos la imagen que queremos probar (metalpipe.png) y el procesador lo lee bien pero al intentar detectar lineas, salta una excepcion

int main(int argc, char** argv)
{
	// Pregunta input
	bool isImage;
	string path = "";
	Menu* menu = new Menu();
	menu->runMenu(isImage, path);


	if (isImage) {
		// Image tester
		ImageTester* iTester = new ImageTester(path);
		if (!iTester->init()) {
			std::cerr << "ERROR: No se ha podido inicializar image tester";
			delete iTester;
			iTester = nullptr;
			return 1;
		}
		iTester->testImage();
		delete iTester;

	}
	else {

		// Video tester
		VideoTester* vTester = new VideoTester(path);
		if (!vTester->init()) {

			std::cerr << "ERROR: No se ha podido inicializar video tester";
			delete vTester;
			vTester = nullptr;
			return 1;
		}
		vTester->testVideo();
		delete vTester;
	}

	// Delete
	delete menu;

	cv::waitKey();
	return 0;
}

//int main(int argc, char** argv)
//{
//	// Declare the output variables
//	Mat dst, cdst, cdstP;
//	const char* default_file = "sudoku.png";
//	const char* filename = argc >= 2 ? argv[1] : default_file;
//	// Loads an image
//	Mat src = imread(samples::findFile(filename), IMREAD_GRAYSCALE);
//	// Check if image is loaded fine
//	if (src.empty()) {
//		printf(" Error opening image\n");
//		printf(" Program Arguments: [image_name -- default %s] \n", default_file);
//		return -1;
//	}
//	// Edge detection
//	Canny(src, dst, 50, 200, 3);
//	// Copy edges to the images that will display the results in BGR
//	cvtColor(dst, cdst, COLOR_GRAY2BGR);
//	cdstP = cdst.clone();
//
//	// Standard Hough Line Transform
//	vector<Vec2f> lines; // will hold the results of the detection
//	HoughLines(dst, lines, 1, CV_PI / 180, 100, 0, 0); // runs the actual detection
//	// Draw the lines
//	for (size_t i = 0; i < lines.size(); i++)
//	{
//		float rho = lines[i][0], theta = lines[i][1];
//		Point pt1, pt2;
//		double a = cos(theta), b = sin(theta);
//		double x0 = a * rho, y0 = b * rho;
//		pt1.x = cvRound(x0 + 1000 * (-b));
//		pt1.y = cvRound(y0 + 1000 * (a));
//		pt2.x = cvRound(x0 - 1000 * (-b));
//		pt2.y = cvRound(y0 - 1000 * (a));
//		line(cdst, pt1, pt2, Scalar(0, 0, 255), 3, LINE_AA);
//	}
//	// Probabilistic Line Transform
//	vector<Vec4i> linesP; // will hold the results of the detection
//	HoughLinesP(dst, linesP, 1, CV_PI / 180, 100, 20, 10); // runs the actual detection
//	// Draw the lines
//	for (size_t i = 0; i < linesP.size(); i++)
//	{
//		Vec4i l = linesP[i];
//		line(cdstP, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 1, LINE_AA);
//	}
//	// Show results
//	imshow("Source", src);
//	imshow("Detected Lines (in red) - Standard Hough Line Transform", cdst);
//	imshow("Detected Lines (in red) - Probabilistic Line Transform", cdstP);
//	// Wait and Exit
//	waitKey();
//	return 0;
//}