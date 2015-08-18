#include "UnitManager.h"
#include <vector>
#include "Unit.h"

UnitManager::UnitManager(lvlManager* lvlMng) {
	unitList = std::vector<Unit>();
	lvl = lvlMng;
}

bool UnitManager::spawnUnit(UnitType u, int x, int y) {
	if (!lvl->isAccessible(x, y))
		return false;

	Unit unit;

	// switch(u) {

	// };
	
	return true; //rm
}

UnitManager::~UnitManager() {
	
}