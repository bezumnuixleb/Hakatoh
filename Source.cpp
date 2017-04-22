#include <iostream>
#include "SDL.h"
#include "MainCirc.h"
#include "Add.h"
#include "Mouse.h"
#include "SDL_ttf.h"
#include <time.h>
#include "Boi.h"

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
	SDL_Surface* temp = IMG_Load("./wheels.png");
	SDL_Texture* textwheel = addtext(renderer, temp);
	temp = IMG_Load("./background.png");
	SDL_Texture* backgroundwheel = addtext(renderer, temp);
	temp = IMG_Load("./pointer.png");
	SDL_Texture* pointer = addtext(renderer, temp);
	temp = IMG_Load("./cube.png");
	SDL_Texture* cubetext = addtext(renderer, temp);
	SDL_Rect wheltextpos = { 0,0,900,900 };
	SDL_Rect cubetextpos = {0,0,200,200};
	SDL_Rect cuberend = { 353,371,200,200 };
	SDL_Rect pointerPos = { 700,370,200,200 };
	//text init
	SDL_FreeSurface(temp);
	bool isRunning = true;
	int wind = 0, vragnum;
	Player igrok;
	SDL_Point mousepos = { 0,0 };
	Vrag enemy;
	int lastTicks = SDL_GetTicks();
	SDL_SetRenderDrawColor(renderer, 255, 76, 0, 0);
	int circlepos = 0, circletexturepos = 0;
	int tmpCub = 0, pressedbutonfight = -1, cubiknum = 0;
	float rotatelifetime = 0;
	bool rotate = false, cubepress = false;
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
			case SDL_MOUSEBUTTONDOWN:
			{
				switch (ev.button.button)
				{
				case SDL_BUTTON_LEFT: {
					if (wind == 0)
					{
						cubepress = true;break;
					}
					if (wind == 1)//obrabotka krotov
					{
						
					}

					if (wind == 3)
					{

					}

				}break;
				
				}
			}break;
			case SDL_MOUSEMOTION:
			{
				mousepos.x = ev.motion.x; mousepos.y = ev.motion.y;
			}break;
			}
			if (wind == 0)//вращение круга 
			{
				int currentTicks = SDL_GetTicks();
				double dt = (currentTicks - lastTicks)*0.001;
				lastTicks = currentTicks;

				if (startispressed(mousepos,cubepress) && rotate == false)
				{
					cubepress = false;
					tmpCub = getrand(1, 6);
					circletexturepos = circlepos;
					circlepos += tmpCub;
					if (circlepos>6)
					{
						circlepos = 0;
					}	//ogranichenie segmenta

					cubiknum = tmpCub;
					cubetextpos.x = tmpCub * 200-200;
					rotate = true;
					rotatelifetime = 2000;
				}
				if (rotate == true)
				{
					rotatelifetime -= dt;
					printf_s("!%d\n", rotatelifetime);
					if (circletexturepos == circlepos)
					{
						rotate = false;
					}
					else
					{
						if (rotatelifetime < 0)
						{
							circletexturepos++;
							if (circletexturepos>5)
							{
								circletexturepos = 0;
								
							}
							if (wheltextpos.x>5400)
							{
								wheltextpos.x = 0;
							}
							wheltextpos.x = 900*circletexturepos;
							printf_s("%d\n", wheltextpos.x);
							
							
							rotatelifetime = 2000;
							
							
						}
						
					}
					//ogranichenie segmenta

					//
				}

			
				SDL_RenderCopy(renderer, backgroundwheel, NULL, NULL);//render zadnika
				SDL_RenderCopy(renderer, textwheel, &wheltextpos,NULL );//render colesa
				SDL_RenderCopy(renderer, pointer,NULL, &pointerPos);//render player
				//render stats,money
				SDL_RenderCopy(renderer, pointer, &pointerPos, NULL);
				//render cubika
				SDL_RenderCopy(renderer, cubetext, &cubetextpos, &cuberend );
				SDL_RenderPresent(renderer);
				SDL_RenderClear(renderer);
				cubepress = false;
			}
			if (wind == 1)//окно боя
			{
				int currentTicks = SDL_GetTicks();
				double dt = (currentTicks - lastTicks)*0.001;
				lastTicks = currentTicks;
				vragnum = getrand(0, 4);
				initMob(&enemy, vragnum);
				if (igrok.xod == true && enemy.xod == false)
				{
					draka_P(&igrok, &enemy, battleswitch(mousepos));
				}
				if (igrok.xod == false && enemy.xod == true)
				{
					SDL_Delay(200);
					draka_V(&igrok, &enemy);
				}
				if (igrok.xod == false && enemy.xod == false)
				{
					if (igrok.hp > 0)
					{
						wind == 0;
					}
				}
				//render fon
				//render player
				//render mob (1-6)
				//render stats
				//
				//

				SDL_RenderPresent(renderer);
				SDL_RenderClear(renderer);
			}
			if (wind == 2)//главное меню
			{
				int currentTicks = SDL_GetTicks();
				double dt = (currentTicks - lastTicks)*0.001;
				lastTicks = currentTicks;
				glswitch(&wind, mousepos);
				//render glmeny

				SDL_RenderPresent(renderer);
				SDL_RenderClear(renderer);
			}
			if (wind == -1)
			{
				isRunning = false; return 0; break;
			}

		}
	}

		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();

		return 0;



}
