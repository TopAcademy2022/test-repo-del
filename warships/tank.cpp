#include "tank.h"

void printer::PrintOnConsole(std::string bufer)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	if (consoleHandle != NULL)
	{
		WriteConsole(consoleHandle, converter::ConverRUStringToWstring(bufer).c_str(), bufer.size(), NULL, NULL);
	}
}

Tank::Tank()
{
	this->countTankists = this->DEFAULT_COUNT_TANKISTS;
	this->_tankists = new People[this->countTankists]();
	this->DAMAGE = new unsigned int(rand() % (this->MAX_DEFAULT_DAMAGE - this->MIN_DEFAULT_DAMAGE
		+ 1) + this->MIN_DEFAULT_DAMAGE);
}

bool Tank::CheckAlive()
{
	bool result = false;
	unsigned int allHealthPoints = 0;

	for (int i = 0; i < this->countTankists; i++)
	{
		allHealthPoints += (this->_tankists + i)->GetHealthPoints();
	}

	if (allHealthPoints > 0 && this->_tankists[0].GetAge() != 0)
	{
		result = true;
	}

	return result;
}

void Tank::Shoot(Tank& otherTank)
{
	if (otherTank.CheckAlive())
	{
		int remainderDamage = *this->DAMAGE;

		for (int i = 0; i < otherTank.countTankists; i++)
		{
			otherTank._tankists[i].SubtractHealthPoints(remainderDamage);

			if (!otherTank._tankists[i].GetHealthPoints())
			{
				otherTank.KillPeople(i);
				otherTank.countTankists -= 1;
				i--;
			}

			if (remainderDamage <= 0)
			{
				break;
			}
		}
	}
	else
	{
		std::string bufer = "Танк был УЖЕ уничтожен\n";
		printer::PrintOnConsole(bufer);
	}
}

void Tank::KillPeople(unsigned int indexDeletedPeople)
{
	unsigned int newCountPeoples = this->countTankists - 1;

	People* newPeoples = new People[newCountPeoples];

	for (int i = 0; i < indexDeletedPeople; i++)
	{
		People::CopyTo(this->_tankists[i], newPeoples[i]);
	}

	for (int i = indexDeletedPeople; i < newCountPeoples; i++)
	{
		People::CopyTo(this->_tankists[i + 1], newPeoples[i]);
	}

	delete[] this->_tankists;
	this->_tankists = newPeoples;
}

void Tank::PrintInfo()
{
	std::string bufer = "Количество танкистов в танке " + std::to_string(this->countTankists) + '\n' + 
		"Количество наносимого урона " + std::to_string(300) + '\n';
	

	if (this->countTankists)
	{
		bufer.insert(bufer.size(), "Информация о танкистах:\n\n");
	}
	else
	{
		bufer.insert(bufer.size(), "Все танкисты выбыли :(\n\n");
	}

	printer::PrintOnConsole(bufer);

	for (int i = 0; i < this->countTankists; i++)
	{
		this->_tankists[i].PrintInfo();
		printer::PrintOnConsole("\n");
	}
}

void Tank::PrintInfoAboutTankist(int tankistIndex, Tank& otherTank)
{
	if (tankistIndex >= 0 && tankistIndex < this->countTankists)
	{
		if (tankistIndex < otherTank.countTankists)
		{
			this->_tankists[tankistIndex].PrintInfo(otherTank._tankists[tankistIndex]);
		}
		else
		{
			this->_tankists[tankistIndex].PrintInfo(otherTank._tankists[tankistIndex], false);
		}
	}
}

void Tank::AutoFight(Tank& firstTank, Tank& secondTank)
{
	while (firstTank.CheckAlive() && secondTank.CheckAlive())
	{
		system("cls");

		uint8_t magicNumber = rand() % 2;

		if (!magicNumber)
		{
			firstTank.Shoot(secondTank);
			printer::PrintOnConsole("Первый танк нанёс урон!\n");
		}
		else
		{
			secondTank.Shoot(firstTank);
			printer::PrintOnConsole("Второй танк нанёс урон!\n");
		}

		Sleep(3000);

		firstTank.PrintInfo();
		secondTank.PrintInfo();

		Sleep(5000);
	}
}