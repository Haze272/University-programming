#include "../helpFunc/helpFunctions.h"
#include "weeks.h"
#include <iostream>
#include <string>
#define  NOMINMAX // Без этого define происходит кофликт библиотеки Windows.h и max() в функции inputInt
#include <Windows.h> // Реализация русского ввода/вывода
#include <cmath>
#define M_PI 3.14159265358979323846
#include <fstream>
#include <algorithm>
#include <iomanip>      // std::setw
#include <vector>

using namespace std;
void khanZamai();

/*-----------------------------------------Дополнительные задания-----------------------------------------*/

void spinner() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;

	float a, b, c;
	int N;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Спиннер----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		
		cout << "Введите первый параметр" << endl;
		a = inputFloat(-2147483647, 2147483647);
		cout << "Введите второй параметр" << endl;
		b = inputFloat(-2147483647, 2147483647);
		cout << "Введите третий параметр" << endl;
		c = inputFloat(-2147483647, 2147483647);

		N = (c - a) / b;
		cout << "Количество лопастей у спинеера " << N << endl;


		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}