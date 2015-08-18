#include "Unit.h"
#include "lvlManager.h"
#include <vector>

class UnitManager {
public:
	UnitManager();
	~UnitManager();
	std::vector<Unit> unitList;

private:
	lvlManager* lvl = NULL;
};