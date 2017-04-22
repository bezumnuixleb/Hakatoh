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
	if (PInRect(mpos, { 0,0 }, { 0,0 }))//ydar
	{
		return 0;
	}
	else if (PInRect(mpos, { 0,0 }, { 0,0 }))//sp dmg
	{
		return 1;
	}
	else if (PInRect(mpos, { 0,0 }, { 0,0 }))//armor up
	{
		return 2;
	}
	else if (PInRect(mpos, { 0,0 }, { 0,0 }))//leave try
	{
		return 3;
	}
	else
	{
		return -1;//do nothing
	}
}