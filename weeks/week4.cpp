#include "../helpFunc/helpFunctions.h"
#include "weeks.h"
#include <iostream>
#include <string>
#define  NOMINMAX // ��� ����� define ���������� ������� ���������� Windows.h � max() � ������� inputInt
#include <Windows.h> // ���������� �������� �����/������
#include <cmath>
#define M_PI 3.14159265358979323846
#include <fstream>

using namespace std;
void khanZamai();

/*-----------------------------------------�������� ������-----------------------------------------*/

void task4_1() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;
	float Zamai, Sum;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------����----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		Sum = 0;

		cout << "������� 10 ����� ��������� ����� enter\n";
		ofstream damnson("fifa202n.txt");

		for (int i = 0; i < 10; i++) {
			Zamai = inputFloat(-2147483647, 2147483647);
			damnson << Zamai << endl;
		}
		damnson.close();


		cout << "���� ��� ������� ������!\n\n";

		ifstream file_leer("fifa202n.txt");
		int b;

		do
		{
			// ������� ������� �����
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

		cout << "����� ����� � ����� �����: " << Sum << endl;

		cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
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

	cout << "\n\n\n\n\n\n\n\n\n\n----------------���� �����----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "������� �����\n";
		numero = inputFloat(-2147483647, 2147483647);

		if (sign(numero) == 1)
			cout << "����� " << numero << " - �������������.";
		else if (sign(numero) == 0)
			cout << "����� " << numero << " - �� ������������� � �� �������������.";
		else if (sign(numero) == -1)
			cout << "����� " << numero << " - �������������.";

		cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
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

	cout << "\n\n\n\n\n\n\n\n\n\n----------------�������������� ������----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "�������� ����� ������ ���������� ������?\n";
		cout << "1 - �������������\n";
		cout << "2 - �����������\n";
		cout << "3 - ����������\n";
		choice = inputInt(1, 3);

		switch (choice) {
		case 1:
			cout << "������� ������ ������� ��������������\n";
			rect1 = inputFloat(0, 2147483647);
			cout << "������� ������ ������� ��������������\n";
			rect2 = inputFloat(0, 2147483647);

			area = areaDeRectangulo(rect1, rect2);
			cout << "������� �������������� ����� " << area << endl;
			break;
		case 2:
			cout << "������� ������ ������� ������������\n";
			tri1 = inputFloat(0, 2147483647);
			cout << "������� ������ ������� ������������\n";
			tri2 = inputFloat(0, 2147483647);
			cout << "������� ������ ������� ������������\n";
			tri3 = inputFloat(0, 2147483647);

			area = areaDeTriangulo(tri1, tri2, tri3);
			cout << "������� ������������ ����� " << area << endl;
			break;
		case 3:
			cout << "������� ������ ����������\n";
			radius = inputFloat(0, 2147483647);

			area = areaDeCirculo(radius);
			cout << "������� ���������� ����� " << area << endl;
			break;
		}


		cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
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

	cout << "\n\n\n\n\n\n\n\n\n\n----------------����� �����----------------\n\n\n\n\n\n\n\n\n\n";

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



		cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
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

	cout << "\n\n\n\n\n\n\n\n\n\n----------------���������----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "C'est govno, Marie.. \n";



		cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}