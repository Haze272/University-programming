#include <iostream>
#include <string>
#define  NOMINMAX // Без этого define происходит кофликт библиотеки Windows.h и max() в функции  inputInt
#include <Windows.h>

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
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

void task1() {
	string yourName;

	cout << "Вывод имени\n";
	cout << "Как вас зовут?\n";
	
	cin >> yourName;
	cout << "Ваше имя - " << yourName << "\n";
}

void task2() {
	float calculateNumberFirst, calculateNumberSecond;
	char calculateOperator;
	// Объявим минимальное и максимальное вводимое значение для последующей проверки
	int calculateMinimum = -2147483648;
	int calculateMaximum = 2147483647;

	while (true) {
		float localNumberFirst;
		cout << "введите значение переменной а" << endl;
		if ((cin >> localNumberFirst).good() && (calculateMinimum <= localNumberFirst) && (localNumberFirst <= calculateMaximum)) {
			calculateNumberFirst = localNumberFirst;
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
	cout << "Вы покинули ментальную тюрьму..\n";
}

void task3() {
	cout << "Замай - бог рэпа3\n";
}

void task4() {
	cout << "Замай - бог рэпа4\n";
}

void task5() {
	cout << "Замай - бог рэпа5\n";
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	setlocale (LC_ALL, "Russian");

	cout << "Домашняя работа №1 Беркунова Степан" << endl;

	int taskNumber;

	while (true) {
		cout << "Для просмотра заданий введите номер задания (1-5)" << endl;
		cout << endl;
		cout << "№1 - задание \"Имя\"\n";
		cout << "№2 - задание \"Арифметика\" \n";
		cout << "№3 - задание \"Уравнение\" \n";
		cout << "№4 - задание \"Ещё уравнение\" \n";
		cout << "№5 - задание \"Лампа со шторой\" \n\n";

		// Нас интересует проверка, которая будет определять, ввёл ли пользователь число от 1 до 5.
		taskNumber = inputInt(1, 5);
		switch (taskNumber) {
			case 1: task1(); break;
			case 2: task2(); break;
			case 3: task3(); break;
			case 4: task4(); break;
			case 5: task5(); break;
		}

		cout << "\nТы вышел из ментальной тюрьмы, ежже\n" << endl;
	}
}