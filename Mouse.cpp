#include "Mouse.h"

void glswitch(int*wind, SDL_Point mpos)
{
	if (PInRect(mpos, {0,0}, {0,0}))//knopk na4 igri
	{
		*wind = 0;
		return;
	}
	if (PInRect(mpos, {0,0}, { 0,0 }))//knopk exit
	{
		*wind = -1;
		return;
	}
}

int battleswitch(SDL_Point mpos)
{
	if (PInRect(mpos, { 225,745 }, { 330,850 }))//ydar
	{
		return 0;
	}
	else if (PInRect(mpos, { 350,745 }, { 455,850 }))//sp dmg
	{
		return 1;
	}
	else if (PInRect(mpos, { 475,745 }, { 580,850 }))//armor up
	{
		return 2;
	}
	else if (PInRect(mpos, { 600,850 }, { 705,850 }))//leave try
	{
		return 3;
	}
	else
	{
		return -1;//do nothing
	}
}