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
	temp = IMG_Load("./FighScreen.png");
	SDL_Texture* hudfight = addtext(renderer, temp);
	temp = IMG_Load("./BossAlert.png");
	SDL_Texture* bossfight = addtext(renderer, temp);
	temp = IMG_Load("./Treasures.png");
	SDL_Texture* shopcontent = addtext(renderer, temp);
	temp = IMG_Load("./fightevents.png");
	SDL_Texture* fightev = addtext(renderer, temp);
	SDL_Rect wheltextpos = { 0,0,900,900 };
	SDL_Rect cubetextpos = {0,0,200,200};
	SDL_Rect cuberend = { 353,351,200,200 };
	SDL_Rect pointerPos = { 680,355,200,200 };
	SDL_Rect textRectPos;
	SDL_Rect fightTM = { 0,0,105,105 }, fightTP{ 0,0,105,105 };
	SDL_Rect fightPM = { 620,140,105,105 }, fightPP = { 160,140,105,105 };
	SDL_Rect shoprect = { 0,0,280,170 };
	SDL_Rect shoptextRect = { 0,0,280,170 };
	SDL_Color TextColor;
	//text init
	SDL_FreeSurface(temp);
	bool isRunning = true;
	int wind = 2, vragnum;
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
	int battleEvM = -1, battleEvP = -1;
	bool rotate = false, cubepress = false;
	bool battlepress=false;
	bool fightstart = false,fightboss=false;
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
			case SDLK_LEFT: {igrok.mane += 500; }break;
			case SDLK_i: {igrok.uron = 999; }break;
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
						battlepress = true;
						break;
					}
					if (wind == 2)
					{
						if (PInRect(mousepos, { 139,105 }, { 756,325 })) { wind = -2; break; }
						if (PInRect(mousepos, { 139,453 }, { 756,673 })){wind = -1; break;}
					}
					if (wind == 3)
					{//{ 520,420,280,170 };
						if (PInRect(mousepos, { 160,420 }, { 440,590 }))
						{
							if (igrok.mane >= price1) {
								igrok.mane -= price1;
								price2=price1 *= 2;
								switch (tovar1)
								{
								case 0: {igrok.hp += 75; }break;
								case 1: {igrok.uron += 15; }break;
								case 2: {igrok.basearmor += 10; }break;
								case 3: {igrok.spal_uron += 10; }break;
								case -1:break;
								}
								tovar1 = -1;
							}
						}
						if (PInRect(mousepos, { 520,420 }, { 700,590 }))
						{
							if (igrok.mane >= price2) {
								igrok.mane -= price2;
								price1 = price2 *= 2;
								switch (tovar1)
								{
								case 0: {igrok.hp += 75; }break;
								case 1: {igrok.uron += 15; }break;
								case 2: {igrok.basearmor += 10; }break;
								case 3: {igrok.spal_uron += 10; }break;
								case -1:break;
								}
								tovar2 = -1;
							}
						}
					}
					if (wind == 4)
					{
						if (PInRect(mousepos, { 141,291 }, { 760,515 })) { wind = 2; break; }
						if (PInRect(mousepos, { 141,564 }, { 760,783 })) { wind = -1; break; }
					}
					if (wind == 5)
					{
						if (PInRect(mousepos, { 30,355 }, { 420,545 })) { fightboss = true; wind = 1; fightstart = true;break; }
						if (PInRect(mousepos, { 470,355 }, { 870,545 })) { wind = 0;break; }
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
			if (wind == 0)//вращение круга 
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
						sobitie(circlepos, &igrok, &wind,&tovar1,&tovar2,&fightstart);
						
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
			if (wind == 1)//окно боя
			{
				int currentTicks = SDL_GetTicks();
				double dt = (currentTicks - lastTicks)*0.001;
				lastTicks = currentTicks;

				if (fightstart == true) {
					
					vragnum = getrand(0, 4);
					if (fightboss == true)vragnum = 10;
					initMob(&enemy, vragnum);
					enemy.basearmor = enemy.brony;
					igrok.brony = igrok.basearmor;
					fightstart = false;
				}
				if (igrok.xod == false && enemy.xod == true)
				{
					SDL_Delay(200);
					if (battlepress == true) {
						draka_V(&igrok, &enemy,&battleEvM);
						battlepress = false;
						igrok.mana += 10;
						if (igrok.mana > igrok.maxmana)igrok.maxmana = 100;
						igrok.brony = igrok.basearmor;
					}
				}
				if (igrok.xod == false && enemy.xod == false)
				{
					
					if (igrok.hp > 0)
					{
						wind = 0; SDL_Delay(200); break;
						igrok.brony = igrok.basearmor;
					}
				}
				if (igrok.xod == true && enemy.xod == false&& pressedbutonfight>=0)
				{
					SDL_Delay(200);
						draka_P(&igrok, &enemy, battleswitch(mousepos), &battleEvP);
						battlepress = false;
						enemy.mana += 15;
						if (enemy.mana > enemy.maxmana)enemy.maxmana = 100;
						enemy.brony = enemy.basearmor;
					
				}
				if (enemy.hp <= 0)
				{
					igrok.exp += 700;
					if (igrok.exp > 1000) { igrok.lvl++; igrok.exp -= 1000; }
					igrok.mane += 500;
					wind = 0;
				}
				if (igrok.hp<=0)
				{
					wind = 4;
				}
				
				//render fon

				SDL_RenderCopy(renderer, hudfight, NULL, NULL);
	
				//render mob (1-6)
				if (battleEvP >= 0)
				{
					fightTP.x = battleEvP * 105;
					SDL_RenderCopy(renderer, fightev, &fightTP, &fightPP);
				}
				if (battleEvM >= 0)
				{
					fightTM.x = battleEvM * 105;
					SDL_RenderCopy(renderer, fightev, &fightTM, &fightPM);
				}
				//otrisovka last deistvia igroka
				//otrisovka last deistvia 

				rendWord(renderer, {67,368,60,35}, igrok.hp, font);
				rendWord(renderer, { 67,408,60,35 }, igrok.brony, font);
				rendWord(renderer, { 67,452,60,35 }, igrok.mana, font);
				rendWord(renderer, { 67,490,60,35 }, igrok.spal_uron, font);
				rendWord(renderer, { 67,525,60,35 }, igrok.uron, font);

				rendWord(renderer, {770,368,60,35 },enemy.hp, font);
				rendWord(renderer, { 770,408,60,35 }, enemy.brony, font);
				rendWord(renderer, { 770,452,60,35 }, enemy.mana, font);
				rendWord(renderer, { 770,490,60,35 }, enemy.spal_uron, font);
				rendWord(renderer, { 770,530,60,35 }, enemy.uron, font);
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
				SDL_RenderCopy(renderer, backgroundshop, NULL, NULL);
				if (tovar1 >= 0)
				{
					shoprect = { 160,420,280,170 };
					shoptextRect.x = tovar1 * 280;
					SDL_RenderCopy(renderer, shopcontent, &shoptextRect, &shoprect);
					rendWord(renderer, { 160,565,120,60 }, price1, font);
				}
				if (tovar2 >= 0)
				{
					shoprect = { 520,420,280,170 };
					shoptextRect.x = tovar2 * 280;
					SDL_RenderCopy(renderer, shopcontent, &shoptextRect, &shoprect);
					rendWord(renderer, { 550,565,120,60 } , price2, font);
				}
				//rend tovar 1
				//rend tovar 2

				

				_itoa_s(igrok.mane, buf, 255, 10);
				textRectPos = { 750,29,80,40 };
				TextColor = { 255,255,255 };
				SDL_Surface* temp = TTF_RenderText_Solid(font, buf, TextColor);
				SDL_Texture* textrend = SDL_CreateTextureFromSurface(renderer, temp);
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
				SDL_RenderCopy(renderer, bossfight, NULL, NULL);
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
				price1 = 150;
				price2 = 150;
			}

		}

		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();

		return 0;



}
