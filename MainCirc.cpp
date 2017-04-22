#include <iostream>
#include "SDL.h"
#include "Add.h"
#include "Boi.h"

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

void sobitie(int circlepos, Player *igrok, int *wind,int *tovar1,int *tovar2)
{
	switch (circlepos)
	{
	case 0:return; break;
	case 1: {*wind = 3; *tovar1 = getrand(0, 4); *tovar2 = getrand(0, 4); return; } break;
	case 2: *wind = 1; return; break;
	case 3: {igrok->hp += 50; }break;
	case 4: {igrok->mane += 400; }break;
	case 5: *wind = 5; return; break;
	}
	
}

