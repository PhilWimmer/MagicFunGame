#pragma once
#include "Unit.h"
#include "lvlManager.h"
//#include "unitType.h"
#include <vector>

class UnitManager {
public:
	UnitManager(lvlManager*);
	~UnitManager();
	bool spawnUnit(UnitType, int, int);
	std::vector<Unit> unitList;
private:
	lvlManager* lvl = NULL;
};