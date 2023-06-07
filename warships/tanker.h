#pragma once


#include "people.h"

class Tanker : private People
{
private:
	/// <summary>
	/// ������� ���������� � ��������
	/// </summary>
	/// <returns>���������� � ��������</returns>
	std::string CreatePeopleInfo() override;

	std::string CreatePeopleInfo(People& otherTanker, bool printFlag = true) override;
public:
	/// <summary>
	/// ������������ ������������ �� ���������
	/// </summary>
	Tanker() : People() {};
};