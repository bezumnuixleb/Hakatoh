#include <iostream>
#include <time.h>
#include "Boi.h"


void draka_P(Player *pl, Vrag *v,int nagatie,int *ev)
{
	if (pl->xod == true)
	{
		if (nagatie == 0)
		{
			Udar_P(pl,v);
			pl->xod = false;
			v->xod = true;
			*ev = 0;
		}
		else if (nagatie == 1)
		{
			Kast_P(pl, v);
			pl->xod = false;
			v->xod = true;
			*ev = 1;
		}
		else if (nagatie == 2)
		{
			Up_bron_P(pl, v);
			pl->xod = false;
			v->xod = true;
			*ev = 2;
		}
		else if (nagatie == 3)
		{
			Liv_P(pl, v);
			*ev = 3;
		}
		else if (nagatie == -1)
		{
			pl->xod = true;
			v->xod =false;
			*ev = -1;
		}
	}
}
void draka_V(Player *pl, Vrag *v, int *ev)
{
	srand(time(NULL));
	if (v->xod == true)
	{
		v->nagatie = rand() % 2;
		if (v->nagatie == 0)
		{
			Udar_V(pl, v);
			pl->xod = true;
			v->xod = false;
			*ev = 0;
		}
		else if (v->nagatie == 1)
		{
			Kast_V(pl, v);
			pl->xod = true;
			v->xod = false;
			*ev = 1;
		}
		
	}
}

//player
void Udar_P(Player *pl, Vrag *v)
{
	if (pl->uron - v->brony > 0) {
		v->hp -= pl->uron - v->brony;
	}
	else
	{
		v->hp -= 2;
		return;
	}
}
void Kast_P(Player *pl, Vrag *v)
{
	if (pl->mana < 40)
	{
		Udar_P(pl, v);
		return;
	}
	v->hp -= pl->spal_uron;
	pl->mana -= 40;
}
void Up_bron_P(Player *pl, Vrag *v)
{
	pl->brony += 20;
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
	pl->spal_uron = 25;
	pl->exp = 0;
	pl->mane = 0;
	pl->lvl = 1;
	pl->maxmana = 100;
}
//enemy
void Udar_V(Player *pl, Vrag *v)
{

	if (pl->uron - v->brony < 0) {
		pl->hp = pl->uron - v->brony;
	}
	else
	{
		pl->hp -= 2;
		return;
	}
}
void Kast_V(Player *pl, Vrag *v)
{
	if (v->mana < 40)
	{
		Udar_V(pl, v);
		return;
	}
	pl->hp -= v->spal_uron;
	v->mana -= 40;

}
void Up_bron_V(Player *pl, Vrag *v)
{
	v->brony +=20;
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
		v->maxmana = 30;
	}
	else if (a == 1)
	{
		strcpy_s(v->mas, "Mob2");//типо дальник
		v->hp = 70;
		v->mana = 120;
		v->brony = 3;
		v->uron = 35;
		v->maxmana = 120;
	}
	else if (a == 2)
	{
		strcpy_s(v->mas, "Mob3");//обычный
		v->hp = 100;
		v->mana = 100;
		v->brony = 5;
		v->uron = 10;
		v->maxmana = 100;
	}
	else if (a == 3)
	{
		strcpy_s(v->mas, "Mob4");//танк
		v->hp = 350;
		v->mana = 30;
		v->brony = 16;
		v->uron = 5;
		v->maxmana = 10;
	}
	else if (a == 4)
	{
		strcpy_s(v->mas, "Mob5");//слабый
		v->hp = 100;
		v->mana = 120;
		v->brony = 3;
		v->uron = 7;
		v->maxmana = 120;
	}
	else if (a == 10)
	{
		strcpy_s(v->mas, "Boss");//boss
		v->hp = 300;
		v->mana = 250;
		v->brony = 12;
		v->uron = 50;
		v->maxmana = 250;
	}
}