#include <string>
#include <vector>
#pragma once

class Options
{
public:
	Options();
	~Options();
	int get_width();
	int get_height();
	bool get_debug();
private:
	unsigned int width;
	unsigned int height;
	bool debug=false;
	std::vector<std::string> parse_str(std::string line);
};

