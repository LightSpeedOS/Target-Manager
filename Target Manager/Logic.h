#pragma once

#include "Structs.h"
#include "Includes.h"

void healthBar(Entity& entity)
{
	int filled = (entity.health + 9) / 10;
	int empty = 10 - filled;

	cout << "[";
	for (int i = 0; i < filled; i++) cout << "#";
	for (int i = 0; i < empty; i++) cout << "-";
	cout << "]";
}

const char* teamColor(Entity& entity)
{
	if (entity.team == 1) return green;
	else return red;

	return reset;
}

void listEntities(vector<Entity>& entities, Entity& localPlayer)
{
	int subMenu;

	while (true)
	{
		clear();

		cout << "========== Sub Menu ==========" << endl;
		space();

		cout << "[1] -> List All" << endl;
		cout << "[2] -> List Enemies" << endl;
		cout << "[3] -> List Team" << endl;
		cout << "[4] -> List Local Player" << endl;
		space();

		cout << "> ";
		cin >> subMenu;

		if (input())
		{
			continue;
		}

		switch (subMenu)
		{

		case All:
			clear();

			cout << "Entity List" << endl;
			space();

			for (size_t i = 0; i < entities.size(); i++)
			{
				cout << "Name: " << entities[i].name << " | Team: " << teamColor(entities[i]) << entities[i].team << reset << " | ";
				healthBar(entities[i]); cout << " (" << entities[i].health << ") ";
				if (entities[i].health <= 0) cout << " Dead!" << endl;
				else cout << endl;
			}

			space();
			cout << "[S] Show Coordinates  [R] Return" << endl;

			char key = _getch();

			switch (tolower(key))
			{
			case 's':
				clear();

				constexpr float unitsPerMeter = 100.0f;

				for (size_t i = 0; i < entities.size(); i++)
				{

					float disX = entities[i].position.x - localPlayer.position.x;
					float disY = entities[i].position.y - localPlayer.position.y;

					float distance = sqrt((disX * disX) + (disY * disY));
					float distanceMeters = distance / unitsPerMeter;

					cout << "Name: " << entities[i].name << " | Team: " << teamColor(entities[i]) << entities[i].team << reset << " | ";
					healthBar(entities[i]); cout << " (" << entities[i].health << ") ";
					cout << fixed << setprecision(2);
					cout << distanceMeters << "[m] ";;

					if (i == 0) cout << "Local Player" << endl;
					else cout << endl;
				}
				getKey();
				

				break;
			}
		}

	}
}