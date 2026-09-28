#pragma once

#include "Includes.h"

enum mainMenu
{
	List = 1,
	Find,
	Attack,
	Heal,
	Change,
	Clear,
	Exit
};

enum subMenu
{
	All = 1,
	Enemies,
	Team,
	Local
};

struct Vec2
{
	float x, y;
};

struct Entity
{
	string name;
	int health;
	int team;
	Vec2 position;
};