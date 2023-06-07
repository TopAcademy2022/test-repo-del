#include "tanker.h"

std::string Tanker::CreatePeopleInfo()
{
	std::string bufer = "��� ��������: " + this->_name + '\n' +
		"�������: " + std::to_string(this->_age) + '\n' +
		"������� ��������: " + std::to_string(this->_healthPoints) + '\n';

	return bufer;
}

std::string Tanker::CreatePeopleInfo(People& otherTanker, bool printFlag)
{
	std::string bufer = "��� ��������: " + this->_name;
	
	for (int i = 0; i < 5; i++)
	{
		bufer.insert(bufer.size(), "\t");
	}
	
	if (printFlag)
	{
		bufer.insert(bufer.size(), "��� ��������: " + otherTanker.GetName() + "\n");

		bufer = "�������: " + std::to_string(this->_age);

		for (int i = 0; i < 5; i++)
		{
			bufer.insert(bufer.size(), "\t");
		}

		bufer.insert(bufer.size(), "�������: " + std::to_string(otherTanker.GetAge()) + "\n");

		bufer = "������� ��������: " + std::to_string(this->_healthPoints);

		for (int i = 0; i < 5; i++)
		{
			bufer.insert(bufer.size(), "\t");
		}

		bufer.insert(bufer.size(), "������� ��������: " + std::to_string(otherTanker.GetHealthPoints()) + "\n");
	}

	return bufer;
}