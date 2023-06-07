#pragma once


#include "people.h"

namespace printer
{
	/// <summary>
	/// Вывести текст на консоль
	/// </summary>
	/// <param name="bufer">Текст для печати</param>
	void PrintOnConsole(std::string bufer);
}

class Tank
{
private:
	/// <summary>
	/// Количество танкистов по умолчанию
	/// </summary>
	const uint8_t DEFAULT_COUNT_TANKISTS = 3;

	/// <summary>
	/// Количество урона по умолчанию
	/// </summary>
	const unsigned int MIN_DEFAULT_DAMAGE = 300;

	const unsigned int MAX_DEFAULT_DAMAGE = 1300;

	/// <summary>
	/// Танкисты
	/// </summary>
	People* _tankists;

	/// <summary>
	/// Количество танкистов
	/// </summary>
	uint8_t countTankists;

	/// <summary>
	/// Наносимый урон
	/// </summary>
	const unsigned int* DAMAGE;

	/// <summary>
	/// Удалить человека из танка
	/// </summary>
	/// <param name="indexDeletedPeople">Индекс удаляемого человека</param>
	void KillPeople(unsigned int indexDeletedPeople);
public:
	/// <summary>
	/// Конструктор по умолчанию
	/// </summary>
	Tank();

	/// <summary>
	/// Вывести информацию о танке
	/// </summary>
	void PrintInfo();

	void PrintInfoAboutTankist(int tankistIndex, Tank& otherTank);

	/// <summary>
	/// Сделать выстрел
	/// </summary>
	/// <param name="otherTank">Другой танк</param>
	void Shoot(Tank& otherTank);

	/// <summary>
	/// Начать сражение танков
	/// </summary>
	/// <param name="firstTank">Первый танк</param>
	/// <param name="secondTank">Второй танк</param>
	static void AutoFight(Tank& firstTank, Tank& secondTank);

	/// <summary>
	/// Проверить жизнеспособность
	/// </summary>
	bool CheckAlive();
};