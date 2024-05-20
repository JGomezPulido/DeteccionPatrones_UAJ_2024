#include "Analyzer.h"
#include "checkML.h"

Analyzer::Analyzer(double maxBr, double brDiff, double maxLF)
{
	// Tras varios experimentos, se ha determinado que un brillo mayor a 0.4 es peligroso
	maxBrightness = maxBr;
	brightnessDiff = brDiff;
	maxLinesFlash = maxLF;
	dangerousPattern = false;
}

Analyzer::~Analyzer()
{
}

// Si el brillo promedio de la imagen es demasiado alto, se considera peligroso
bool Analyzer::analyzeBrightness(const cv::Mat& image)
{
	double averageBrightness = cv::mean(image)[0];
	averageBrightness = averageBrightness / 255.0; // Normalización opcional	

	std::cout << "Average brightness: " << averageBrightness << "\n" << std::endl;

	return averageBrightness > maxBrightness;
}

// Se considera que si el brillo supera el maximo o la diferencia de brillo entre frames es mayor a 20, se considera peligroso
bool Analyzer::analyzeBrightness(double& brightness,const cv::Mat& frame2)
{
	double averageBrightness = cv::mean(frame2)[0];
	averageBrightness = averageBrightness / 255.0; // Normalización opcional	

	double diff = std::abs(brightness - averageBrightness);
	brightness = averageBrightness;
	std::cout << "Average brightness: " << averageBrightness << "\n" << std::endl;
	return (averageBrightness > maxBrightness || diff > brightnessDiff);
}

// Si la diferencia de grupos de lineas en un patron en cada frame es mayor a 5, se considera un parpadeo peligroso
bool Analyzer::analyzeFlash(int& nLineasF1, int nLineasF2)
{
	int diffNLineas = std::abs(nLineasF1 - nLineasF2);
	nLineasF1 = nLineasF2;
	return diffNLineas > maxLinesFlash;
}

bool Analyzer::analyze(const cv::Mat& ogImg, const PatternMap& pattern, double& brightness, int& flash)
{
	// Si el parpadeo entre frame y frame es muy grande (Teniendo en cuenta la diferencia de brillo y la diferencia entre patrones)
	if (analyzeBrightness(brightness, ogImg) && analyzeFlash(flash,pattern.size()))
	{
		return true;
	}

	return false;
}


bool Analyzer::analyze(const cv::Mat& ogImg)
{
	return analyzeBrightness(ogImg);
}
