#include "Configuration.h"
#include <fstream>
#include <iostream>
Configuration::Configuration(const std::string& file): _fileName(file)
{
}

void Configuration::readConfiguration(ConfigInfo& config)
{
	std::ifstream entry("Configuration/" + _fileName);

	if (!entry.is_open())
	{
		std::cerr << "Error: No se ha podido abrir el archivo: " << _fileName << "\n";
	}
	else
	{
		// Dato de configuracion actual
		std::string data;
		entry >> data;
		//Identificador de objeto
		while (data != "--")
		{
			if (data == "MaxBrightness")
			{
				entry >> data;
				config.maxBr = std::stod(data);
			}
			else if (data == "DiffBrightness")
			{
				entry >> data;
				config.diffBr = std::stod(data);
			}
			else if (data == "MaxLinesFlash")
			{
				entry >> data;
				config.maxLinesFlash = std::stod(data);
			}
			else if (data == "Thresholds")
			{
				entry >> data;
				config.threshold = std::stoi(data);
			}
			else if (data == "MinLenght")
			{
				entry >> data;
				config.minLenght = std::stod(data);
			}
			else if (data == "MaxGap")
			{
				entry >> data;
				config.maxGap = std::stod(data);
			}
			//Leemos identificador siguiente
			entry >> data;
		}
		entry.close();
	}
}
