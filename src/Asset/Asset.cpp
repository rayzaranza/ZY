#include "Asset.h"
#include <fstream>
#include <iostream>
#include <sstream>

std::string ZY::Asset::getFileContent(const std::string& path)
{
	std::ifstream file{ path };
	if (!file.is_open())
	{
		std::cerr << "Error opening file " << path << std::endl;
		throw "Error opening file";
	}
	std::ostringstream content;
	content << file.rdbuf();
	return content.str();
}
