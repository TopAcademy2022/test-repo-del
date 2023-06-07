#pragma once


#include <map>
#include "tank.h"

namespace map_helper
{
	bool FindByKeyInMap(std::map<bool*, Tank> originMap, bool findedValue);
}

class TankTeam
{
private:
	static const unsigned int DEFAULT_COUNT_TANKS = 3;

	std::map<bool*, Tank> _tankTeam;

	Tank& GetRandomTankForShoot();

	Tank& GetRandomTarget();

	bool CheckAlive();

	static void PrintBattleInfo(Tank& a, Tank& b);
public:
	TankTeam(unsigned int countTanks = DEFAULT_COUNT_TANKS);

	static void TeamAutoFight(TankTeam& firstTeam, TankTeam& secondTeam);
};