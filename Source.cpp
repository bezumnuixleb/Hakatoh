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
	TTF_Font * font = TTF_OpenFont("shrift.ttf", 35);//shrift
	SDL_Surface* temp = IMG_Load("./wheels.png");
	SDL_Texture* textwheel = addtext(renderer, temp);
	temp = IMG_Load("./background.png");
	SDL_Texture* backgroundwheel = addtext(renderer, temp);
	temp = IMG_Load("./pointer.png");
	SDL_Texture* pointer = addtext(renderer, temp);
	temp = IMG_Load("./cube.png");
	SDL_Texture* cubetext = addtext(renderer, temp);
	temp = IMG_Load("./shop.png");
	SDL_Texture* backgroundshop = addtext(renderer, temp);
	temp = IMG_Load("./losemenu.png");
	SDL_Texture* backgroundloose = addtext(renderer, temp);
	temp = IMG_Load("./startmenu.png");
	SDL_Texture* backgroundmain = addtext(renderer, temp);
	SDL_Rect wheltextpos = { 0,0,900,900 };
	SDL_Rect cubetextpos = {0,0,200,200};
	SDL_Rect cuberend = { 353,351,200,200 };
	SDL_Rect pointerPos = { 680,355,200,200 };
	SDL_Rect textRectPos;
	SDL_Color TextColor;
	//text init
	SDL_FreeSurface(temp);
	bool isRunning = true;
	int wind = 3, vragnum;
	char buf[255];
	Player igrok;
	SDL_Point mousepos = { 0,0 };
	Vrag enemy;
	int lastTicks = SDL_GetTicks();
	int price1 = 150,price2=150;//cena v magaze
	int tovar1 = 0, tovar2 = 0;//tovar v magaze
	SDL_SetRenderDrawColor(renderer, 255, 76, 0, 0);//orange color of error
	int circlepos = 0, circletexturepos = 0;//vrashenie kruga
	int tmpCub = 0, pressedbutonfight = -1, cubiknum = 0,tmprotate=0;
	bool rotate = false, cubepress = false;

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
			case SDLK_LEFT: {igrok.mane += 5; }break;
			case SDLK_ESCAPE: {
				switch (wind)
				{
				case 0: {wind = 2; }break;
				case 1: {}break;
				case 2: {isRunning = false; return 0; break; }break;
				case 3: {wind = 0; }break;
				case 4: {wind = 2; }break;
				case 5: {wind = 0; }break;
				default:
					break;
				}
				
				
				} break;
			}
			case SDL_MOUSEBUTTONDOWN:
			{
				switch (ev.button.button)
				{
				case SDL_BUTTON_LEFT: {
					if (wind == 0)
					{
						if (PInRect(mousepos, { 353,351 }, { 553,551 }))
						{
							cubepress = true;
						}
						break;
					}
					if (wind == 1)
					{
						pressedbutonfight=battleswitch(mousepos);
						break;
					}
					if (wind == 2)
					{
						if (PInRect(mousepos, { 139,105 }, { 756,325 })) { wind = -2; break; }
						if (PInRect(mousepos, { 139,453 }, { 756,673 })){wind = -1; break;}
					}
					if (wind == 3)
					{

					}
					if (wind == 4)
					{
						if (PInRect(mousepos, { 141,291 }, { 760,515 })) { wind = 1; break; }
						if (PInRect(mousepos, { 141,564 }, { 760,783 })) { wind = -1; break; }
					}

				}break;

				}
			}break;
			case SDL_MOUSEMOTION:
			{
				mousepos.x = ev.motion.x; mousepos.y = ev.motion.y;
			}break;
			}
		}
			if (wind == 0)//�������� ����� 
			{
				int currentTicks = SDL_GetTicks();
				double dt = (currentTicks - lastTicks)*0.001;
				lastTicks = currentTicks;
				if (cubepress == true)
				{
					cubepress = false;
					tmpCub = getrand(1, 6);
					circlepos += tmpCub;
					if (circlepos > 5)circlepos = 0;

					tmprotate = tmpCub;
					cubiknum = tmpCub;
					cubetextpos.x = tmpCub * 200 - 200;
					rotate = true;
				}
				if(rotate==true)
				{
					printf_s("%d\n", tmprotate);
					if (tmprotate<=0)
					{
						rotate = false;
						SDL_Delay(300);
						circlepos = circletexturepos;
						sobitie(circlepos, &igrok, &wind,&tovar1,&tovar2);
						
					}
					else
					{
						circletexturepos++;
						tmprotate--;
						if (circletexturepos>5)
						{
							circletexturepos = 0;
						}
						SDL_Delay(170);
					}
				}
				

				
				

				wheltextpos.x = (circletexturepos) * 900;
				SDL_RenderCopy(renderer, backgroundwheel, NULL, NULL);//render zadnika
				SDL_RenderCopy(renderer, textwheel, &wheltextpos,NULL );//render colesa
				SDL_RenderCopy(renderer, pointer,NULL, &pointerPos);//render player
				
				_itoa_s(igrok.mane, buf, 255, 10);
				textRectPos = {752,26,80,40 };
				TextColor = { 255,255,255 };
				SDL_Surface* temp = TTF_RenderText_Solid(font, buf, TextColor);
				SDL_Texture* textrend = SDL_CreateTextureFromSurface(renderer, temp);
				SDL_RenderCopy(renderer, textrend, NULL, &textRectPos);

				_itoa_s(igrok.lvl, buf, 255, 10);
				textRectPos = { 460,5,40,40 };
				TextColor = { 255,255,255 };
				temp = TTF_RenderText_Solid(font, buf, TextColor);
				textrend = SDL_CreateTextureFromSurface(renderer, temp);
				SDL_RenderCopy(renderer, textrend, NULL, &textRectPos);

				_itoa_s(igrok.hp, buf, 255, 10);
				textRectPos = { 77,16,75,41 };
				TextColor = { 255,255,255 };
				temp = TTF_RenderText_Solid(font, buf, TextColor);
				textrend = SDL_CreateTextureFromSurface(renderer, temp);

				SDL_RenderCopy(renderer, textrend, NULL, &textRectPos);
				//render stats,money
				SDL_RenderCopy(renderer, pointer, &pointerPos, NULL);
				//render cubika
				SDL_RenderCopy(renderer, cubetext, &cubetextpos, &cuberend );
				SDL_RenderPresent(renderer);
				SDL_RenderClear(renderer);
				cubepress = false;
				SDL_FreeSurface(temp);
				SDL_DestroyTexture(textrend);
			}
			if (wind == 1)//���� ���
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
			if (wind == 2)//������� ����
			{
				int currentTicks = SDL_GetTicks();
				double dt = (currentTicks - lastTicks)*0.001;
				lastTicks = currentTicks;
				glswitch(&wind, mousepos);
				//render glmeny

				SDL_RenderCopy(renderer, backgroundmain, NULL, NULL);
				SDL_RenderPresent(renderer);
				SDL_RenderClear(renderer);
			}
			if (wind == 3)//magazin
			{
				int currentTicks = SDL_GetTicks();
				double dt = (currentTicks - lastTicks)*0.001;
				lastTicks = currentTicks;
				//choose tovar
				//rend tovar 1
				//rend tovar 2

				SDL_RenderCopy(renderer, backgroundshop, NULL, NULL);

				_itoa_s(igrok.mane, buf, 255, 10);
				textRectPos = { 750,29,80,40 };
				TextColor = { 255,255,255 };
				SDL_Surface* temp = TTF_RenderText_Solid(font, buf, TextColor);
				SDL_Texture* textrend = SDL_CreateTextureFromSurface(renderer, temp);
				SDL_RenderCopy(renderer, textrend, NULL, &textRectPos);

				_itoa_s(price1, buf, 255, 10);
				textRectPos = {200,495,120,60 };
				TextColor = { 255,255,255 };
				temp = TTF_RenderText_Solid(font, buf, TextColor);
				textrend = SDL_CreateTextureFromSurface(renderer, temp);
				SDL_RenderCopy(renderer, textrend, NULL, &textRectPos);

				_itoa_s(price2, buf, 255, 10);
				textRectPos = { 550,495,120,60 };
				TextColor = { 255,255,255 };
				temp = TTF_RenderText_Solid(font, buf, TextColor);
				textrend = SDL_CreateTextureFromSurface(renderer, temp);
				SDL_RenderCopy(renderer, textrend, NULL, &textRectPos);

				SDL_RenderPresent(renderer);
				SDL_RenderClear(renderer);

				SDL_FreeSurface(temp);
				SDL_DestroyTexture(textrend);
			}
			if (wind == 4)//loosewind
			{
				int currentTicks = SDL_GetTicks();
				double dt = (currentTicks - lastTicks)*0.001;
				lastTicks = currentTicks;
				SDL_RenderCopy(renderer, backgroundloose, NULL, NULL);

				_itoa_s(igrok.lvl, buf, 255, 10);
				textRectPos = { 224,100,90,60 };
				TextColor = { 255,255,255 };
				SDL_Surface* temp = TTF_RenderText_Solid(font, buf, TextColor);
				SDL_Texture* textrend = SDL_CreateTextureFromSurface(renderer, temp);
				SDL_RenderCopy(renderer, textrend, NULL, &textRectPos);

				_itoa_s(igrok.mane, buf, 255, 10);
				textRectPos = { 667,120,120,60 };
				TextColor = { 255,255,255 };
				temp = TTF_RenderText_Solid(font, buf, TextColor);
				textrend = SDL_CreateTextureFromSurface(renderer, temp);
				SDL_RenderCopy(renderer, textrend, NULL, &textRectPos);

				SDL_FreeSurface(temp);
				SDL_DestroyTexture(textrend);
				SDL_RenderPresent(renderer);
				SDL_RenderClear(renderer);
			}
			if (wind == 5)//ask about boss
			{
				int currentTicks = SDL_GetTicks();
				double dt = (currentTicks - lastTicks)*0.001;
				lastTicks = currentTicks;

				SDL_RenderPresent(renderer);
				SDL_RenderClear(renderer);
			}
			if (wind == -1)
			{
				isRunning = false; return 0;
			}
			if (wind == -2)
			{
				initPlayer(&igrok);
				cubiknum = 1;
				circlepos = 0;
				circletexturepos = 0;
				tmpCub = 0;
				cubepress = false;
				rotate = false;
				//obnylenie
				wind = 0;
			}

		}

		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();

		return 0;



}
