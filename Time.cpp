#include "Time.h"
#include <iostream>
#include <windows.h>    // Библиотека для русской локализации


using namespace std;
//перегрузка операции присваивания
Time& Time::operator=(const Time& t)
{
	//проверка на самоприсваивание
	if (&t == this) return *this;
	min = t.min;
	sec = t.sec;
	return *this;
}

//перегрузка префиксной операции инкремент
Time& Time::operator++()
{
	int temp = min * 60 + sec;
	temp++;
	min = temp / 60;
	sec = temp % 60;
	return *this;
}
//перегрузка постфиксной операции инкремент
Time Time::operator ++(int)
{
	int temp = min * 60 + sec;
	temp++;
	Time t(min, sec);
	min = temp / 60;
	sec = temp % 60;
	return t;
}
//перегрузка бинарной операции сложения
Time Time::operator+(const Time& t)
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	Time p;
	p.min = (temp1 + temp2) / 60;
	p.sec = (temp1 + temp2) % 60;
	return p;
}

//перегрузка бинарной операции вычитания
Time Time::operator-(const Time& t)
{
	int temp1 = min * 60 - sec;
	int temp2 = t.min * 60 - t.sec;
	Time p;
	p.min = (temp1 - temp2) / 60;
	p.sec = (temp1 - temp2) % 60;
	return p;
}


//перегрузка глобальной функции-операции ввода
istream& operator>>(istream& in, Time& t)
{
	SetConsoleCP(1251);         // Ввод с консоли в кодировке 1251 для русской локализации.
	SetConsoleOutputCP(1251);   // Вывод на консоль в кодировке 1251 для русской локализации.

	cout << "Введите минуты: "; in >> t.min;
	cout << "Введите секунды: "; in >> t.sec;
	return in;
}

//перегрузка глобальной функции-операции вывода
ostream& operator<<(ostream& out, const Time& t)
{
	return (out << t.min << " : " << t.sec);
}