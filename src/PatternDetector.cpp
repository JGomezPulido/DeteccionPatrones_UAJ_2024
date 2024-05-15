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

void PatternDetector::detectLines(Mat destino, Mat cdst, Mat cdstP)
{
	//El metodo HoughLinesP detecta lineas en una imagen y las guarda en un vector de Vec4i
	// Vec4i es un vector de 4 enteros, que representan las coordenadas de dos puntos en la imagen
	// Probablemente haya que meter parametros en este metodo para detectar las lineas que queremos

	// Esta funcion detecta lineas en una imagen binaria usando el algoritmo estandar de Hough

	// Estos metodos funcionan en el main, pero no en esta clase. Incluso con el mismo material destino
	HoughLines(destino, lines, 1, CV_PI / 180, 100, 0, 0); // runs the actual detection

	// Draw the lines
	for (size_t i = 0; i < lines.size(); i++)
	{
		float rho = lines[i][0], theta = lines[i][1];
		Point pt1, pt2;
		double a = cos(theta), b = sin(theta);
		double x0 = a * rho, y0 = b * rho;
		pt1.x = cvRound(x0 + 1000 * (-b));
		pt1.y = cvRound(y0 + 1000 * (a));
		pt2.x = cvRound(x0 - 1000 * (-b));
		pt2.y = cvRound(y0 - 1000 * (a));
		line(cdst, pt1, pt2, Scalar(0, 0, 255), 3, LINE_AA);
	}

	// Esta funcion detecta lineas en una imagen binaria usando el algoritmo probabilistico de Hough
	HoughLinesP(destino, linesP, 1, CV_PI / 180, 50, 50, 10); // runs the actual detection

	// El HoughLinesP devuelve SEGMENTOS de linea, no una linea completa, segun los parametros que se le pasen (Como la longitud minima de linea)
		// Draw the lines
	for (size_t i = 0; i < linesP.size(); i++)
	{
		Vec4i l = linesP[i];
		line(cdstP, Point(l[0], l[1]), Point(l[2], l[3]), Scalar(0, 0, 255), 1, LINE_AA);
	}
	// Show results
	//imshow("Source", src);
	//imshow("Detected Lines (in red) - Standard Hough Line Transform", cdst);
	//imshow("Detected Lines (in red) - Probabilistic Line Transform", cdstP);
	// Wait and Exit
	//waitKey();

}

void PatternDetector::detectPattern()
{
	// Con el vector de lineas detectadas, se puede intentar detectar un patron de lineas en la imagen

}
