#include "Menu.h"
#include <iostream>

#include "ImageTester.h"
#include "VideoTester.h"
#include "Configuration.h"
#include "checkML.h"

// METODOS PUBLICOS
bool Menu::runMenu(int& inputOption, std::string& path) {
	inputOption = isImageOrVideo();
	if(inputOption) path = getFilePath();

	// Salir
	if (!inputOption) {
		std::cerr << "No se ha registrado ningun input \n";
		return true;
	}

	// Se usa 0.4, 0.2, 5 como valores por defecto para analizar la imagen o video, pero se pueden cambiar segun se desee
	// 0.4 es el brillo maximo permitido
	// 0.2 es la diferencia de brillo permitida entre frames
	// 5 es la diferencia de lineas permitida entre frames

	Configuration* config = new Configuration("data.txt");
	ConfigInfo info;
	config->readConfiguration(info);

	// Image tester
	if (inputOption == 1) {
		ImageTester* iTester = new ImageTester(path);
		if (!iTester->init(info.maxBr, info.diffBr, info.maxLinesFlash, info.threshold, info.minLenght, info.maxGap)) {
			std::cerr << "ERROR: No se ha podido inicializar image tester";
			delete iTester;
			iTester = nullptr;
			return false;
		}
		iTester->testImage();
		delete iTester;
	}
	// Video tester
	else {
		VideoTester* vTester = new VideoTester(path);
		if (!vTester->init(info.maxBr, info.diffBr, info.maxLinesFlash, info.threshold, info.minLenght, info.maxGap)) {
			std::cerr << "ERROR: No se ha podido inicializar video tester";
			delete vTester;
			vTester = nullptr;
			return false;
		}
		vTester->testVideo();
		delete vTester;
	}

	return true;
}


// METODOS PRIVADOS

int Menu::isImageOrVideo()
{
	char num = ' ';
	// Recoge nombre de archivo
	do {
		std::cout << "Desea analizar una imagen(1) o un video(2)? Escribe 1 o 2 para testear o \"Q\" para salir" << std::endl;
		std::cin >> num;

	} while (num != '1' && num != '2' && num != 'Q');

	if (num == 'Q') optionType = 0; // Salir
	else if (num == '1') optionType = 1; // Imagen
	else optionType = 2; // Video

	return optionType;
}

std::string Menu::getFilePath()
{
	std::string fileName = "";

	// Recoge nombre de archivo
	do {
		// Aunque se pueda probar con resoluciones superiores, se recomienda 512px x 910px dado que si se supera,
		// se recorta la imagen/video a 512 x 910 para que el procesamiento funcione
		std::cout << "\nIngrese el nombre del archivo que desea probar [Resolucion recomendada: 512px x 910px o superior]: " << std::endl;
		std::cin >> fileName;

	} while (fileName == "");

	pathFile_ = "Assets/" + fileName;

	return pathFile_;
}
