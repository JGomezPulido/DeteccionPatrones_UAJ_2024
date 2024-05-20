#include <iostream>
#include "ImageTester.h"
#include "opencv2/highgui.hpp"
#include "Menu.h"
#include "VideoTester.h"
#include "checkML.h"


using namespace std;

int main(int argc, char** argv)
{
#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif
	// Pregunta input
	int option = 0;
	string path = "";
	Menu* menu = new Menu();
	menu->runMenu(option, path);

	// Salir
	if (!option) {
		delete menu;
		return 0;
	}

	// Se usa 0.4, 0.2, 5 como valores por defecto para analizar la imagen o video, pero se pueden cambiar segun se desee
	// 0.4 es el brillo maximo permitido
	// 0.2 es la diferencia de brillo permitida entre frames
	// 5 es la diferencia de lineas permitida entre frames

	// Image tester
	if (option == 1) {
		ImageTester* iTester = new ImageTester(path);
		if (!iTester->init(0.4, 0.2, 10)) {
			std::cerr << "ERROR: No se ha podido inicializar image tester";
			delete iTester;
			iTester = nullptr;
			delete menu;
			return 1;
		}
		iTester->testImage();
		delete iTester;
	}
	// Video tester
	else {
		VideoTester* vTester = new VideoTester(path);
		if (!vTester->init(0.4, 0.2, 10)) {
			std::cerr << "ERROR: No se ha podido inicializar video tester";
			delete vTester;
			vTester = nullptr;
			delete menu;
			return 1;
		}
		vTester->testVideo();
		delete vTester;
	}


	// Delete menu
	delete menu;

	cv::waitKey();
	return 0;
}