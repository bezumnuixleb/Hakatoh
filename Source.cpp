#include <iostream>
#include "SDL.h"
#include "MainCirc.h"
#include "Add.h"

#define WINDOW_SIZE_W 1280
#define WINDOW_SIZE_H 1024

int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow(u8"Afasdjsadhkash", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_SIZE_W, WINDOW_SIZE_H, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_RenderSetLogicalSize(renderer, WINDOW_SIZE_W, WINDOW_SIZE_H);
	bool isRunning = true;
	int wind = 0;
	SDL_Point mousepos;
	SDL_SetRenderDrawColor(renderer, 255, 76, 0, 0);
	int circlepos = 0;
	int tmpCub = 0;
	float cubiklifetime = 0;
	bool rotate = false;
	while (isRunning)
	{
		SDL_Event ev;
		while (SDL_PollEvent(&ev) != 0)
		{
			switch (ev.type) {
			case SDL_QUIT:
				isRunning = false; return 0; break;
			case SDL_KEYDOWN:switch (ev.key.keysym.sym)
			{
			
			case SDLK_ESCAPE: {isRunning = false; return 0;} break;
			}
			
			case SDL_MOUSEMOTION:
			{
				mousepos.x = ev.motion.x; mousepos.y = ev.motion.y; 
			}break;
		}
		if (wind==0)//вращение круга 
		{
			if (startispressed(mousepos))
			{
				tmpCub=getrand(1, 6);
				circlepos += tmpCub;
				cubiklifetime = 4000;
				rotate == true;
			}
			if (rotate == false)
			{
				
			}
			//render zadnika
			//render colesa
			//render player
			//render stats,money
			//render cubika
		}
		if (wind == 1)//окно боя
		{

		}
		if (wind == 2)//главное меню
		{

		}


		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer);
	}


	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;



}
