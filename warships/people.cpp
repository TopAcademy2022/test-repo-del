#include "people.h"
#include <iostream>

std::wstring converter::ConverRUStringToWstring(std::string sourceString)
{
	const unsigned int RU_CHAR_SHIFT_FOR_WCHAR = 1104;
	const int RU_CHAR_START_CODE = -64;
	const int RU_CHAR_FINISH_CODE = -1;

	std::wstring result;

	for (int i = 0; i < sourceString.size(); i++)
	{
		wchar_t symbol = sourceString[i];

		if (sourceString[i] >= RU_CHAR_START_CODE && sourceString[i] <= RU_CHAR_FINISH_CODE)
		{
			symbol += RU_CHAR_SHIFT_FOR_WCHAR;
		}
		else if (sourceString[i] == -72)
		{
			symbol = 1105;
		}

		result += symbol;
	}

	return result;
}

std::string converter::ConverRUCharsToString(const char* sourceChars, std::string nameFileForLocale)
{
	std::map<int*, int> badLocaleToRussiansChars = loader::ReadMapFromFile(nameFileForLocale);
	char* resultString = new char[strlen(sourceChars) / 2 + 1]();

	for (int i = 0, k = 0; i < strlen(sourceChars) / 2; i++, k += 2)
	{
		char firstLetter = sourceChars[k];
		char secondLetter = sourceChars[k + 1];

		int keys[2] = { firstLetter, secondLetter };
		*(resultString + i) = loader::GetValueByKeyInMap(badLocaleToRussiansChars, keys);
	}

	return std::string(resultString);
}

template <typename T> T random::GetRandomElementFromVector(std::vector<T> sourceVector)
{
	const unsigned int MIN_INDEX = 0;
	const unsigned int MAX_INDEX = sourceVector.size() - 1;

	unsigned int randomIndex = rand() % (MAX_INDEX - MIN_INDEX + 1) + MIN_INDEX;

	return sourceVector[randomIndex];
}

std::vector<std::string> loader::ReadDataFromFile(std::string fullFileName, std::string nameFileForLocale)
{
	unsigned int DEFAULT_BUFER_SIZE = 1024;

	std::vector<std::string> resultVector = std::vector<std::string>();
	std::ifstream file = std::ifstream(fullFileName, std::ifstream::binary);

	while (file)
	{
		char* bufer = new char[DEFAULT_BUFER_SIZE];

		file.getline(bufer, DEFAULT_BUFER_SIZE, '\n');
		std::string str = converter::ConverRUCharsToString(bufer, nameFileForLocale);

		if (str.empty())
		{
			break;
		}

		resultVector.push_back(str);
		delete[] bufer;
	}

	file.close();

	return resultVector;
}

char loader::GetValueByKeyInMap(std::map<int*, int> object, int* findedKey)
{
	char result = NULL;

	for (auto elem = object.begin(); elem != object.end(); elem++)
	{
		if (elem->first[0] == findedKey[0] && elem->first[1] == findedKey[1])
		{
			result = elem->second;
		}
	}

	return result;
}

std::map<int*, int> loader::ReadMapFromFile(std::string fullFileName)
{
	unsigned int DEFAULT_BUFER_SIZE = 1024;

	std::map<int*, int> result = std::map<int*, int>();
	std::ifstream file = std::ifstream(fullFileName, std::ifstream::binary);

	char* bufer = nullptr;

	while (file)
	{
		bufer = new char[DEFAULT_BUFER_SIZE];
		file.getline(bufer, DEFAULT_BUFER_SIZE, ':');

		if (*bufer == 0)
		{
			break;
		}

		int* letter = new int[2];
		letter[0] = bufer[0];
		letter[1] = bufer[1];

		delete[] bufer;

		bufer = new char[DEFAULT_BUFER_SIZE];
		file.getline(bufer, DEFAULT_BUFER_SIZE, '\n');
		int secondNumber = atoi(bufer);
		delete[] bufer;

		result.insert({ letter, secondNumber });
	}

	file.close();

	return result;
}

void People::Init()
{
	const uint8_t MIN_AGE = 18;
	const uint8_t MAX_AGE = 65;

	const unsigned int MIN_HEALTH_POINTS = 100;
	const unsigned int MAX_HEALTH_POINTS = 500;

	std::vector<std::string> listOfNames = loader::ReadDataFromFile("./names.txt", "./latters-code.txt");

	this->_name = random::GetRandomElementFromVector(listOfNames);
	this->_age = rand() % (MAX_AGE - MIN_AGE + 1) + MIN_AGE;
	this->_healthPoints = rand() % (MAX_HEALTH_POINTS - MIN_HEALTH_POINTS + 1) + MIN_HEALTH_POINTS;
}

std::string People::CreatePeopleInfo()
{
	std::string bufer = "Имя: " + this->_name + '\n' +
		"Возраст: " + std::to_string(this->_age) + '\n' +
		"Текущее здоровье: " + std::to_string(this->_healthPoints) + '\n';

	return bufer;
}

std::string People::CreatePeopleInfo(People& otherTanker, bool printFlag)
{
	std::string bufer = "Имя танкиста: " + this->_name;

	for (int i = 0; i < 5; i++)
	{
		bufer.insert(bufer.size(), "\t");
	}

	if (printFlag)
	{
		bufer.insert(bufer.size(), "Имя танкиста: " + otherTanker._name + "\n");

		bufer.insert(bufer.size(), "Возраст: " + std::to_string(this->_age));

		for (int i = 0; i < 6; i++)
		{
			bufer.insert(bufer.size(), "\t");
		}

		bufer.insert(bufer.size(), "Возраст: " + std::to_string(otherTanker._age) + "\n");

		bufer.insert(bufer.size(), "Текущее здоровье: " + std::to_string(this->_healthPoints));

		for (int i = 0; i < 5; i++)
		{
			bufer.insert(bufer.size(), "\t");
		}

		bufer.insert(bufer.size(), "Текущее здоровье: " + std::to_string(otherTanker._healthPoints) + "\n\n");
	}
	else
	{
		bufer.insert(bufer.size(), "Это место вакантно!\n");
		bufer.insert(bufer.size(), "Возраст: " + std::to_string(this->_age) + '\n');
		bufer.insert(bufer.size(), "Текущее здоровье: " + std::to_string(this->_healthPoints) + "\n\n");
	}

	return bufer;
}

People::People()
{
	this->Init();
}

People::People(std::string name, uint8_t age, unsigned int healthPoints)
{
	this->_name = name;
	this->_age = age;
	this->_healthPoints = healthPoints;
}

unsigned int People::GetHealthPoints()
{
	return this->_healthPoints;
}

void People::PrintInfo()
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	std::string bufer = this->CreatePeopleInfo();

	if (consoleHandle != NULL)
	{
		WriteConsole(consoleHandle, converter::ConverRUStringToWstring(bufer).c_str(), bufer.size(), NULL, NULL);
	}
}

void People::PrintInfo(People& otherTanker, bool printFlag)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	std::string bufer = this->CreatePeopleInfo(otherTanker, printFlag);

	if (consoleHandle != NULL)
	{
		WriteConsole(consoleHandle, converter::ConverRUStringToWstring(bufer).c_str(), bufer.size(), NULL, NULL);
	}
}

void People::SubtractHealthPoints(int& remainderDamage)
{
	if (this->_healthPoints <= remainderDamage)
	{
		remainderDamage -= this->_healthPoints;
		this->_healthPoints = 0;
	}
	else
	{
		this->_healthPoints -= remainderDamage;
		remainderDamage = 0;
	}
}

void People::CopyTo(People& from, People& to)
{
	to._name = from._name;
	to._age = from._age;
	to._healthPoints = from._healthPoints;
}

std::string People::GetName()
{
	return this->_name;
}

uint8_t People::GetAge()
{
	return this->_age;
}
