#include <iostream>
#include "SDL.h"
#include "MainCirc.h"
#include "Add.h"
#include "P.h"
#include "Mouse.h"
#include "SDL_ttf.h"
#include <time.h>
#include "Boi.h"
#include "V.h"

#define WINDOW_SIZE_W 900
#define WINDOW_SIZE_H 900

int main(int argc, char** argv)
{
	TTF_Init();
	srand(time(0));
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow(u8"Afasdjsadhkash", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		WINDOW_SIZE_W, WINDOW_SIZE_H, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_RenderSetLogicalSize(renderer, WINDOW_SIZE_W, WINDOW_SIZE_H);
	TTF_Font * font = TTF_OpenFont("eng.ttf", 25);//shrift
	//text init
	bool isRunning = true;
	int wind = 0,int vragnum;
	Player igrok;
	SDL_Point mousepos;
	Vrag enemy;
	int lastTicks = SDL_GetTicks();
	SDL_SetRenderDrawColor(renderer, 255, 76, 0, 0);
	int circlepos = 0,circletexturepos=0;
	int tmpCub = 0, pressedbutonfight = -1;
	float cubiklifetime = 0,rotatelifetime=0;
	bool rotate = false;
	initPlayer(&igrok);
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
			int currentTicks = SDL_GetTicks();
			double dt = (currentTicks - lastTicks)*0.001;
			lastTicks = currentTicks;

			if (startispressed(mousepos)&&rotate==false)
			{
				tmpCub=getrand(1, 6);
				circlepos += tmpCub;
				//ogranichenie segmenta

				cubiklifetime = 4000;
				rotate == true;
			}
			if (rotate == true)
			{
				if (circletexturepos == circlepos)
				{
					rotate = false;
				}
				else
				{	
					if (rotatelifetime < 0)
					{
						circletexturepos++;
						//povorot texturi kolesa na 1 segment
						rotatelifetime = 2000;
					}
					else
					{
						rotatelifetime -= dt;
					}
				}
				//ogranichenie segmenta
				
			//
			}

			//render zadnika
			//render colesa
			//render player
			//render stats,money
			//render cubika

			SDL_RenderPresent(renderer);
			SDL_RenderClear(renderer);
		}
		if (wind == 1)//окно боя
		{
			int currentTicks = SDL_GetTicks();
			double dt = (currentTicks - lastTicks)*0.001;
			lastTicks = currentTicks;
			vragnum = getrand(0, 4);
			initMob(&enemy, vragnum);
			if (igrok.xod==true&&enemy.xod==false)
			{
				draka_P(&igrok, &enemy, battleswitch(mousepos));
			}
			if (igrok.xod==false&& enemy.xod ==true)
			{
				draka_V(&igrok, &enemy, 0);
			}
			
			pressedbutonfight;


			SDL_RenderPresent(renderer);
			SDL_RenderClear(renderer);
		}
		if (wind == 2)//главное меню
		{
			int currentTicks = SDL_GetTicks();
			double dt = (currentTicks - lastTicks)*0.001;
			lastTicks = currentTicks;
			glswitch(&wind,mousepos);
			//render glmeny

			SDL_RenderPresent(renderer);
			SDL_RenderClear(renderer);
		}
		if (wind==-1)
		{
			isRunning = false; return 0; break;
		}

	}


	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;



}
