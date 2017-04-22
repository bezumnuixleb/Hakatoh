#include "Add.h"
#include <time.h>
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

int getrand(int a, int b)
{
	return rand() % (b - a + 1) + a;
}

bool PInRect(SDL_Point C, SDL_Point A1, SDL_Point A2)
{
	if (C.x <= A2.x&&C.y <= A2.y&&C.x >= A1.x&&C.y >= A1.y)
	{
		return 1;
	}
	else return 0;
}

SDL_Texture *addtext(SDL_Renderer* rend, SDL_Surface* temp)
{
	SDL_Texture *text = SDL_CreateTextureFromSurface(rend, temp);
	return text;
}