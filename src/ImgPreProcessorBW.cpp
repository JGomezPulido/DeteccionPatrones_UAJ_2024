#include "ImgPreProcessorBW.h"
#include "opencv2/imgproc.hpp"
#include <opencv2/photo.hpp>
#include <iostream>
#include <opencv2/highgui.hpp>
#include "Analyzer.h"

cv::Mat ImgPreProcessorBW::processImage(Mat image)
{

	// Cambia la resolucion
	source = image;
	cv::resize(source, source, Size(910, 512));

	if (image.channels() != 1) {
		// If the image has only one channel, it is grayscale
		cvtColor(source, source, COLOR_BGR2GRAY);

	}


	cvtColor(source, destino, COLOR_GRAY2BGR);


	// Reduce ruido desenfocando
	lessNoise(destino);

	// Calculate median of the grayscale image
	Scalar medianValue = mean(destNoNoise);

	double median = medianValue[0]; // Median value of the image

	// Define sigma (scaling factor)
	double sigma = 0.33;

	// Calculate Canny thresholds
	int cannyTh1 = max(0.0, (1.0 - sigma) * median);
	int cannyTh2 = min(255.0, (1.0 + sigma) * median);

	// Apply Canny edge detection
	Mat edges;
	Canny(destNoNoise, edges, cannyTh1, cannyTh2);
	//imshow("Detected Lines (in red) - Probabilistic Line Transform", edges);
	//waitKey();

	return edges;
}

void ImgPreProcessorBW::lessNoise(Mat source)
{
	medianBlur(source, destNoNoise, 7);
	//GaussianBlur(source, destNoNoise, Size(1, 1), 0.33, 0.33);
}