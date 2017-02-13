#include "Object.h"
#include <string>
#include <SDL.h>
#include "Structs.h"

Object::Object(std::string start_name, Coord start_coord)
{
	this->name = start_name;
	this->obj_coord = start_coord;
}


Object::~Object()
{
}

void Object::draw(SDL_Surface screen)
{
}
