#include "UnitManager.h"
#include <vector>
#include "Unit.h"

UnitManager::UnitManager(lvlManager* lvlMng, TextureManager* texMng) {
	unitList = std::vector<Unit>();
	lvl = lvlMng;
	tex = texMng;
}

bool UnitManager::spawnUnit(UnitType u, int x, int y) {
	// if ((!(lvl->isAccessible(x, y))) || lvl->map[x][y].pawn != NULL)
	// 	return false;

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

	//lvl->map[x][y].pawn = &unit;
	lvl->map[x][y].pawn = &unitList[unitList.size()];

	return true; //rm
}

UnitManager::~UnitManager() {
	
}