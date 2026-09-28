#include "Includes.h"
#include "Logic.h"
#include "Structs.h"

using namespace std;

auto main() -> int
{
	initConsole();

	vector<Entity> entities;

	Entity localPlayer = {};
	localPlayer.name = "Raider";
	localPlayer.health = 100;
	localPlayer.team = 1;
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


	while (true)
	{
		cout << "========== TARGET MANAGER ==========" << endl;
		space();

		cout << "[1] -> List Entities" << endl;
		cin >> mainMenu;

		switch (mainMenu)
		{
		case List:
			listEntities(entities, localPlayer);
			break;
		}
	}

}