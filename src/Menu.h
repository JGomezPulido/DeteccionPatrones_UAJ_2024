#pragma once
#include <string>
class Menu
{
private:
	std::string pathFile_;
	bool isImage_;
public:
	Menu() { pathFile_ = "";}
	~Menu() {};
	void runMenu(bool& isImage, std::string& path);

private:
	bool isImageOrVideo();
	std::string getFilePath();
};

