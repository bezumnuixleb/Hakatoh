#include "Add.h"
#include <time.h>
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

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

void rendWord(SDL_Renderer * rend, SDL_Rect Pos, int a,TTF_Font *font)
{
	char buf[255];
	_itoa_s(a, buf, 255, 10);
	SDL_Color TextColor = { 255,255,255 };
	SDL_Surface* temp = TTF_RenderText_Solid(font, buf, TextColor);
	SDL_Texture* textrend = SDL_CreateTextureFromSurface(rend, temp);
	SDL_RenderCopy(rend, textrend, NULL, &Pos);
}
void rendStr(SDL_Renderer * rend, SDL_Rect Pos, char buf[255], TTF_Font *font,SDL_Color TextColor)
{
	SDL_Surface* temp = TTF_RenderText_Solid(font, buf, TextColor);
	SDL_Texture* textrend = SDL_CreateTextureFromSurface(rend, temp);
	SDL_RenderCopy(rend, textrend, NULL, &Pos);
}