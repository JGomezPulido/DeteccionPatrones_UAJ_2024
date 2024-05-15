#include "PatternDetector.h"
#include "ImgPreProcessor.h"
using namespace cv;

PatternDetector::PatternDetector()
{
	lines = std::vector<Vec2f>();
	linesP = std::vector<Vec4i>();
}

PatternDetector::~PatternDetector()
{
}

void PatternDetector::detectLines(Mat destino)
{
	//El metodo HoughLinesP detecta lineas en una imagen y las guarda en un vector de Vec4i
	// Vec4i es un vector de 4 enteros, que representan las coordenadas de dos puntos en la imagen
	// Probablemente haya que meter parametros en este metodo para detectar las lineas que queremos

	// Esta funcion detecta lineas en una imagen binaria usando el algoritmo estandar de Hough

	// Esta funcion detecta lineas en una imagen binaria usando el algoritmo probabilistico de Hough
	HoughLinesP(destino, linesP, 1, CV_PI / 180, 50, 50, 10); // runs the actual detection

	// El HoughLinesP devuelve SEGMENTOS de linea, no una linea completa, segun los parametros que se le pasen (Como la longitud minima de linea)
		// Draw the lines
	Mat tmp;
	cvtColor(destino, tmp, COLOR_GRAY2RGB);
	for (size_t i = 0; i < linesP.size(); i++)
	{
		Vec4i l = linesP[i];
		line(tmp, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 1, LINE_AA);
	}
	// Show results
	//imshow("Source", src);
	imshow("Detected Lines (in red) - Probabilistic Line Transform", tmp);
	// Wait and Exit

}

void PatternDetector::detectPattern()
{
	// Con el vector de lineas detectadas, se puede intentar detectar un patron de lineas en la imagen

}
