#include <iostream>
#include "opencv2/highgui.hpp"
#include "Menu.h"
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
	if (menu->runMenu(option, path))
	{
		// Delete menu
		delete menu;
		cv::waitKey();
		return 0;
	}
	else
	{
		// Delete menu
		delete menu;
		std::cerr << "ERROR: No se ha podido inicializar el menu";
		return -1;
	}
}