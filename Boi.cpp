#include <iostream>
#include <time.h>
#include "Boi.h"


void draka_P(Player *pl, Vrag *v,int nagatie)
{
	if (pl->xod == true)
	{
		if (nagatie == 0)
		{
			Udar_P(pl,v);
			pl->xod = false;
			v->xod = true;
		}
		else if (nagatie == 1)
		{
			Kast_P(pl, v);
			pl->xod = false;
			v->xod = true;
		}
		else if (nagatie == 2)
		{
			Up_bron_P(pl, v);
			pl->xod = false;
			v->xod = true;
		}
		else if (nagatie == 3)
		{
			Liv_P(pl, v);
		}
		if (nagatie == -1)
		{
			pl->xod = false;
			v->xod = true;
		}
	}
}
void draka_V(Player *pl, Vrag *v)
{
	srand(time(NULL));
	if (v->xod == true)
	{
		v->nagatie = rand() % 2;
		if (v->nagatie == 0)
		{
			Udar_V(pl, v);
		}
		else if (v->nagatie == 1)
		{
			Kast_V(pl, v);
		}
		else if (v->nagatie == 2)
		{
			Up_bron_V(pl, v);
		}
	}
}

//player
void Udar_P(Player *pl, Vrag *v)
{
	v->hp += v->brony - pl->uron;
}
void Kast_P(Player *pl, Vrag *v)
{
	if (pl->mana < 30)
		return;
	v->hp -= pl->spal_uron;
	pl->mana -= 30;
}
void Up_bron_P(Player *pl, Vrag *v)
{
	pl->brony += 3;
}
void Liv_P(Player *pl, Vrag *v)
{
	srand(time(NULL));
	int c = rand() % 100 + 1;
	if (c < 36)
	{
		pl->xod = false;
		v->xod = false;
	}
	else
	{
		return;
	}
}
void initPlayer(Player *pl)
{
	pl->hp = 100;
	pl->mana = 100;
	pl->uron = 10;
	pl->spal_uron = 10;
	pl->exp = 0;
	pl->mane = 0;
	pl->lvl = 1;
	
}
//enemy
void Udar_V(Player *pl, Vrag *v)
{
	pl->hp += pl->brony - v->uron;
}
void Kast_V(Player *pl, Vrag *v)
{
	if (v->mana < 30)
		return;
	pl->hp -= v->spal_uron;
	v->mana -= 30;
}
void Up_bron_V(Player *pl, Vrag *v)
{
	v->brony += 3;
}
void initMob(Vrag *v, int a)
{
	if (a == 0)
	{
		strcpy_s(v->mas, "Mob1");//танк
		v->hp = 200;
		v->mana = 30;
		v->brony = 10;
		v->uron = 25;
	}
	else if (a == 1)
	{
		strcpy_s(v->mas, "Mob2");//типо дальник
		v->hp = 70;
		v->mana = 120;
		v->brony = 3;
		v->uron = 35;
	}
	else if (a == 2)
	{
		strcpy_s(v->mas, "Mob3");//обычный
		v->hp = 100;
		v->mana = 100;
		v->brony = 5;
		v->uron = 10;
	}
	else if (a == 3)
	{
		strcpy_s(v->mas, "Mob4");//танк
		v->hp = 350;
		v->mana = 10;
		v->brony = 16;
		v->uron = 5;
	}
	else if (a == 4)
	{
		strcpy_s(v->mas, "Mob5");//слабый
		v->hp = 100;
		v->mana = 120;
		v->brony = 3;
		v->uron = 7;
	}
	else if (a == 10)
	{
		strcpy_s(v->mas, "Boss");//boss
		v->hp = 300;
		v->mana = 250;
		v->brony = 12;
		v->uron = 50;
	}
}