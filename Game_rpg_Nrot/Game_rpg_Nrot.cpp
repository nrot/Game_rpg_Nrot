// Game_rpg_Nrot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Options.h"
#include <SDL.h>
#include <iostream>


int main(int argc, char ** argv)
{
	Options options = Options();
	
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		std::cout << "Can`t init screen" << std::endl;
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		return 2;
	}

	SDL_Surface *screen;
	SDL_Event event;
	SDL_Window *window = SDL_CreateWindow("Nrot RPG Game",
		SDL_WINDOWPOS_UNDEFINED, 
		SDL_WINDOWPOS_UNDEFINED, 
		options.get_width(), 
		options.get_height(),
		SDL_WINDOW_SHOWN| SDL_WINDOW_BORDERLESS);

	if (window == NULL)
	{
		std::cout << "Can`t create window: " << SDL_GetError() << std::endl;
		return 1;
	}


	SDL_Delay(100);
	SDL_DestroyWindow(window);
	SDL_Quit();

	std::system("pause");
	return 0;
}
