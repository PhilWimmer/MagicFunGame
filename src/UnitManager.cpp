#pragma once
#include "UnitManager.h"
#include <vector>
#include "Unit.h"
#include <iostream>
#include "ActionUnit.h"

UnitManager::UnitManager(lvlManager* lvlMng, TextureManager* texMng, Player* p, SoundManager* s) {
	unitList = std::vector<Unit>();
	lvl = lvlMng;
	tex = texMng;
	player = p;
	unitList.push_back(*(player->playerUnit));
	snd = s;

 	dieBuffer = s->soundTable.at("die");
	die = sf::Sound();
	die = sf::Sound(dieBuffer);
	die.setVolume(100);
}

bool UnitManager::spawnUnit(UnitType u, int x, int y) {
	if (!(lvl->isAccessible(x*128, y*128))) //isAcc uses pixel values
	 	return false;

	Unit unit;

	switch(u) {	
		case standard:
			break;
		case doge:	//(int mAP, int mHP, sf::Sprite s, TextureManager* texMng,int xPos, int yPos, UnitType u)
			unit = Unit(1000, 1000, sf::Sprite(), tex, x, y, doge); 
			break;
		case turtle:	
			unit = Unit(10, 10, sf::Sprite(), tex, x, y, turtle); 
			break;
	};

	unitList.push_back(unit);

	return true; //rm
}

UnitManager::~UnitManager() {
	
}

	
std::vector<DrawableUnit> UnitManager::getUnits() {
	std::vector<DrawableUnit> dUnits;
	for(std::vector<Unit>::iterator it = unitList.begin(); it != unitList.end(); ++it) {
    	sf::Sprite* sprtPtr = &(it->sprite);
    	DrawableUnit dU = {it->x, it->y, sprtPtr};
    	dUnits.push_back(dU);
    }
    return dUnits;
}

bool UnitManager::movePlayer(int newX, int newY, Player* p) {
	//for (std::vector<Unit>::iterator it = unitList.begin(); it != unitList.end(); ++it) 
	for (int i = 0; i < unitList.size(); i++) {
		//if (it->x == newX && it->y == newY) {
		if (unitList[i].x == newX && unitList[i].y == newY) {
			//if (newX != p->playerUnit->x && newY != p->playerUnit->y) {
				playerAttack(&(unitList[i]));
				isDead(i);
			//}
			return false;
		}
	}
	p->playerUnit->x = newX;
	p->playerUnit->y = newY;
	player = p;
	unitList[0] = *(player->playerUnit);
	p->playerUnit->currAP -= 1;
	//lvl->map[playerUnit->x][playerUnit->y].pawn = playerUnit;
	//std::cout << x << std::endl;
	return true;
}

void UnitManager::isDead(int index) {
	if (unitList[index].currHP <= 0) {
		unitList.erase(unitList.begin() + index, unitList.begin() + index + 1);
		die.play();
	}
}

void UnitManager::playerAttack(Unit* enemy) {
	int attackValue = rand() % 10;
	player->bark.play();
	enemy->currHP -= attackValue;
	std::cout << "Corgi attacks! Damage: " << attackValue << "! Enemy at " << enemy->currHP << " hp! wow such damage" << std::endl;
	std::cout << enemy->currHP << std::endl;
}

void UnitManager::gatherActions() {
	std::vector<ActionUnit> sortedUnits;

	for (std::vector<Unit>::iterator it = unitList.begin(); it != unitList.end(); ++it) {
		ActionUnit temp = {((double)it->maxAP / (double)it->currAP), &(*it)};
		sortedUnits.push_back(temp);
		std::cout << temp.apRatio << std::endl;
	}

	//std::cout << sortedUnits[1].apRatio << std::endl;

	// sortedUnits.insert(it, &unitList[0]);
	// sortedUnits.push_back(&unitList[0]);
	// std::cout << sortedUnits[0]->maxAP << std::endl;
}

