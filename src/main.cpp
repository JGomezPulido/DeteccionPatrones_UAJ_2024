#include <iostream>
#include "ImageTester.h"
#include "opencv2/highgui.hpp"

#include "Menu.h"
#include "VideoTester.h"
using namespace std;

// En este main, escribimos la imagen que queremos probar (metalpipe.png) y el procesador lo lee bien pero al intentar detectar lineas, salta una excepcion

int main(int argc, char** argv)
{
	// Pregunta input
	int option;
	string path = "";
	Menu* menu = new Menu();


	menu->runMenu(option, path);

	// Salir
	if (!option) return 0;

	// Image tester
	if (option == 1) {
		ImageTester* iTester = new ImageTester(path);
		if (!iTester->init()) {
			std::cerr << "ERROR: No se ha podido inicializar image tester";
			delete iTester;
			iTester = nullptr;
			return 1;
		}
		iTester->testImage();
		delete iTester;
	}
	// Video tester
	else {
		VideoTester* vTester = new VideoTester(path);
		if (!vTester->init()) {
			std::cerr << "ERROR: No se ha podido inicializar video tester";
			delete vTester;
			vTester = nullptr;
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