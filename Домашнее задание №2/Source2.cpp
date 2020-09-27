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

void task2_1() {
	string command_empty;
	bool isExit = false;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Вывод имени----------------\n\n\n\n\n\n\n\n\n\n";

	cout << "Мы из антихайпа!!! 1";
}

void task2_2() {
	cout << "Мы из антихайпа!!! 2";
}

void task2_3() {
	cout << "Мы из антихайпа!!! 3";
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