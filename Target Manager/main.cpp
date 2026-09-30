#include "Includes.h"
#include "Logic.h"
#include "Structs.h"
#include "Entities.h"

using namespace std;

auto main() -> int
{
	initConsole();

	vector<Entity> entities;

	Entity localPlayer = {};
	localPlayer.name = "Raider";
	localPlayer.health = 100;
	localPlayer.team = 1;
	localPlayer.damage = 20;
	localPlayer.position.x = 2000;
	localPlayer.position.y = 1000;
	entities.push_back(localPlayer);

	Entity dummyTeamBot = {};
	dummyTeamBot.name = "Dummy Team";
	dummyTeamBot.health = 1;
	dummyTeamBot.team = 1;
	dummyTeamBot.position.x = 100;
	dummyTeamBot.position.y = 100;
	entities.push_back(dummyTeamBot);
	
	Entity johnBot = {};
	johnBot.name = "John";
	johnBot.health = 80;
	johnBot.team = 2;
	johnBot.position.x = 1520;
	johnBot.position.y = 786;
	entities.push_back(johnBot);

	Entity steveBot = {};
	steveBot.name = "Steve";
	steveBot.health = 19;
	steveBot.team = 2;
	steveBot.position.x = 920;
	steveBot.position.y = 200;
	entities.push_back(steveBot);

	Entity dummyDeadBot = {};
	dummyDeadBot.name = "Dummy";
	dummyDeadBot.health = 0;
	dummyDeadBot.team = 2;
	dummyDeadBot.position.x = 1000;
	dummyDeadBot.position.y = 1000;
	entities.push_back(dummyDeadBot);

	int mainMenu;

	Entity* currentTarget = nullptr;


	while (true)
	{
		clear();
		SetConsoleTitleA("Target Manager");

		cout << "========= TARGET MANAGER ==========" << endl;
		space();

		printTarget(currentTarget);

		cout << "[1] -> List Entities" << endl;
		cout << "[2] -> Find Closest Target" << endl;
		cout << "[3] -> Attack Current Target" << endl;
		cout << "[4] -> Heal Enemy" << endl;
		cout << "[5] -> Change Enemy Distance" << endl;
		cout << "[6] -> Clear Target" << endl;
		cout << "[7] Exit" << endl;

		space();
		cout << "> ";
		cin >> mainMenu;

		switch (mainMenu)
		{
		case List:
			listEntities(entities, localPlayer);
			break;

		case Find:
			currentTarget = findClosest(entities, localPlayer);
			break;

		case Attack:
			attackTarget(currentTarget, &localPlayer);
			break;

		case Heal:
			healTarget(currentTarget);
			break;

		case Change:
			targetPosition(currentTarget, entities, localPlayer);
			break;

		case Clear:
			clearTarget(currentTarget);
			break;

		case Exit:
			shutDown();
			break;
		}
	}

}