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
	/// Конвертировать русско-английскую строку string в wstring
	/// </summary>
	/// <param name="sourceString">Изначальная строка</param>
	/// <returns>Конвертированная строка</returns>
	std::wstring ConverRUStringToWstring(std::string sourceString);

	/// <summary>
	/// Преобразовать русские символы в string
	/// </summary>
	/// <param name="sourceChars">Изначальная строка</param>
	/// <param name="nameFileForLocale">Название файла хранящего локаль</param>
	/// <returns>Преобразованная строка</returns>
	std::string ConverRUCharsToString(const char* sourceChars, std::string nameFileForLocale);
}

namespace random
{
	/// <summary>
	/// Получить случайное значение из вектора
	/// </summary>
	/// <typeparam name="T">Тип значения в векторе</typeparam>
	/// <param name="sourceVector">Основной вектор</param>
	/// <returns>Случайное значение из вектора</returns>
	template <typename T> T GetRandomElementFromVector(std::vector<T> sourceVector);
}

namespace loader
{
	/// <summary>
	/// Получить данные из файла
	/// </summary>
	/// <param name="fullFileName">Название файла с именами</param>
	/// <param name="nameFileForLocale">Название файла с буквами для локали</param>
	/// <returns>Данные из файла</returns>
	std::vector<std::string> ReadDataFromFile(std::string fullFileName, std::string nameFileForLocale);
	
	/// <summary>
	/// Получить значение по ключу из контейнера
	/// </summary>
	/// <param name="object">Основной контейнер</param>
	/// <param name="findedKey">Ключ</param>
	/// <returns>Значение по ключу</returns>
	char GetValueByKeyInMap(std::map<int*, int> object, int* findedKey);
	
	/// <summary>
	/// Получить контейнер из файла
	/// </summary>
	/// <param name="fullFileName">Название файла</param>
	/// <returns>Контейнер</returns>
	std::map<int*, int> ReadMapFromFile(std::string fullFileName);
}

/// <summary>
/// Класс Человек
/// </summary>
class People
{
protected:
	/// <summary>
	/// Имя
	/// </summary>
	std::string _name;

	/// <summary>
	/// Возраст
	/// </summary>
	uint8_t _age;

	/// <summary>
	/// Количество очков здоровья
	/// </summary>
	unsigned int _healthPoints;

	/// <summary>
	/// Инициализация объекта
	/// </summary>
	void Init();

	/// <summary>
	/// Создать информацию об объекте
	/// </summary>
	/// <returns>Информация об объекте</returns>
	virtual std::string CreatePeopleInfo();

	virtual std::string CreatePeopleInfo(People& otherTanker, bool printFlag = true);
public:
	/// <summary>
	/// Конструктор по умолчанию
	/// </summary>
	People();

	/// <summary>
	/// Конструктор с параметром
	/// </summary>
	/// <param name="name">Имя</param>
	/// <param name="age">Возраст</param>
	/// <param name="healthPoints">Количество очков здоровья</param>
	People(std::string name, uint8_t age, unsigned int healthPoints);

	/// <summary>
	/// Получить количество очков здоровья
	/// </summary>
	/// <returns>Количество очков здоровья</returns>
	unsigned int GetHealthPoints();

	/// <summary>
	/// Вывести информацию об объекте
	/// </summary>
	void PrintInfo();

	void PrintInfo(People& otherTanker, bool printFlag = true);

	/// <summary>
	/// Вычесть очки здоровья
	/// </summary>
	/// <param name="remainderDamage">Вычитаемое количество очков здоровья</param>
	void SubtractHealthPoints(int& remainderDamage);

	/// <summary>
	/// Скопировать данные в объект (по значению)
	/// </summary>
	/// <param name="from">Откуда скопировать данные</param>
	/// <param name="to">Куда скопировать данные</param>
	static void CopyTo(People& from, People& to);

	std::string GetName();

	uint8_t GetAge();
};