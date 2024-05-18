#pragma once
#include <string>
class Menu
{
private:
	std::string pathFile_;
	int optionType;
public:
	Menu() { pathFile_ = ""; optionType = -1; }
	~Menu() {};
	void runMenu(int& inputOption, std::string& path);

private:
	int isImageOrVideo();
	std::string getFilePath();
};

