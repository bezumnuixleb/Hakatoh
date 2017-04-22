#include <iostream>
#include "SDL.h"
#include "Add.h"

bool startispressed(SDL_Point mpos,bool shoot)
{
	if (PInRect(mpos, {353,371 }, { 553,571 })&&shoot==true)//knopka najata
	{
		return true;
	}
	else
	{
		return false;
	}
}