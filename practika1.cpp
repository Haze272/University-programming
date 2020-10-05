//
//
// Самостоятельная работа
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


/*-----------------------------------------Раздел с вспомогательными функциям-----------------------------------------*/


int inputInt(int m, int M) {
	for (;;) {
		int valueChecking;
		if ((cin >> valueChecking).good() && (m <= valueChecking) && (valueChecking <= M) && (floor(valueChecking) == valueChecking)) {
			return valueChecking;
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

float inputFloat(int m, int M) {
	for (;;) {
		float valuea;
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

/*-----------------------------------------Раздел с заданиями-----------------------------------------*/

void trabajo1() {
	string command_empty;
	bool isExit = false;

	int N;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Целое число N----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "Введите число N\n";

		N = inputInt(-2147483647, 2147483647);

		if (N <= 0) {
			cout << "Число " << N << " не положительное, ";
		}
		else {
			cout << "Число " << N << " положительное, ";
		}

		if (N % 2 == 1) {
			cout << " нечётное, ";
		}
		else {
			cout << " чётное, ";
		}

		if (N > -3) {
			cout << " число превосходит -3.\n";
		}
		else {
			cout << " число не превосходит -3.\n"; 
		}

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void trabajo2() {
	string command_empty;
	bool isExit = false;

	float x, resulto;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Функция----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "Введите значение переменной x\n";

		x = inputFloat(-2147483647, 2147483647);

		try {
			if (abs(x - 1) <= 0) {
				throw 1488;
			}
		}
		catch (int dripCatcher) {
			if (dripCatcher == 1488) {
				cout << "Вы вышли за область допустимых значений! (|x - 1| > 0)";

				cout << "\nПродолжим? Напишите всё что угодно\n";
				cin >> command_empty;
				break;
			}
		}

		if (x < 0) {
			resulto = abs(x + 1);
			cout << "Функция равна " << resulto << endl;
		}
		else if (x > 0) {
			resulto = log(abs(x - 1));
			cout << "Функция равна " << resulto << endl;
		}
		else if (x == 0) {
			resulto = sqrt(9 - x) / 3;
			cout << "Функция равна " << resulto << endl;
		}

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void trabajo3() {
	string command_empty;
	bool isExit = false;


	cout << "\n\n\n\n\n\n\n\n\n\n----------------Остаток----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		for (int i = 35; i <= 87; i++) {
			if (i % 7 == 1 || i % 7 == 2 || i % 7 == 5) {
				cout << i << endl;
			}
		}
		

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}
	

void trabajo4() {
	string command_empty;
	bool isExit = false;

	float tabel, resulto;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Табуляция----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "Введите число для табулирования функции\n";
		tabel = inputFloat(-2147483647, 2147483647);
		cout << endl;
		tabel -= 5;
		int counter = 1;

		for (int i = 0; i < 21; i++) {
			cout << counter << ") ";
			if (!(abs(tabel) + 1 <= 0)) {
				resulto = (pow(tabel, 2) + tabel + 1) * log(abs(tabel) + 1);
				cout << "Результат для x = " << tabel << "равен: " << resulto << endl << endl;
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

long double fact(int N)
{
	if (N == 0) // если пользователь ввел ноль,
		return 1; // возвращаем факториал от нуля - 1
	else // Во всех остальных случаях
		return N * fact(N - 1); // делаем рекурсию.
}

void trabajo5() {
	string command_empty;
	bool isExit = false;

	int facto, resulto;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Факториал----------------\n\n\n\n\n\n\n\n\n\n";

	do {

		cout << "Введите число для вычисления факториала\n";
		facto = inputInt(0, 2147483647);

		cout << "Факториал для числа " << facto << " = " << fact(facto) << endl << endl;
		

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, Y если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "Y") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

/*-----------------------------------------Раздел с главной функцией-----------------------------------------*/

int main() {
	// Установим кодировку для входных и выходных данных в консоли.
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Русская локализация.
	setlocale(LC_ALL, "Russian");

	cout << "Домашняя работа №1 Беркунова Степан" << endl;

	int numeroDeTrabajo;

	while (true) {
		cout << "Введите номер недели с домашним заданием (1-2)" << endl;
		cout << endl;
		cout << "№1 - Целое число N\n";
		cout << "№2 - Функция\n";
		cout << "№3 - Остаток\n";
		cout << "№4 - Табуляция\n";
		cout << "№5 - Факториал\n";
		cout << "Ввод нуля завершит программу\n\n";

		numeroDeTrabajo = inputInt(0, 5);
		system("cls");

		bool isExit = false;
		switch (numeroDeTrabajo) {
		case 1: trabajo1(); break;
		case 2: trabajo2(); break;
		case 3: trabajo3(); break;
		case 4: trabajo4(); break;
		case 5: trabajo5(); break;
		case 0: exit(0); break;
		}
	}
}
