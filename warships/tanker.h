#pragma once


#include "people.h"

class Tanker : private People
{
private:
	/// <summary>
	/// Создать информацию о танкисте
	/// </summary>
	/// <returns>Информация о танкисте</returns>
	std::string CreatePeopleInfo() override;

	std::string CreatePeopleInfo(People& otherTanker, bool printFlag = true) override;
public:
	/// <summary>
	/// Наследования конструктора по умолчанию
	/// </summary>
	Tanker() : People() {};
};