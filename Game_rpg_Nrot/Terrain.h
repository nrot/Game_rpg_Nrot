#pragma once
#include "Object.h"
#include "Structs.h"

class Terrain: Object
{
public:
	Terrain(std::string start_name, Coord start_coord);
	~Terrain();
private:
	bool passable = false;
	Type type = WALL;
};

