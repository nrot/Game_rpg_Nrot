// Game_rpg_Nrot.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Options.h"
#include "Main_SDL.h"
#include "Main_Game_Loop.h"
#include <SDL.h>
#include <iostream>


int main(int argc, char ** argv)
{
	Options options = Options();
	
	Main_SDL mainSDL = Main_SDL(options);

	if (mainSDL.get_errors() != 0)
	{
		mainSDL.~Main_SDL();
		return mainSDL.get_errors();
	}
	SDL_Delay(1000);

	Main_Game_Loop game_loop = Main_Game_Loop(options);

	while (game_loop.is_running())
	{
		game_loop.update(mainSDL.event);
		game_loop.draw(mainSDL.screen);
	}

	mainSDL.~Main_SDL();

	//std::system("pause");
	return 0;
}
