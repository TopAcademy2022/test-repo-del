#include "tanker.h"

std::string Tanker::CreatePeopleInfo()
{
	std::string bufer = "Имя танкиста: " + this->_name + '\n' +
		"Возраст: " + std::to_string(this->_age) + '\n' +
		"Текущее здоровье: " + std::to_string(this->_healthPoints) + '\n';

	return bufer;
}

std::string Tanker::CreatePeopleInfo(People& otherTanker, bool printFlag)
{
	std::string bufer = "Имя танкиста: " + this->_name;
	
	for (int i = 0; i < 5; i++)
	{
		bufer.insert(bufer.size(), "\t");
	}
	
	if (printFlag)
	{
		bufer.insert(bufer.size(), "Имя танкиста: " + otherTanker.GetName() + "\n");

		bufer = "Возраст: " + std::to_string(this->_age);

		for (int i = 0; i < 5; i++)
		{
			bufer.insert(bufer.size(), "\t");
		}

		bufer.insert(bufer.size(), "Возраст: " + std::to_string(otherTanker.GetAge()) + "\n");

		bufer = "Текущее здоровье: " + std::to_string(this->_healthPoints);

		for (int i = 0; i < 5; i++)
		{
			bufer.insert(bufer.size(), "\t");
		}

		bufer.insert(bufer.size(), "Текущее здоровье: " + std::to_string(otherTanker.GetHealthPoints()) + "\n");
	}

	return bufer;
}