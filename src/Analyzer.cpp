#include "Analyzer.h"


Analyzer::Analyzer()
{
	// Tras varios experimentos, se ha determinado que un brillo mayor a 0.4 es peligroso
	maxBrightness = 0.4;
	dangerousPattern = false;
}

Analyzer::~Analyzer()
{
}

// Si el brillo promedio de la imagen es demasiado alto, se considera peligroso
bool Analyzer::analyzeBrightness(cv::Mat image)
{
	double averageBrightness = cv::mean(image)[0];
	averageBrightness = averageBrightness / 255.0; // Normalización opcional	

	std::cout << "Average brightness: " << averageBrightness << std::endl;

	return averageBrightness > maxBrightness;
}

// Se considera que si el brillo supera el maximo o la diferencia de brillo entre frames es mayor a 20, se considera peligroso
bool Analyzer::analyzeBrightness(double brightness,cv::Mat frame2)
{
	double averageBrightness = cv::mean(frame2)[0];
	averageBrightness = averageBrightness / 255.0; // Normalización opcional	

	double diff = std::abs(brightness - averageBrightness);

	return (averageBrightness > maxBrightness || diff > 0.2);
}

// Si la diferencia de grupos de lineas en un patron en cada frame es mayor a 5, se considera un parpadeo peligroso
bool Analyzer::analyzeFlash(int nLineasF1, int nLineasF2)
{
	int diffNLineas = std::abs(nLineasF1 - nLineasF2);

	return diffNLineas > 5;
}

bool Analyzer::analyzeMovement(const PatternMap& patternF1, const PatternMap& patternF2)
{
	int limit = std::min(patternF1.size(), patternF2.size());

	/*for (int i = 0; i < limit; i++)
	{
		double x1, x2;
		double y1, y2;

		x1 = patternF1[i].x;
		x2 = patternF2[i].x;
		y1 = patternF1[i].y;
		y2 = patternF2[i].y;

		double distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
	}*/



	return false;
}

bool Analyzer::analyze(cv::Mat ogImg, const PatternMap& pattern, double& brightness, int& flash, PatternMap& movement)
{
	// Si el cambio de brillo es demasiado grande y el parpadeo o el movimiento del patron es demasiado grande, se considera peligroso
	if (analyzeBrightness(ogImg) && (analyzeFlash(flash,pattern.size()) || analyzeMovement(movement,pattern)))
	{
		return true;
	}

	return false;
}


bool Analyzer::analyze(cv::Mat ogImg)
{
	return analyzeBrightness(ogImg);
}
