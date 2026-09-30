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
	Allies,
	Local
};

enum Team
{
	None = -1,
	Raiders = 1, // Team
	Arcs        // Enemy
};

struct Vec2
{
	float x, y;
};

struct Entity
{
	string name;
	int health;
	static constexpr int maxHealth = 100;
	int team;
	int damage;
	Vec2 position;
};