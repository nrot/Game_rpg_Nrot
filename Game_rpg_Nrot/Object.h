#pragma once
#include "Structs.h"
#include <string>
#include <SDL.h>

class Object
{
public:
	Object(std::string start_name, Coord start_coord);
	~Object();
	void draw(SDL_Surface screen);
protected:
	Coord obj_coord;
	std::string name;
};

