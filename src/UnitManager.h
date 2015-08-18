#pragma once
#include "Unit.h"
#include "lvlManager.h"
#include "textureManager.h"
//#include "unitType.h"
#include <vector>

class UnitManager {
public:
	UnitManager(lvlManager*, TextureManager*);
	~UnitManager();
	bool spawnUnit(UnitType, int, int);
	std::vector<Unit> unitList;
private:
	lvlManager* lvl = NULL;
	TextureManager* tex = NULL;
};