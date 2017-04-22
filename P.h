#pragma once
#include <iostream>
#include "V.h"

struct Player
{
	int hp = 0;
	int mana = 0;
	int brony = 0;
	int uron = 0;
	int spal_uron = 0;
	int mane = 0;
	int score = 0;
	bool xod = true;
};

void Udar_P(Player *pl, Vrag *v);
void Kast_P(Player *pl, Vrag *v);
void Up_bron_P(Player *pl, Vrag *v);
void Liv_P(Player *pl, Vrag *v);
void initPlayer(Player *pl);