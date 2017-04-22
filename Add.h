#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

int getrand(int a, int b);
bool PInRect(SDL_Point C, SDL_Point A1, SDL_Point A2);
SDL_Texture *addtext(SDL_Renderer* rend, SDL_Surface* temp);
void rendWord(SDL_Renderer * rend, SDL_Rect Pos, int a,TTF_Font *font);