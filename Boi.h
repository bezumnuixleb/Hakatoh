#pragma once
#include <iostream>
#include <time.h>

struct Vrag
{
	int hp = 100;
	int mana = 100,maxmana=0;
	int brony = 0;
	int uron = 5;
	int spal_uron = 12;
	bool xod = false;
	int nagatie;
	double aut = 0;
	char mas[255];
	int basearmor = 0;
};

struct Player
{
	int hp = 0,maxhp=0;
	int mana = 0, maxmana = 0;
	int brony = 0;
	int uron = 0;
	int spal_uron = 0;
	int mane = 0;
	int exp = 0;
	bool xod = true;
	int lvl = 0;
	int basearmor = 0;
};


void draka_P(Player *pl, Vrag *v, int nagatie, int *ev);
void draka_V(Player *pl, Vrag *v, int *ev);
void Udar_V(Player *pl, Vrag *v);
void Kast_V(Player *pl, Vrag *v);
void Up_bron_V(Player *pl, Vrag *v);
void initMob(Vrag *v, int a);
void Udar_P(Player *pl, Vrag *v);
void Kast_P(Player *pl, Vrag *v);
void Up_bron_P(Player *pl, Vrag *v);
void Liv_P(Player *pl, Vrag *v);
void initPlayer(Player *pl);