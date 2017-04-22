#include <iostream>
#include "SDL.h"
#include "Add.h"

bool startispressed(SDL_Point mpos)
{
	if (PInRect(mpos, { 0,0 }, { 0,0 }))//knopka najata
	{
		return true;
	}
	else
	{
		return false;
	}
}