#include "ImgPreProcessorBW.h"
#include "opencv2/imgproc.hpp"
#include <opencv2/photo.hpp>
#include <iostream>
#include <opencv2/highgui.hpp>

cv::Mat ImgPreProcessorBW::processImage()
{
	// Recibir un archivo de imagen y prepararla para detectar lineas en ella
	// Devuelve -1 o null si no se ha encontrado la imagen, y el material procesado si se ha encontrado y procesado correctamente
	// Se puede cambiar este metodo como se vea conveniente

	// Loads an image
	// Hacer un try catch para manejar excepciones si no encuentra la imagen
	source = imread(samples::findFile(imagePath), IMREAD_GRAYSCALE);
	// Check if image is loaded fine


	if (source.empty()) {
		// Comunicar que no se ha encontrado la imagen
		std::cerr << "Error: Failed to load or process image." << std::endl;
		return cv::Mat(); // Devuelve Mat vacia
	}

	// Cambia la resolucion
	//cv::resize(source, source, Size(910, 512));

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