//
//
// Домашняя работа №2 по процедурному программированию
// Беркунов Степан Игоревич, ИНБО-15-20
//
//

#include <iostream>
#include <string>
#define  NOMINMAX // Без этого define происходит кофликт библиотеки Windows.h и max() в функции inputInt
#include <Windows.h> // Реализация русского ввода/вывода
#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;

int inputInt(int m = INT_MIN, int M = INT_MAX)
{
	int N;
	for (;;) {
		if ((cin >> N).good() && (m <= N) && (N <= M)) return N;

		if (cin.fail()) {
			cin.clear();
			cout << "Неверный ввод, повторите." << endl;
		}
		else {
			cout << "Число вне допустимого диапазона значений. Повторите ввод.\n";
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // <-- Я не знаю зачем эта строка, честно не смог понять. Однако из-за max() я не мог поставить windows.h
	}
}
double Inputfloat(int m, int M) {
	for (;;) {
		float valuea;
		cout << "Введите число. \n";
		if ((cin >> valuea).good() && (m <= valuea) && (valuea <= M)) {
			return valuea;
			break;
		}
		if (cin.fail()) {
			cin.clear();
			cout << "Неверный ввод, повторите. \n";
		}
		else {
			cout << "Число вне допустимого диапазона значений. Повторите ввод. \n";
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

void task2_1() {
	system("cls");
	string command_empty;
	bool isExit = false;
	double coneMinimum = 0;
	double coneMaximum = 2147483647;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Конус----------------\n\n\n\n\n\n\n\n\n\n";

	double Volume, Area, height, radiusOut, radiusIn, forming;

	do {
		/*
		while (true) {
			float localradiusOut;
			cout << "Введите радиус большего основания:" << endl;
			if ((cin >> localradiusOut).good() && (coneMinimum <= localradiusOut) && (localradiusOut <= coneMaximum)) {
				radiusOut = localradiusOut;
				break;
			}

			if (cin.fail()) {
				cin.clear();
				cout << "Неверный ввод, повторите." << endl;
			}
			else {
				cout << "Число вне допустимого диапазона значений. Повторите ввод.\n";
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		*/
		cout << "Введите радиус большего основания:" << endl;
		radiusOut = inputInt(0, 2147483647);

		cout << "Введите радиус меньшего основания:" << endl;
		radiusIn = inputInt(0, 2147483647);
		/*
		while (true) {
			float localradiusIn;
			cout << "Введите радиус меньшего основания:" << endl;
			if ((cin >> localradiusIn).good() && (coneMinimum <= localradiusIn) && (localradiusIn <= coneMaximum)) {
				radiusIn = localradiusIn;
				break;
			}

			if (cin.fail()) {
				cin.clear();
				cout << "Неверный ввод, повторите." << endl;
			}
			else {
				cout << "Число вне допустимого диапазона значений. Повторите ввод.\n";
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		*/
		while (true) {
			float localheight;
			cout << "Введите высоту:" << endl;
			if ((cin >> localheight).good() && (coneMinimum <= localheight) && (localheight <= coneMaximum)) {
				height = localheight;
				break;
			}

			if (cin.fail()) {
				cin.clear();
				cout << "Неверный ввод, повторите." << endl;
			}
			else {
				cout << "Число вне допустимого диапазона значений. Повторите ввод.\n";
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		while (true) {
			float localforming;
			cout << "Введите образующую конуса:" << endl;
			if ((cin >> localforming).good() && (coneMinimum <= localforming) && (localforming <= coneMaximum)) {
				forming = localforming;
				break;
			}

			if (cin.fail()) {
				cin.clear();
				cout << "Неверный ввод, повторите." << endl;
			}
			else {
				cout << "Число вне допустимого диапазона значений. Повторите ввод.\n";
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

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
	} while (!isExit);
}

void task2_2() {
	system("cls");
	string command_empty;
	bool isExit = false;
	double coneMinimum = 0;
	double coneMaximum = 2147483647;

	double w, a, x;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Разветвление----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		while (true) {
			float localParameter;
			cout << "Введите значение параметра a:" << endl;
			if ((cin >> localParameter).good() && (coneMinimum <= localParameter) && (localParameter <= coneMaximum)) {
				a = localParameter;
				break;
			}

			if (cin.fail()) {
				cin.clear();
				cout << "Неверный ввод, повторите." << endl;
			}
			else {
				cout << "Число вне допустимого диапазона значений. Повторите ввод.\n";
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		while (true) {
			float localVariable;
			cout << "Введите значение переменной x:" << endl;
			if ((cin >> localVariable).good() && (coneMinimum <= localVariable) && (localVariable <= coneMaximum)) {
				x = localVariable;
				break;
			}

			if (cin.fail()) {
				cin.clear();
				cout << "Неверный ввод, повторите." << endl;
			}
			else {
				cout << "Число вне допустимого диапазона значений. Повторите ввод.\n";
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		try {
			if (abs(x) <= 0 && a - pow(x, 2) < 0) {
				throw 5001;
			}
			if (abs(x) <= 0) {
				throw 5002;
			}
			if (a - pow(x, 2) < 0) {
				throw 5003;
			}
		}
		catch (int dripperCatcher) {
			if (dripperCatcher == 5001) {
				cout << "Вы вышли за область предела функции (|x| > 0) и (a - x^2 >= 0)";
				break;
			}
			if (dripperCatcher == 5002) {
				cout << "Вы вышли за область предела функции (|x| > 0)";
				break;
			}
			if (dripperCatcher == 5003) {
				cout << "Вы вышли за область предела функции (a - x^2 >= 0)";
				break;
			}
		}

		if (abs(x) < 1) {
			w = a * log(abs(x));
		}
		else if (abs(x) >= 1) {
			w = sqrt(a - pow(x, 2));
		}

		cout << "\n\n\n\n Ответ равен " << w;
		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
	} while (!isExit);
}

void task2_3() {
	system("cls");
	string command_empty;
	bool isExit = false;
	double coneMinimum = 0;
	double coneMaximum = 2147483647;

	double w, a, x;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Функция----------------\n\n\n\n\n\n\n\n\n\n";

	do {

	} while (!isExit);
}

void task2_4() {
	cout << "Мы из антихайпа!!! 4";
}

void task2_5() {
	cout << "Мы из антихайпа!!! 5";
}

int main() {

	// Установим кодировку для входных и выходных данных в консоли.
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Русская локализация.
	setlocale(LC_ALL, "Russian");

	cout << "Домашняя работа №1 Беркунова Степан" << endl;

	int taskNumber;

	while (true) {
		cout << "Для просмотра заданий введите номер задания (1-5)" << endl;
		cout << endl;
		cout << "№1 - задание \"Конус»\"\n";
		cout << "№2 - задание \"Разветвление\"\n";
		cout << "№3 - задание \"Функция\"\n";
		cout << "№4 - задание \"Порядок»\"\n";
		cout << "№5 - задание \"Табуляция\"\n\n";
		cout << "Ввод нуля завершит программу\n\n";

		// Нас интересует проверка, которая будет определять, ввёл ли пользователь число от 1 до 5.
		taskNumber = inputInt(1, 5);

		// Когда пользователь вводит номер задания и соответствующий case реазилуется, после этого работа главной функции не завешается и это может привести к ошибкам.
		// Поэтому сразу как только функция - задание выполнится, будет выход из switch.
		switch (taskNumber) {
		case 1: task2_1(); break;
		case 2: task2_2(); break;
		case 3: task2_3(); break;
		case 4: task2_4(); break;
		case 5: task2_5(); break;
		case 0: exit(0);
		}

		cout << "\n\n\n\n\n----------------Вы вышли в главное меню----------------\n\n\n\n\n" << endl;
	}
}