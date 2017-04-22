#include "Mouse.h"

void glswitch(int*wind, SDL_Point mpos)
{
	if (PInRect(mpos, {0,0}, {0,0}))//knopk na4 igri
	{
		wind = 0;
		return;
	}
	if (PInRect(mpos, {0,0}, { 0,0 }))//knopk exit
	{
		wind = -1;
		return;
	}
}