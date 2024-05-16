#pragma once
#include "PatternDetector.h"
class StraightPatternDetector: public PatternDetector
{
public:
	StraightPatternDetector();
	~StraightPatternDetector() {};

	void detectLines(Mat destino)override;
	void detectPattern()override;
private:
};

