#pragma once
#include "Unit.h"
#include "lvlManager.h"
#include "textureManager.h"
//#include "unitType.h"
#include <vector>
#include "player.h"
#include "DrawableUnit.h"
#include "SoundManager.h"
#include <SFML/Audio.hpp>

class UnitManager {
public:
	UnitManager(lvlManager*, TextureManager*, Player*, SoundManager*);
	~UnitManager();
	bool spawnUnit(UnitType, int, int);
	std::vector<DrawableUnit> getUnits();
	std::vector<Unit> unitList;
	Player* player;
	bool movePlayer(int, int, Player*);
	void playerAttack(Unit*);
	void isDead(int);
	void gatherActions();
	sf::SoundBuffer dieBuffer;
	sf::Sound die;
private:
	lvlManager* lvl = NULL;
	TextureManager* tex = NULL;
	SoundManager* snd = NULL;
};