#pragma once
#include <string>

struct ConfigInfo {
	double maxBr;
	double diffBr;
	double maxLinesFlash;
	int threshold;
	double minLenght;
	double maxGap;
};

class Configuration
{
public:
	Configuration(const std::string& file);
	~Configuration() {};

	void readConfiguration(ConfigInfo& config);
private:
	std::string _fileName;
};

