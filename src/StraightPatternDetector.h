#pragma once
#include "PatternDetector.h"
#include <unordered_map>


struct LineInfo {
	cv::Point2i p1, p2;
	double slope;
	double intercept;
	bool isVertical;
	bool isInGroup;
	LineInfo(const cv::Vec4i& line);
};

typedef std::unordered_multimap<int, LineInfo> PatternMap;

class StraightPatternDetector: public PatternDetector
{
public:
	StraightPatternDetector();
	~StraightPatternDetector() {};

	void detectLines(const cv::Mat& destino) override;
	bool detectPattern() override;
	inline const PatternMap& getPossiblePatterns() const { return groups; }
private:
	void drawDetectedLines(const cv::Mat& img);
protected:
	std::vector<LineInfo> lines;
	std::vector<cv::Vec4i> linesP;
	PatternMap groups;
	int maxGroup;
};

