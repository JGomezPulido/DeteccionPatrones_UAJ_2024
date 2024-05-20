#include "StraightPatternDetector.h"
#include "ImgPreProcessor.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include "checkML.h"
StraightPatternDetector::StraightPatternDetector(int th, double minL, double maxG)
	: threshold(th), minLenght(minL), maxGap(maxG), lines(), linesP(), groups(), maxGroup(0)
{}

void StraightPatternDetector::detectLines(const cv::Mat& destino)
{
	// El metodo HoughLinesP detecta lineas en una imagen y las guarda en un vector de Vec4i
	// Vec4i es un vector de 4 enteros, que representan las coordenadas de dos puntos en la imagen
	cv::HoughLinesP(destino, linesP, 1, CV_PI / 180, threshold, minLenght, maxGap); 
	lines.clear();
	//Calculate information for each line detected
	for (const Vec4i& line : linesP) {
		lines.push_back(LineInfo(line));
	}

	std::cout << "Number of lines: " << lines.size() << std::endl;
	// Agrupamos las lineas por lineas paralelas
	groups.clear();
	maxGroup = 0;
	for (int i = 0; i < lines.size(); i++) {
		LineInfo line = lines[i];
		if (line.isInGroup) continue;
		for(int j = i+1; j < lines.size(); j++){
			if ((line.isVertical && lines[j].isVertical) || std::abs(line.slope - lines[j].slope) < 0.1 ) {
				line.isInGroup = true;
				lines[j].isInGroup = true;
				groups.insert({ maxGroup, lines[j] });
			}
		}
		if(line.isInGroup) maxGroup++;
	}

	// Por ultimo, dibujamos las lineas detectadas
	drawDetectedLines(destino);

}

bool StraightPatternDetector::detectPattern()
{
	// Se filtran los grupos que tengan menos de 10 lineas
	int validGroups = 0;
	for (int group = 0; group < maxGroup; group++) {
		if (groups.count(group) < 10) {
			auto gIt = groups.equal_range(group);
			groups.erase(gIt.first, gIt.second);
		}
		else {
			validGroups++;
		}
	}
	std::cout << "Line groups: " << validGroups << std::endl;
	// Con el vector de lineas detectadas, se puede intentar detectar un patron de lineas en la imagen
	return groups.size() > 0;
}

void StraightPatternDetector::drawDetectedLines(const cv::Mat& img)
{
	Mat tmp;
	cv::cvtColor(img, tmp, cv::COLOR_GRAY2RGB);
	for (const LineInfo& mLine : lines)
	{
		cv::line(tmp, mLine.p1, mLine.p2, Scalar(0, 0, 255), 1, LINE_AA);
	}
	cv::imshow("Detected Lines (in red) - Probabilistic Line Transform", tmp);
}

LineInfo::LineInfo(const cv::Vec4i& line)
{
	p1 = Point2i(line[0], line[1]);
	p2 = Point2i(line[2], line[3]);
	isInGroup = false;
	if (p1.x == p2.x) {
		slope = INFINITY;
		intercept = p1.x;
		isVertical = true;
	}
	else {
		slope = double(p2.y - p1.y) / double(p2.x - p1.x);
		intercept = p1.y - slope * p1.x;
		isVertical = false;
	}
}
