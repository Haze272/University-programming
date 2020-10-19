#include "../helpFunc/helpFunctions.h"
#include "weeks.h"
#include <iostream>
#define M_PI 3.14159265358979323846

using namespace std;
void khanZamai();

/*-----------------------------------------Вторая неделя-----------------------------------------*/

void task2_1() {
	khanZamai();
	string command_empty;
	bool isExit = false;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Конус----------------\n\n\n\n\n\n\n\n\n\n";

	double Volume, Area, height, radiusOut, radiusIn, forming;

	do {
		cout << "Введите радиус большего основания:\n";
		radiusOut = inputDouble(0, 2147483647);

		cout << "Введите радиус меньшего основания:\n";
		radiusIn = inputDouble(0, 2147483647);

		cout << "Введите высоту:\n";
		height = inputDouble(0, 2147483647);

		cout << "Введите образующую конуса:\n";
		forming = inputDouble(0, 2147483647);

		system("cls");

		Volume = M_PI / 3 * height * (pow(radiusOut, 2) + radiusOut * radiusIn + pow(radiusIn, 2));
		cout << "Объём вашего усечённого конуса равен " << Volume << endl;

		Area = M_PI * (pow(radiusOut, 2) + forming * (radiusOut + radiusIn) + pow(radiusIn, 2));
		cout << "Площадь вашего усечённого конуса равна " << Area << endl;

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void task2_2() {
	khanZamai();
	string command_empty;
	bool isExit = false;

	double w, a, x;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Разветвление----------------\n\n\n\n\n\n\n\n\n\n";

	int exceptionCounter;
	do {
		exceptionCounter = 0;

		cout << "Введите значение параметра a:" << endl;
		a = inputDouble(-2147483647, 2147483647);

		cout << "Введите значение переменной x:" << endl;
		x = inputDouble(-2147483647, 2147483647);

		try {
			if (abs(x) <= 0 && a - pow(x, 2) < 0) {
				throw 5201;
			}
			if (abs(x) <= 0) {
				throw 5202;
			}
			if (a - pow(x, 2) < 0) {
				throw 5203;
			}
		}
		catch (int dripperCatcher) {
			if (dripperCatcher == 5201) {
				exceptionCounter++;
				cout << "Вы вышли за область предела функции (|x| > 0) и (a - x^2 >= 0)";

				cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
				cin >> command_empty;
				if (command_empty == "!exit") {
					return;
				}
				else {
					break;
				}
			}
			if (dripperCatcher == 5202) {
				exceptionCounter++;
				cout << "Вы вышли за область предела функции (|x| > 0)";

				cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
				cin >> command_empty;
				if (command_empty == "!exit") {
					return;
				}
				else {
					break;
				}
			}
			if (dripperCatcher == 5203) {
				exceptionCounter = 1;
				cout << "Вы вышли за область предела функции (a - x^2 >= 0)";

				cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
				cin >> command_empty;
				if (command_empty == "!exit") {
					break;
				}
			}
		}

		if (exceptionCounter == 0) {
			if (abs(x) < 1) {
				w = a * log(abs(x));
			}
			else if (abs(x) >= 1) {
				w = sqrt(a - pow(x, 2));
			}
			cout << "\n\n\n\nОтвет равен " << w;

			cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
			system("cls");
		}
	} while (!isExit);
}

void task2_3() {
	khanZamai();
	string command_empty;
	bool isExit = false;

	double z, b, x, y;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Функция----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "Введите значение параметра b:" << endl;
		b = inputDouble(-2147483647, 2147483647);

		cout << "Введите значение переменной x:" << endl;
		x = inputDouble(-2147483647, 2147483647);

		cout << "Введите значение переменной y:" << endl;
		y = inputDouble(-2147483647, 2147483647);

		try {
			if (b - y <= 0 && b - x < 0) {
				throw 5301;
			}
			if (b - y <= 0) {
				throw 5302;
			}
			if (b - x < 0) {
				throw 5303;
			}
		}
		catch (int dripperCatcher) {
			if (dripperCatcher == 5301) {
				cout << "Вы вышли за область предела функции (b - y > 0) и (b - x >= 0)";

				cout << "\nПродолжим? Напишите всё что угодно\n";
				cin >> command_empty;
				break;
			}
			if (dripperCatcher == 5302) {
				cout << "Вы вышли за область предела функции (b - y > 0)";

				cout << "\nПродолжим? Напишите всё что угодно\n";
				cin >> command_empty;
				break;
			}
			if (dripperCatcher == 5303) {
				cout << "Вы вышли за область предела функции (b - x >= 0)";

				cout << "\nПродолжим? Напишите всё что угодно\n";
				cin >> command_empty;
				break;
			}
		}

		z = log(b - y) * sqrt(b - x);
		cout << "\n\n\n\nФункция равна " << z;

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void task2_4() {
	khanZamai();
	string command_empty;
	bool isExit = false;

	int order;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Порядок----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "Введите число, для которого выведутся последующие 10\n";

		order = inputInt(0, 2147483647);
		cout << "Последовательность равна:\n";
		for (int i = 10; i > 0; i--) {
			order++;
			cout << order << endl;
		}

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void task2_5() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;

	double tabel, result;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Табуляция----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "Введите число для табулирования функции\n";
		tabel = inputDouble(-2147483647, 2147483647);
		cout << endl;
		tabel -= 4;
		int counter = 1;

		for (int i = 0; i < 17; i++) {
			cout << counter << ") ";
			if (tabel - 1 != 0) {
				result = (pow(tabel, 2) - 2 * tabel + 2) / (tabel - 1);
				cout << "Результат для x = " << tabel << "равен: " << result << endl << endl;
			}
			try {
				if (tabel - 1 == 0) {
					throw 5501;
				}
			}
			catch (int q) {
				cout << "Результат для x = 1\n" << "Ошибка, на 0 делить нельзя (x - 1 != 0)" << endl << endl;
			}
			tabel += 0.5;
			counter++;
		}

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}