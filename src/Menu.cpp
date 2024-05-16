#include "Menu.h"
#include <iostream>


// METODOS PUBLICOS
void Menu::runMenu(bool& isImage, std::string& path) {
	isImage = isImageOrVideo();
	path = getFilePath();
}


// METODOS PRIVADOS

bool Menu::isImageOrVideo()
{
	// Recoge nombre de archivo
	do {
		std::cout << "Desea analizar un video(0) o una imagen(1)? Escribe 0 o 1\n";
		std::cin >> isImage_;

	} while (isImage_ != 0 && isImage_ != 1);

	return isImage_;
}

std::string Menu::getFilePath()
{
	std::string fileName = "";

	// Recoge nombre de archivo
	do {
		std::cout << "Ingrese el nombre del archivo que desea probar: ";
		std::cin >> fileName;

	} while (fileName == "");

	pathFile_ = "Assets/" + fileName;

	return pathFile_;
}
