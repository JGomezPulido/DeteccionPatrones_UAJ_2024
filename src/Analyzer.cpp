#include "Analyzer.h"


Analyzer::Analyzer(): maxBrightness(0.4), dangerousPattern(false)
{
}

Analyzer::~Analyzer()
{
}


bool Analyzer::dangerousBrightness(cv::Mat frame)
{

	double averageBrightness = cv::mean(frame)[0];		
	averageBrightness = averageBrightness / 255.0; // Normalización opcional	

	std::cout << "Average brightness: " << averageBrightness << std::endl;	

	return averageBrightness > maxBrightness;	
}


void Analyzer::analyzeImage(cv::Mat image)
{
	//comprueba si la imagen es demasiado brillante
	if (dangerousBrightness(image))
	{
		dangerousPattern = true;
		std::cout << "Dangerous pattern detected" << std::endl;
	}
	else
	{
		dangerousPattern = false;
		std::cout << "No dangerous pattern detected" << std::endl;
	}
}
