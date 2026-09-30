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

const char* healthColor(Entity* entity)
{
	if (entity->health > 50) return brightGreen;
	else if (entity->health > 20) return yellow;
	else return red;

	return reset;
}

const char* teamColor(Entity& entity)
{
	if (entity.team == 1) return green;
	else return red;

	return reset;
}

void printTarget(Entity* target)
{
	if (target == nullptr) cout << "Current Target: None" << endl, space();
	else cout << "Current Target: " << target->name << " " << healthColor(target) << target->health << reset << "/" << green << target->maxHealth << reset << endl, space();
}


Entity* findClosest(vector<Entity>& entities, Entity& localPlayer)
{
	clear();

	Entity* closet = nullptr;
	float closestDistance = FLT_MAX;
	constexpr float unitsPerMeter = 100.0f;
	constexpr float maxDistanceMeters = 200.0f;

	for (size_t i = 0; i < entities.size(); i++)
	{
		float disX = entities[i].position.x - localPlayer.position.x;
		float disY = entities[i].position.y - localPlayer.position.y;

		float distance = sqrt((disX * disX) + (disY * disY));
		float distanceMeters = distance / unitsPerMeter;


		if (distanceMeters >= maxDistanceMeters)
		{
			cout << "Entity is out of range." << endl;
			continue;
		}

		if (entities[i].team == 1) continue;

		if (closestDistance > distance)
		{
			closestDistance = distance;
			closet = &entities[i];
		}
	}

	if (closet == nullptr)
	{
		clear();
		cout << "[!] No Targets Within Range" << endl;
		pause();
		return nullptr;
	}

	else
	{
		space();
		cout << "Closest: " << closet->name << " | " << fixed << setprecision(2) << closestDistance / unitsPerMeter << "[m]" << endl;
		getKey();
		return closet;
	}

}

void attackTarget(Entity*& target, Entity* localPlayer)
{
	clear();

	if (target == nullptr)
	{
		cout << "[!] No Target To Attack" << endl;
		pause();
		return;
	}

	const int targetHealthSnapshot = target->health;
	target->health -= localPlayer->damage;

	cout << localPlayer->name << " Attacking " << target->name << " " << targetHealthSnapshot << " -> " << target->health
		<< " (" << red << "-" << localPlayer->damage << reset << ")" << endl;
	getKey();
}

void healTarget(Entity*& target)
{
	clear();
	if (target == nullptr)
	{
		cout << "[!] No Target To Heal" << endl;
		pause();
		return;
	}

	if (target->health == 100)
	{
		cout << "[+] " << target->name << "'s Health is Alread Max" << endl;
		pause();
		return;
	}

	const int targetHealthSnapshot = target->health;
	const int amount = target->maxHealth - targetHealthSnapshot;
	target->health = target->maxHealth;

	cout << "[+] " << target->name << "'s Health Has Been Replenished To Max | " << targetHealthSnapshot
		<< " -> " << target->health << " (" << green << "+" << amount << reset << ")" << endl;
	getKey();
}

void targetPosition(Entity*& target, vector<Entity>& entities, Entity& localPlayer)
{
	clear();


	if (target == nullptr)
	{
		cout << "[!] No Target To Edit" << endl;
		pause();
		return;
	}
	int result = MessageBoxA(NULL, "Changing The Target's Poistion Will Result In a Different Target Till Relaunch (or if You Clear Target)", "Disclaimer!", MB_YESNO | MB_ICONWARNING);

	if (result == IDYES)
	{
		float constexpr unitsPerMeter = 100.0f;

		while (true)
		{

			float newX;
			float newY;

			float xSnap = target->position.x;
			float ySnap = target->position.y;

			cout << "Enter X: ";
			cin >> newX;

			if (input())
			{
				continue;
			}

			cout << "Enter Y: ";
			cin >> newY;

			if (input())
			{
				continue;
			}

			target->position.x = newX;
			target->position.y = newY;


			float disX = target->position.x - localPlayer.position.x;
			float disY = target->position.y - localPlayer.position.y;

			float oldDisX = xSnap - localPlayer.position.x;
			float oldDisY = ySnap - localPlayer.position.y;

			float distance = sqrt((disX * disX) + (disY * disY));
			float oldDistance = sqrt((oldDisX * oldDisX) + (oldDisY * oldDisY));

			float distanceMeters = distance / unitsPerMeter;
			float oldDistanceMeters = oldDistance / unitsPerMeter;


			cout << "[+] Changed " << target->name << "'s Coordinates From " << oldDistanceMeters << "[m] -> " << distanceMeters << "[m]" << endl;
			getKey();
			break;
		}
	}

	else if (result == IDNO)
	{
		cout << "Reuturning." << endl;
		pause();
		return;
	}

}

void clearTarget(Entity*&  target)
{
	clear();
	if (target == nullptr)
	{
		cout << "[!] No Target To Clear" << endl;
		pause();
		return;
	}

	else
	{
		cout << "[+] " << green << "Successfully " << reset << "Cleared Target" << endl;
		getKey();
		target = nullptr;
	}
}
