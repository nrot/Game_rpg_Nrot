#include "Terrain.h"
#include <vector>
#pragma once

class Field
{
public:
	Field();
	~Field();
	Object get_from_coord();
private:
	std::vector<Terrain> terrains;
};

