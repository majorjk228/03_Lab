// Лабораторная работа №3, Вариант 3 (2 семестр).
// Добавление, вычитание секунд.

#include "Time.h"
#include <iostream>
#include <windows.h>    // Библиотека для русской локализации

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");

	int s = 0;	// Секунды

	Time a;		//конструктор без параметров
	Time c;		//конструктор без параметров

	cin >> a;	//ввод переменной всего объекта
	cout << "Сколько необходимо добавить секунд: ";
	cin >> s;	//ввод переменной секунд

	Time b(s);  //конструктор только для добавления секунд 

	cout << "\nПроизводим добавление секунд: \n";
	c = a + b; // Вызываем перегруженный метод для сложения 
	cout << "1 объект A = " << a << endl;					  //вывод объекта
	cout << "2 объект B = " << b << endl;					  //вывод объекта
	cout << "Полученный итоговый объект C = " << c << endl;   //вывод объекта

	cout << "\nВычитание секунд" << endl;
	cout << "Сколько необходимо вычесть секунд: ";

	b.clear();		// Чистим секунды в объекте, для дальнейшей операции вычитания
	cin >> s;		//ввод переменной секунд
	b.set_sec(s);	// присваиваем новые секунды объекту
	c = a - b;		// Вызываем перегруженный метод для вычитания 

	cout << "1 объект A = " << a << endl;					  //вывод объекта
	cout << "2 объект B = " << b << endl;					  //вывод объекта
	cout << "Полученный итоговый объект C = " << c << endl;   //вывод объекта

	return 0;
}

