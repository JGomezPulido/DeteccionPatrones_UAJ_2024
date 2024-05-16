#include "Analyzer.h"


Analyzer::Analyzer(): maxBrightness(2.5), dangerousPattern(false)
{
}

Analyzer::~Analyzer()
{
}


bool Analyzer::dangerousBrightness(cv::Mat frame)
{
	//adaptamos la imagen para que sea binaria
	cv::threshold(frame, frame, 25, 255, cv::THRESH_BINARY);

	//calcula el brillo medio de la imagen
	std::cout << "Average brightness: " << cv::mean(frame)[0] << std::endl;
	return cv::mean(frame)[0] > maxBrightness;
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
