#include "tank-team.h"

bool map_helper::FindByKeyInMap(std::map<bool*, Tank> originMap, bool findedValue)
{
	bool result = false;

	for (auto iterator = originMap.begin(); iterator != originMap.end(); iterator++)
	{
		if (*(iterator->first) == findedValue)
		{
			result = true;
			break;
		}
	}

	return result;
}

TankTeam::TankTeam(unsigned int countTanks)
{
	this->_tankTeam = std::map<bool*, Tank>();
	
	for (int i = 0; i < countTanks; i++)
	{
		bool* key = new bool(false);
		Tank& value = *(new Tank());

		this->_tankTeam.insert({ key, value });
	}
}

Tank& TankTeam::GetRandomTankForShoot()
{
	const unsigned int min = 0;
	const int max = this->_tankTeam.size() - 1;

	auto it = this->_tankTeam.begin();
	int indexTank = 0;
	int oldIndexTank = -1;

	do
	{
		indexTank = rand() % (max - min + 1) + min;

		if (indexTank != oldIndexTank)
		{
			it = this->_tankTeam.begin();
			std::advance(it, indexTank);
		}
		
		oldIndexTank = indexTank;
	} while (*it->first);

	*(it->first) = true;

	if (!map_helper::FindByKeyInMap(this->_tankTeam, false))
	{
		for (auto element : this->_tankTeam)
		{
			*(element.first) = false;
		}
	}

	return it->second;
}

Tank& TankTeam::GetRandomTarget()
{
	const unsigned int min = 0;
	const int max = this->_tankTeam.size() - 1;

	auto it = this->_tankTeam.begin();
	unsigned int indexTank = 0;

	indexTank = rand() % (max - min + 1) + min;
	std::advance(it, indexTank);

	return it->second;
}

bool TankTeam::CheckAlive()
{
	bool result = false;

	for (auto tankInTeam : this->_tankTeam)
	{
		if (tankInTeam.second.CheckAlive())
		{
			result = true;
			break;
		}
	}

	return result;
}

void TankTeam::PrintBattleInfo(Tank& a, Tank& b)
{
	std::string bufer;

	if (a.CheckAlive())
	{
		bufer = "Экипаж стреляющего танка:";

		printer::PrintOnConsole(bufer);

		for (int i = 0; i < 5; i++)
		{
			bufer = "\t";
			printer::PrintOnConsole(bufer);
		}

		bufer = "Экипаж жертвы:\n\n";
		printer::PrintOnConsole(bufer);

		for (int i = 0; i < 3; i++)
		{
			a.PrintInfoAboutTankist(i, b);
		}
	}
}

void TankTeam::TeamAutoFight(TankTeam& firstTeam, TankTeam& secondTeam)
{
	while (firstTeam.CheckAlive() && secondTeam.CheckAlive())
	{
		// Rewrite
		Tank& firstATank = firstTeam.GetRandomTankForShoot();
		Tank& targetForATank = secondTeam.GetRandomTarget();

		if (firstATank.CheckAlive())
		{
			printer::PrintOnConsole("\nПервый танк выбрал цель, результат:\n\n");
			PrintBattleInfo(firstATank, targetForATank);
			Sleep(5000);
			firstATank.Shoot(targetForATank);
			printer::PrintOnConsole("\nПервый танк произвёл выстрел, результат:\n\n");
			PrintBattleInfo(firstATank, targetForATank);
			Sleep(10000);
			system("cls");
		}

		Tank& secondBTank = secondTeam.GetRandomTankForShoot();
		Tank& targetForBTank = firstTeam.GetRandomTarget();

		if (secondBTank.CheckAlive())
		{
			printer::PrintOnConsole("\nВторой танк выбрал цель, результат:\n\n");
			PrintBattleInfo(secondBTank, targetForBTank);
			Sleep(5000);
			secondBTank.Shoot(targetForBTank);
			printer::PrintOnConsole("\nВторой танк произвёл выстрел, результат:\n\n");
			PrintBattleInfo(secondBTank, targetForBTank);
			Sleep(10000);
			system("cls");
		}
	}

	if (firstTeam.CheckAlive())
	{
		printer::PrintOnConsole("\nПЕРВАЯ команда ПОБЕДИЛА, УРА УРА УРАААААА!\n\n");
	}
	else
	{
		printer::PrintOnConsole("\nВТОРАЯ команда ПОБЕДИЛА, УРА УРА УРАААААА!\n\n");
	}
	printer::PrintOnConsole("\nСпасибо, что играли с нами  :D\n\n");
}