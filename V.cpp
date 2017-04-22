#include <iostream>
#include "V.h"


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
void initMob(Vrag *v,int a)
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