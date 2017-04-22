#pragma once
#include <iostream>
#include "SDL.h"
#include "Boi.h"

struct Player;
struct Circle
{
	int pos;
	
};

bool startispressed(SDL_Point mpos,bool shop);
void sobitie(int circlepos, Player *igrok, int *wind, int *tovar1, int *tovar2,bool *fightstart);