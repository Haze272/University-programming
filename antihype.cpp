//
//
// ��� �������� ������ �� ������������ ����������������
// �������� ������ ��������, ����-15-20
//
//

#include <iostream>
#include <string>
#define  NOMINMAX // ��� ����� define ���������� ������� ���������� Windows.h � max() � ������� inputInt
#include <Windows.h> // ���������� �������� �����/������
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

// ������������� ��������� ���� � �������
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

// ���������� ����������� ����
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

/*-----------------------------------------������� ������� :)g-----------------------------------------*/


int main() {

	// ��������� ��������� ��� ������� � �������� ������ � �������.
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ������� �����������.
	setlocale(LC_ALL, "Russian");
	cout << "�������� ������ �1 ��������� ������" << endl;

	int taskNumber;
	int semanaNumero;

	while (true) {
		khanZamai();
		cout << "������� ����� ������ � �������� �������� (1-4)" << endl;
		cout << endl;
		cout << "�1 - ������ ������\n";
		cout << "�2 - ������ ������\n";
		cout << "�3 - ������ ������\n";
		cout << "�4 - ��������� ������ (� ��������)\n";
		cout << "���� ���� �������� ���������\n\n";

		semanaNumero = inputInt(0, 4);

		bool isExit = false;
		switch (semanaNumero) {
		case 1:
			do {
				khanZamai();
				system("cls");
				cout << "\n\n\n\n\n----------------�� ����� � ������� ����----------------\n\n\n\n\n" << endl;

				cout << "��� ��������� ������� ������� ����� ������� (1-5)" << endl;
				cout << endl;
				cout << "�1 - ������� \"���\"\n";
				cout << "�2 - ������� \"����������\" \n";
				cout << "�3 - ������� \"���������\" \n";
				cout << "�4 - ������� \"��� ���������\" \n";
				cout << "�5 - ������� \"����� �� ������\" \n\n";
				cout << "���� ���� ������ � ���� ������ ������\n\n";

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
				cout << "\n\n\n\n\n----------------�� ����� � ������� ����----------------\n\n\n\n\n" << endl;

				cout << "��� ��������� ������� ������� ����� ������� (1-5)" << endl;
				cout << endl;
				cout << "�1 - ������� \"�����\"\n";
				cout << "�2 - ������� \"������������\"\n";
				cout << "�3 - ������� \"�������\"\n";
				cout << "�4 - ������� \"�������\"\n";
				cout << "�5 - ������� \"���������\"\n\n";
				cout << "���� ���� ������ � ���� ������ ������\n\n";

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
				cout << "\n\n\n\n\n----------------�� ����� � ������� ����----------------\n\n\n\n\n" << endl;

				cout << "��� ��������� ������� ������� ����� ������� (1-5)" << endl;
				cout << endl;
				cout << "�1 - ������� \"����\"\n";
				cout << "�2 - ������� \"�����\"\n";
				cout << "�3 - ������� \"����������� �����\"\n";
				cout << "�4 - ������� \"������\"\n";
				cout << "�5 - ������� \"���������� ����\"\n";
				cout << "���� ���� ������ � ���� ������ ������\n";

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
				cout << "\n\n\n\n\n----------------�� ����� � ������� ����----------------\n\n\n\n\n" << endl;

				cout << "��� ��������� ������� ������� ����� ������� (1-5)" << endl;
				cout << endl;
				cout << "�1 - ������� \"����\"\n";
				cout << "�2 - ������� \"���� �����\" \n";
				cout << "�3 - ������� \"�������������� ������\" \n";
				cout << "�4 - ������� \"����� �����\" \n";
				cout << "�5 - ������� \"���������\"\n";
				cout << "�6 - ������� \"���������� ��������������\"\n";
				cout << "�7 - ������� \"��������� ��������� �����\"\n";
				cout << "���� ���� ������ � ���� ������ ������\n";

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