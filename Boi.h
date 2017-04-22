#pragma once
#include <iostream>
#include <time.h>

struct Vrag
{
	int hp = 100;
	int mana = 100;
	int brony = 0;
	int uron = 5;
	int spal_uron = 12;
	bool xod = false;
	int nagatie;
	double aut = 0;
	char mas[255];
};

struct Player
{
	int hp = 0;
	int mana = 0;
	int brony = 0;
	int uron = 0;
	int spal_uron = 0;
	int mane = 0;
	int exp = 0;
	bool xod = true;
	int lvl = 0;
};


void draka_P(Player *pl, Vrag *v, int nagatie);
void draka_V(Player *pl, Vrag *v);
void Udar_V(Player *pl, Vrag *v);
void Kast_V(Player *pl, Vrag *v);
void Up_bron_V(Player *pl, Vrag *v);
void initMob(Vrag *v, int a);
void Udar_P(Player *pl, Vrag *v);
void Kast_P(Player *pl, Vrag *v);
void Up_bron_P(Player *pl, Vrag *v);
void Liv_P(Player *pl, Vrag *v);
void initPlayer(Player *pl);