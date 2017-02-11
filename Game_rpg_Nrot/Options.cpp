#include "Options.h"
#include <string>
#include <fstream>
#include <iostream>

Options::Options()
{
	std::string path_conf = "configure.conf";
	std::ifstream conf_file(path_conf);
	if (!conf_file.is_open())
		std::cout << "Can`t open file" << path_conf << std::endl;
	std::string line;
	std::vector<std::string> tmp;

	while (!conf_file.eof())
	{
		conf_file >> line;
		if (line[0] == '[')
			continue;
		tmp = this->parse_str(line);
		if (tmp[0] == "Width")
			this->width = std::stoi(tmp[1]);
		else if (tmp[0] == "Height")
			this->height = std::stoi(tmp[1]);
		else if (tmp[0] == "Debug") {
			this->debug = std::stoi(tmp[1]) == 0 ? false : true;
		}
		
	}
}


Options::~Options()
{
}

int Options::get_width()
{
	return 0;
}

int Options::get_height()
{
	return 0;
}

bool Options::get_debug()
{
	return false;
}

std::vector<std::string> Options::parse_str(std::string in_line)
{
	int i;
	std::vector<std::string> res;
	res.insert(res.end(), std::string(""));
	for (i = 0; i < in_line.length() && in_line[i] != '='; i++)
		res[0] += in_line[i];
	res.insert(res.end(), in_line.substr(1+i, in_line.length()));
	return res;
}
