//
//
// Все домашние работы по процедурному программированию
// Беркунов Степан Игоревич, ИНБО-15-20
//
//

#include <iostream>
#include <string>
#define  NOMINMAX // Без этого define происходит кофликт библиотеки Windows.h и max() в функции inputInt
#include <Windows.h> // Реализация русского ввода/вывода
#include <cmath>
#define M_PI 3.14159265358979323846
#include <fstream>

#include "helpFunc/helpFunctions.h"
#include "weeks/weeks.h"

using namespace std;

enum Color : int
{
	BLACK = 0,
	RED = 1,
	GREEN = 2,
	BROWN = 3,
	BLUE = 4,
	MAGENTA = 5,
	CYAN = 6,
	GREY = 7,
	YELLOW = 8,
	LRED = 9,
	LGREEN = 10,
	LBLUE = 11,
	LMAGENTA = 12,
	LCYAN = 13,
	WHITE = 14
};

const int ColorCount = static_cast<int>(WHITE) + 1;

// Устанавливает указанный цвет в консоли
void SetColorConsole(Color color)
{
	static WORD WinColorFG[ColorCount] =
	{
		0,                                                                         // BLACK
		FOREGROUND_RED,                                                            // RED
		FOREGROUND_GREEN,                                                          // GREEN
		FOREGROUND_RED | FOREGROUND_GREEN,                                         // BROWN
		FOREGROUND_BLUE,                                                           // BLUE
		FOREGROUND_RED | FOREGROUND_BLUE,                                          // MAGENTA
		FOREGROUND_GREEN | FOREGROUND_BLUE,                                        // CYAN
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,                       // WHITE
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,                  // YELLOW
		FOREGROUND_RED | FOREGROUND_INTENSITY,                                     // RED_BOLD
		FOREGROUND_GREEN | FOREGROUND_INTENSITY,                                   // GREEN_BOLD
		FOREGROUND_BLUE | FOREGROUND_INTENSITY,                                    // BLUE_BOLD
		FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,                   // MAGENTA_BOLD
		FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,                 // CYAN_BOLD
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY // WHITE_BOLD
	};

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, WinColorFG[color]);
}

// Использует стандартный цвет
void ResetColorConsole()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}


Color colours[15] = {
	BLACK, RED, GREEN,
	BROWN, BLUE, MAGENTA,
	CYAN, GREY, YELLOW, LRED,
	LGREEN, LBLUE, LMAGENTA, LCYAN,
	WHITE
};

void khanZamai() {
	int randCol = (rand() % 14) + 1;
	Color govnishe = colours[randCol];
	SetColorConsole(govnishe);
}

/*-----------------------------------------Главная функция :)g-----------------------------------------*/


int main() {

	// Установим кодировку для входных и выходных данных в консоли.
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Русская локализация.
	setlocale(LC_ALL, "Russian");
	cout << "Домашняя работа №1 Беркунова Степан" << endl;

	int taskNumber;
	int semanaNumero;

	while (true) {
		khanZamai();
		cout << "Введите номер недели с домашним заданием (1-4)" << endl;
		cout << endl;
		cout << "№1 - Первая неделя\n";
		cout << "№2 - Вторая неделя\n";
		cout << "№3 - Третья неделя\n";
		cout << "№4 - Четвертая неделя (В процессе)\n";
		cout << "Ввод нуля завершит программу\n\n";

		semanaNumero = inputInt(0, 4);

		bool isExit = false;
		switch (semanaNumero) {
		case 1:
			do {
				khanZamai();
				system("cls");
				cout << "\n\n\n\n\n----------------Вы вышли в главное меню----------------\n\n\n\n\n" << endl;

				cout << "Для просмотра заданий введите номер задания (1-5)" << endl;
				cout << endl;
				cout << "№1 - задание \"Имя\"\n";
				cout << "№2 - задание \"Арифметика\" \n";
				cout << "№3 - задание \"Уравнение\" \n";
				cout << "№4 - задание \"Ещё уравнение\" \n";
				cout << "№5 - задание \"Лампа со шторой\" \n\n";
				cout << "Ввод нуля выйдет в меню выбора недели\n\n";

				taskNumber = inputInt(0, 5);
				system("cls");

				switch (taskNumber) {
				case 1: task1_1(); break;
				case 2: task1_2(); break;
				case 3: task1_3(); break;
				case 4: task1_4(); break;
				case 5: task1_5(); break;
				case 0: isExit = 1;
				}
				system("cls");
			} while (!isExit);

			break;
		case 2:
			do {
				khanZamai();
				system("cls");
				cout << "\n\n\n\n\n----------------Вы вышли в главное меню----------------\n\n\n\n\n" << endl;

				cout << "Для просмотра заданий введите номер задания (1-5)" << endl;
				cout << endl;
				cout << "№1 - задание \"Конус\"\n";
				cout << "№2 - задание \"Разветвление\"\n";
				cout << "№3 - задание \"Функция\"\n";
				cout << "№4 - задание \"Порядок\"\n";
				cout << "№5 - задание \"Табуляция\"\n\n";
				cout << "Ввод нуля выйдет в меню выбора недели\n\n";

				taskNumber = inputInt(0, 5);
				system("cls");

				switch (taskNumber) {
				case 1: task2_1(); break;
				case 2: task2_2(); break;
				case 3: task2_3(); break;
				case 4: task2_4(); break;
				case 5: task2_5(); break;
				case 0: isExit = 1;
				}

				system("cls");
			} while (!isExit);

			break;
		case 3:
			do {
				khanZamai();
				system("cls");
				cout << "\n\n\n\n\n----------------Вы вышли в главное меню----------------\n\n\n\n\n" << endl;

				cout << "Для просмотра заданий введите номер задания (1-5)" << endl;
				cout << endl;
				cout << "№1 - задание \"Заем\"\n";
				cout << "№2 - задание \"Ссуда\"\n";
				cout << "№3 - задание \"Копирование файла\"\n";
				cout << "№4 - задание \"Фильтр\"\n";
				cout << "№5 - задание \"Сортировка букв\"\n";
				cout << "Ввод нуля выйдет в меню выбора недели\n";

				taskNumber = inputInt(0, 5);
				system("cls");

				switch (taskNumber) {
				case 1: task3_1(); break;
				case 2: task3_2(); break;
				case 3: task3_3(); break;
				case 4: task3_4(); break;
				case 5: task3_5(); break;
				case 0: isExit = 1;
				}

				system("cls");
			} while (!isExit);

			break;
		case 4:
			do {
				khanZamai();
				system("cls");
				cout << "\n\n\n\n\n----------------Вы вышли в главное меню----------------\n\n\n\n\n" << endl;

				cout << "Для просмотра заданий введите номер задания (1-5)" << endl;
				cout << endl;
				cout << "№1 - задание \"Файл\"\n";
				cout << "№2 - задание \"Знак числа\" \n";
				cout << "№3 - задание \"Геометрические фигуры\" \n";
				cout << "№4 - задание \"Былая слава\" \n";
				cout << "№5 - задание \"Синусоида\"\n";
				cout << "№6 - задание \"Автоматный распознаватель\"\n";
				cout << "№7 - задание \"Генератор случайных чисел\"\n";
				cout << "Ввод нуля выйдет в меню выбора недели\n";

				taskNumber = inputInt(0, 8);
				system("cls");

				switch (taskNumber) {
				case 1: task4_1(); break;
				case 2: task4_2(); break;
				case 3: task4_3(); break;
				case 4: task4_4(); break;
				case 5: task4_5(); break;
				case 6: task4_6(); break;
				case 7: task4_7(); break;
				case 8: task4_8(); break;
				case 0: isExit = 1;
				}
				system("cls");
			} while (!isExit);

			break;
		case 0: exit(0); break;
		}
	}
}