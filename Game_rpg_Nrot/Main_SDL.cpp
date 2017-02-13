#include "Main_SDL.h"
#include "Options.h"
#include <SDL.h>
#include <iostream>

Main_SDL::Main_SDL(Options options)
{
	if (SDL_Init(SDL_INIT_VIDEO))
	{
		std::cout << "Can`t init screen" << std::endl;
		std::cout << "SDL Error: " << SDL_GetError() << std::endl;
		this->errors |= 0b1;
	}

	this->window = SDL_CreateWindow("Nrot RPG Game",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		options.get_width(),
		options.get_height(),
		SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);

	if (this->window == NULL)
	{
		std::cout << "Can`t create window: " << SDL_GetError() << std::endl;
		this->errors |= 0b10;
	}

	this->renderer = SDL_CreateRenderer(this->window, -1,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == NULL)
	{
		std::cout << "Can`t create renderer: " << SDL_GetError() << std::endl;
		this->errors |= 0b100;
	}
}

Main_SDL::~Main_SDL()
{
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	SDL_Quit();
}

unsigned long int Main_SDL::get_errors()
{
	return errors;
}

