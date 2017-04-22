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
			pl->xod = false;
			v->xod = true;
		}
		if (nagatie == -1)
		{
			pl->xod = false;
			v->xod = true;
		}
	}
}
void draka_V(Player *pl, Vrag *v, int nagatie)
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

