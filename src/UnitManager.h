#pragma once
#include "Unit.h"
#include "lvlManager.h"
#include "textureManager.h"
//#include "unitType.h"
#include <vector>
#include "Player.h"
#include "DrawableUnit.h"

class UnitManager {
public:
	UnitManager(lvlManager*, TextureManager*, Player*);
	~UnitManager();
	bool spawnUnit(UnitType, int, int);
	std::vector<DrawableUnit> getUnits();
	std::vector<Unit> unitList;
	Player* player;
private:
	lvlManager* lvl = NULL;
	TextureManager* tex = NULL;
};