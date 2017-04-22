#include <iostream>
#include "V.h"


void Udar_V(Player *pl, Vrag *v)
{
	pl->hp += pl->brony - v->uron;
}
void Kast_V(Player *pl, Vrag *v)
{
	pl->hp += pl->brony - v->spal_uron;
	v->mana -= 30;
}
void Up_bron_V(Player *pl, Vrag *v)
{
	v->brony += 3;
}