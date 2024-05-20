#pragma once
#include "PatternDetector.h"
#include <unordered_map>

// Informacion de la linea 
struct LineInfo {
	cv::Point2i p1, p2;
	double slope;
	double intercept;
	bool isVertical;
	bool isInGroup;
	LineInfo(const cv::Vec4i& line);
};

// Patron de lineas
typedef std::unordered_multimap<int, LineInfo> PatternMap;

class StraightPatternDetector: public PatternDetector
{
public:
	StraightPatternDetector(int th, double minL, double maxG);
	~StraightPatternDetector() {};

	// Detecta las lineas de la imagen
	void detectLines(const cv::Mat& destino) override;
	// Detecta el patron segun las lineas detectadas
	bool detectPattern() override;
	// Devuelve los patrones
	inline const PatternMap& getPossiblePatterns() const { return groups; }
private:
	// Dibuja las lineas detectadas
	void drawDetectedLines(const cv::Mat& img);
protected:
	// Vector de lineas paralelas
	std::vector<LineInfo> lines;
	// Vector de lineas detectadas
	std::vector<cv::Vec4i> linesP;
	// Mapa de patrones de lineas paralelas
	PatternMap groups;
	// Identificador de grupo de lineas paralelas
	int maxGroup;
	// Limite de linea que termina el ancho de linea que se detecta
	int threshold;
	// Minimo de longitud de la linea a detectar
	double minLenght;
	// Maximo de espacio entre puntos de la linea a detectar
	double maxGap;
};

