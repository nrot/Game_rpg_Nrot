#include "Options.h"
#include <SDL.h>
#pragma once

class Main_Game_Loop
{
public:
	Main_Game_Loop(Options options);
	~Main_Game_Loop();
	bool is_running();
	void update(SDL_Event *events);
	void draw(SDL_Surface *screen);
private:
	enum STATES
	{
		RUN,
		PAUSE,
		EXIT
	};
	int game_state = PAUSE;
	unsigned short int now_level = 1;
};

