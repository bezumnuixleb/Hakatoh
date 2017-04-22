#include <iostream>
#include <time.h>

#include "P.h"

void Udar_P(Player *pl, Vrag *v)
{
	v->hp += v->brony - pl->uron;
}
void Kast_P(Player *pl, Vrag *v)
{
	v->hp += v->brony - pl->spal_uron;
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
		//выход
	}
	else
	{
		return;
	}
}