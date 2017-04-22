#pragma once
#include <iostream>
#include "V.h"

struct Player
{
	int hp = 100;
	int mana = 100;
	int brony = 0;
	int uron = 10;
	int spal_uron = 15;
	int mane = 0;
	int store = 0;
	bool xod = false;
	int nagatie;
};

void Udar_P(Player *pl, Vrag *v);
void Kast_P(Player *pl, Vrag *v);
void Up_bron_P(Player *pl, Vrag *v);
void Liv_P(Player *pl, Vrag *v);
