#pragma once


#include "people.h"

namespace printer
{
	/// <summary>
	/// ������� ����� �� �������
	/// </summary>
	/// <param name="bufer">����� ��� ������</param>
	void PrintOnConsole(std::string bufer);
}

class Tank
{
private:
	/// <summary>
	/// ���������� ��������� �� ���������
	/// </summary>
	const uint8_t DEFAULT_COUNT_TANKISTS = 3;

	/// <summary>
	/// ���������� ����� �� ���������
	/// </summary>
	const unsigned int MIN_DEFAULT_DAMAGE = 300;

	const unsigned int MAX_DEFAULT_DAMAGE = 1300;

	/// <summary>
	/// ��������
	/// </summary>
	People* _tankists;

	/// <summary>
	/// ���������� ���������
	/// </summary>
	uint8_t countTankists;

	/// <summary>
	/// ��������� ����
	/// </summary>
	const unsigned int* DAMAGE;

	/// <summary>
	/// ������� �������� �� �����
	/// </summary>
	/// <param name="indexDeletedPeople">������ ���������� ��������</param>
	void KillPeople(unsigned int indexDeletedPeople);
public:
	/// <summary>
	/// ����������� �� ���������
	/// </summary>
	Tank();

	/// <summary>
	/// ������� ���������� � �����
	/// </summary>
	void PrintInfo();

	void PrintInfoAboutTankist(int tankistIndex, Tank& otherTank);

	/// <summary>
	/// ������� �������
	/// </summary>
	/// <param name="otherTank">������ ����</param>
	void Shoot(Tank& otherTank);

	/// <summary>
	/// ������ �������� ������
	/// </summary>
	/// <param name="firstTank">������ ����</param>
	/// <param name="secondTank">������ ����</param>
	static void AutoFight(Tank& firstTank, Tank& secondTank);

	/// <summary>
	/// ��������� ����������������
	/// </summary>
	bool CheckAlive();
};