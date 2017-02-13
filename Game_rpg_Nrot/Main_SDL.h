#include "Options.h"
#include <SDL.h>
#pragma once

class Main_SDL
{
public:
	Main_SDL(Options options);
	~Main_SDL();
	unsigned long int get_errors();
	SDL_Surface *screen;
	SDL_Event *event;
	SDL_Window *window;
	SDL_Renderer *renderer;
private:
	unsigned long int errors = 0;
};

