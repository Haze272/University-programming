#include "../helpFunc/helpFunctions.h"
#include "weeks.h"
#include <iostream>
#include <string>
#define  NOMINMAX // Без этого define происходит кофликт библиотеки Windows.h и max() в функции inputInt
#include <Windows.h> // Реализация русского ввода/вывода
#include <cmath>
#define M_PI 3.14159265358979323846
#include <fstream>

using namespace std;
void khanZamai();

/*-----------------------------------------Четвёртая неделя-----------------------------------------*/

void task4_1() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;
	float Zamai, Sum;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Файл----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		Sum = 0;

		cout << "Вводите 10 чисел поочерёдно через enter\n";
		ofstream damnson("fifa202n.txt");

		for (int i = 0; i < 10; i++) {
			Zamai = inputFloat(-2147483647, 2147483647);
			damnson << Zamai << endl;
		}
		damnson.close();


		cout << "Файл был успешно создан!\n\n";

		ifstream file_leer("fifa202n.txt");
		int b;

		do
		{
			// пробуем считать число
			if (file_leer >> b)
			{
				Sum += b;
			}
			else
			{
				file_leer.clear();
				file_leer.ignore(1, ' ');
			}
		} while (!file_leer.eof());

		cout << "Сумма чисел в файле равна: " << Sum << endl;

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

int sign(float x) {
	if (x > 0)
		return 1;
	else if (x == 0)
		return 0;
	else if (x < 0)
		return -1;
}

void task4_2() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;
	float numero;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Знак числа----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "Введите число\n";
		numero = inputFloat(-2147483647, 2147483647);

		if (sign(numero) == 1)
			cout << "Число " << numero << " - положительное.";
		else if (sign(numero) == 0)
			cout << "Число " << numero << " - не положительное и не отрицательное.";
		else if (sign(numero) == -1)
			cout << "Число " << numero << " - отрицательное.";

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

float areaDeRectangulo(float x, float y) {
	int result = x * y;
	return result;
}

float areaDeTriangulo(float x, float y, float z) {
	float poluPoker = (x + y + z) * 0.5;
	float result = sqrt(poluPoker * (poluPoker - x) * (poluPoker - y) * (poluPoker - z));
	return result;
}

float areaDeCirculo(float x) {
	float result = M_PI * pow(x, 2);
	return result;
}

void task4_3() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;
	int choice;
	float area, rect1, rect2, tri1, tri2, tri3, radius;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Геометрические фигуры----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "Плоащадь какой фигуры необходимо узнать?\n";
		cout << "1 - Прямоугольник\n";
		cout << "2 - Треугольник\n";
		cout << "3 - Окружность\n";
		choice = inputInt(1, 3);

		switch (choice) {
		case 1:
			cout << "Введите первую сторону прямоугольника\n";
			rect1 = inputFloat(0, 2147483647);
			cout << "Введите вторую сторону прямоугольника\n";
			rect2 = inputFloat(0, 2147483647);

			area = areaDeRectangulo(rect1, rect2);
			cout << "Площадь прямоугольника равна " << area << endl;
			break;
		case 2:
			cout << "Введите первую сторону треугольника\n";
			tri1 = inputFloat(0, 2147483647);
			cout << "Введите вторую сторону треугольника\n";
			tri2 = inputFloat(0, 2147483647);
			cout << "Введите третью сторону треугольника\n";
			tri3 = inputFloat(0, 2147483647);

			area = areaDeTriangulo(tri1, tri2, tri3);
			cout << "Площадь треугольника равна " << area << endl;
			break;
		case 3:
			cout << "Введите радиус окружности\n";
			radius = inputFloat(0, 2147483647);

			area = areaDeCirculo(radius);
			cout << "Площадь окружности равна " << area << endl;
			break;
		}

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void task4_4() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Былая слава----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		int y = 0;
		bool q = true;
		do {
			if (y < 6) {
				for (int i = 0; i < 8; i++) {
					cout << "* ";
				}
				if (y == 1 or y == 3 or y == 5) {
					for (int i = 7; i < 45; i++) {
						cout << " ";
					}
				}
				else
					for (int i = 7; i < 45; i++) {
						cout << "-";
					}
				if (y <= 6) {
					cout << "\n";
					y++;
				}
			}
			else if (y >= 6 and y < 13) {
				if (y == 7 or y == 9 or y == 11 or y == 13) {
					for (int i = 0; i < 54; i++) {
						cout << " ";
					}
				}
				else
					for (int i = 0; i < 54; i++) {
						std::cout << "-";
					}
				std::cout << "\n";
				y++;
			}
			else
				q = false;
		} while (q);

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void task4_5() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Синусоида----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		for (double y = 1.1; y > -1.1; y -= 0.1) {
			for (double x = -4; x < 4; x += 0.1) {
				if (abs(sin(x) - y) < 0.05)
					std::cout << "*";
				else if (x<0.05 && x>-0.05)
					std::cout << "|";
				else if (y<0.05 && y>-0.05)
					std::cout << "-";
				else
					std::cout << " ";
			}
			std::cout << '\n';
		}

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void task4_6() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;

	char romka[80];
	int temka, culpa;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Автоматный  хуй распознаватель----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		culpa = 0;
		cout << "Введите число в римской системе счисления\n";
		cin >> romka;
		temka = strlen(romka);

		for (int i = 0; i < temka; i++) {
			if (!((romka[i] == 'I') || (romka[i] == 'V') || (romka[i] == 'X') || (romka[i] == 'L') || (romka[i] == 'C') || (romka[i] == 'D') || (romka[i] == 'D'))) {
				culpa++;
			}
		}

		if (culpa != 0) {
			cout << "Вы допустили ошибку при вводе, повторите\n";
		}
		else {
			cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
			system("cls");
		}
	} while (!isExit);
}