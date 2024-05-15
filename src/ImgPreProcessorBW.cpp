#include "ImgPreProcessorBW.h"
#include "opencv2/imgproc.hpp"
#include <opencv2/photo.hpp>
#include <iostream>

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

	cvtColor(source, destino, COLOR_GRAY2BGR);
	
	// -----IMPORTANTE QUITAR RUIDO DE LA IMAGEN ANTES DE LA DETECCION DE BORDES----
	//fastNlMeansDenoising(destino, destNoNoise);
	
	// Edge detection
	// ---CALCULOS---------
	// Los limites (thresholds) del metodo se pueden calcular
	// median = median of the frame’s grayscale values
	// Sigma = 0.33 por alguna razon, no sabemos que es lolazo
	//cannyTh1 = Max(0,(1 ? sigma) ? median)
	//cannyTh2 = Max(255,(1 + sigma) ? median)

	Canny(destino, cdst, 50, 200, 3);
	// Copy edges to the images that will display the results in BGR
	cdstP = cdst.clone();

	return cdst;
}