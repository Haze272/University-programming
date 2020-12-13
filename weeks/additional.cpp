#include "../helpFunc/helpFunctions.h"
#include "weeks.h"
#include <iostream>
#include <string>
#define  NOMINMAX // ��� ����� define ���������� ������� ���������� Windows.h � max() � ������� inputInt
#include <Windows.h> // ���������� �������� �����/������
#include <cmath>
#define M_PI 3.14159265358979323846
#include <fstream>
#include <algorithm>
#include <iomanip>      // std::setw
#include <vector>

using namespace std;
void khanZamai();

/*-----------------------------------------�������������� �������-----------------------------------------*/

void spinner() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;

	float a, b, c;
	int N;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------�������----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		
		cout << "������� ������ ��������" << endl;
		a = inputFloat(-2147483647, 2147483647);
		cout << "������� ������ ��������" << endl;
		b = inputFloat(-2147483647, 2147483647);
		cout << "������� ������ ��������" << endl;
		c = inputFloat(-2147483647, 2147483647);

		N = (c - a) / b;
		cout << "���������� �������� � �������� " << N << endl;


		cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}