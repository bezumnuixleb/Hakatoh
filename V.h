#pragma once
#include <iostream>
#include "P.h"

struct Vrag
{
	int hp = 100;
	int mana = 100;
	int brony = 0;
	int uron = 5;
	int spal_uron = 12;
	bool xod = false;
};

void Udar_V(Player *pl, Vrag *v);
void Kast_V(Player *pl, Vrag *v);
void Up_bron_V(Player *pl, Vrag *v);