#pragma once


#include <string>
#include <cstdint>
#include <Windows.h>
#include <ctime>
#include <vector>
#include <fstream>
#include <map>

namespace converter
{
	/// <summary>
	/// �������������� ������-���������� ������ string � wstring
	/// </summary>
	/// <param name="sourceString">����������� ������</param>
	/// <returns>���������������� ������</returns>
	std::wstring ConverRUStringToWstring(std::string sourceString);

	/// <summary>
	/// ������������� ������� ������� � string
	/// </summary>
	/// <param name="sourceChars">����������� ������</param>
	/// <param name="nameFileForLocale">�������� ����� ��������� ������</param>
	/// <returns>��������������� ������</returns>
	std::string ConverRUCharsToString(const char* sourceChars, std::string nameFileForLocale);
}

namespace random
{
	/// <summary>
	/// �������� ��������� �������� �� �������
	/// </summary>
	/// <typeparam name="T">��� �������� � �������</typeparam>
	/// <param name="sourceVector">�������� ������</param>
	/// <returns>��������� �������� �� �������</returns>
	template <typename T> T GetRandomElementFromVector(std::vector<T> sourceVector);
}

namespace loader
{
	/// <summary>
	/// �������� ������ �� �����
	/// </summary>
	/// <param name="fullFileName">�������� ����� � �������</param>
	/// <param name="nameFileForLocale">�������� ����� � ������� ��� ������</param>
	/// <returns>������ �� �����</returns>
	std::vector<std::string> ReadDataFromFile(std::string fullFileName, std::string nameFileForLocale);
	
	/// <summary>
	/// �������� �������� �� ����� �� ����������
	/// </summary>
	/// <param name="object">�������� ���������</param>
	/// <param name="findedKey">����</param>
	/// <returns>�������� �� �����</returns>
	char GetValueByKeyInMap(std::map<int*, int> object, int* findedKey);
	
	/// <summary>
	/// �������� ��������� �� �����
	/// </summary>
	/// <param name="fullFileName">�������� �����</param>
	/// <returns>���������</returns>
	std::map<int*, int> ReadMapFromFile(std::string fullFileName);
}

/// <summary>
/// ����� �������
/// </summary>
class People
{
protected:
	/// <summary>
	/// ���
	/// </summary>
	std::string _name;

	/// <summary>
	/// �������
	/// </summary>
	uint8_t _age;

	/// <summary>
	/// ���������� ����� ��������
	/// </summary>
	unsigned int _healthPoints;

	/// <summary>
	/// ������������� �������
	/// </summary>
	void Init();

	/// <summary>
	/// ������� ���������� �� �������
	/// </summary>
	/// <returns>���������� �� �������</returns>
	virtual std::string CreatePeopleInfo();

	virtual std::string CreatePeopleInfo(People& otherTanker, bool printFlag = true);
public:
	/// <summary>
	/// ����������� �� ���������
	/// </summary>
	People();

	/// <summary>
	/// ����������� � ����������
	/// </summary>
	/// <param name="name">���</param>
	/// <param name="age">�������</param>
	/// <param name="healthPoints">���������� ����� ��������</param>
	People(std::string name, uint8_t age, unsigned int healthPoints);

	/// <summary>
	/// �������� ���������� ����� ��������
	/// </summary>
	/// <returns>���������� ����� ��������</returns>
	unsigned int GetHealthPoints();

	/// <summary>
	/// ������� ���������� �� �������
	/// </summary>
	void PrintInfo();

	void PrintInfo(People& otherTanker, bool printFlag = true);

	/// <summary>
	/// ������� ���� ��������
	/// </summary>
	/// <param name="remainderDamage">���������� ���������� ����� ��������</param>
	void SubtractHealthPoints(int& remainderDamage);

	/// <summary>
	/// ����������� ������ � ������ (�� ��������)
	/// </summary>
	/// <param name="from">������ ����������� ������</param>
	/// <param name="to">���� ����������� ������</param>
	static void CopyTo(People& from, People& to);

	std::string GetName();

	uint8_t GetAge();
};