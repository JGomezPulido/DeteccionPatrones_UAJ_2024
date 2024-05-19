#include "Menu.h"
#include <iostream>


// METODOS PUBLICOS
void Menu::runMenu(int& inputOption, std::string& path) {
	inputOption = isImageOrVideo();
	if(inputOption) path = getFilePath();
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
