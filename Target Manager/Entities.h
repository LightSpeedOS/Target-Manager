#pragma once

#pragma once

#include "Structs.h"
#include "Includes.h"
#include "Logic.h"

void displayEntity(vector<Entity>& entities, Entity& localPlayer, int teamFilter = -1, bool showDistance = false, bool justLocal = false)
{
	clear();
	cout << "=======Entity List=======" << endl;
	space();

	constexpr float unitsPerMeter = 100.0f;

	for (size_t i = 0; i < entities.size(); i++)
	{

		if (teamFilter != None && entities[i].team != teamFilter) continue;
		if (justLocal) if (i != 0) continue;

		float disX = entities[i].position.x - localPlayer.position.x;
		float disY = entities[i].position.y - localPlayer.position.y;

		float distance = sqrt((disX * disX) + (disY * disY));
		float distanceMeters = distance / unitsPerMeter;

		cout << "Name: " << entities[i].name << " | Team: " << teamColor(entities[i]) << entities[i].team << reset << " | ";
		healthBar(entities[i]); cout << " (" << entities[i].health << ") ";

		if (showDistance) cout << fixed << setprecision(2), cout << distanceMeters << "[m] " << endl;
		else cout << endl;

		if (i < entities.size() - 1) cout << "---------------" << endl; space();
	}
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
		cout << "[5] -> Return" << endl;
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
		{
				displayEntity(entities, localPlayer);
				

			space();
			cout << "[S] Show Coordinates  [R] Return" << endl;

			char key = _getch();

			switch (tolower(key))
			{
			case 's':
				displayEntity(entities, localPlayer, -1, true);
				getKey();
				break;
	

			case 'r':
				clear();
				return;

			default:
				invalid();
				while (_kbhit()) _getch();
				break;
			}
			break;
		}

		case Enemies:
			displayEntity(entities, localPlayer, Arcs, true);
			getKey();
			break;

		case Allies:
			displayEntity(entities, localPlayer, Raiders, true);
			getKey();
			break;

		case Local:
			displayEntity(entities, localPlayer, Raiders, true, true);
			getKey();
			break;
		
		case 5:
			clear();
			return;


		}


	}
}