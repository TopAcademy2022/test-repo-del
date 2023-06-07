#include "tanker.h"
#include "tank.h"
#include "tank-team.h"

int main()
{
	srand(time(NULL));

	//Tank tankA = Tank();
	//Tank tankB = Tank();
	//Tank::AutoFight(tankA, tankB);

	TankTeam redTeam = TankTeam();
	TankTeam blueTeam = TankTeam();

	TankTeam::TeamAutoFight(redTeam, blueTeam);
}