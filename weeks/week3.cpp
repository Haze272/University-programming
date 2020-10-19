#include "../helpFunc/helpFunctions.h"
#include "weeks.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void khanZamai();

/*-----------------------------------------������ ������-----------------------------------------*/

void task3_1() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;

	float Sum, r, percent, mouthPay;
	int years;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------����----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "������� ����� �����\n";
		Sum = inputFloat(0, 2147483647);
		cout << endl;

		cout << "������� �������� �������� � %: (0 - 100)\n";
		percent = inputFloat(0, 100);
		cout << endl;

		r = percent / 100;

		cout << "������� ���������� ���\n";
		years = inputInt(0, 2147);
		cout << endl;

		try {
			if (pow((1 + r), years) == 1) {
				throw 6001;
			}
		}
		catch (int antihypeCatcher) {
			if (antihypeCatcher == 6001) {
				cout << "������ ������ �� ����! (12 ((1+r)n?1)) != 0)\n";

				cout << "\n���������? �������� �� ��� ������\n";
				cin >> command_empty;
				break;
			}
		}

		mouthPay = (Sum * r * pow(1 + r, years)) / (12 * (pow(1 + r, years) - 1));
		cout << "\n�������� ������� ����� " << mouthPay << endl;

		cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void task3_2() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;

	float Sum, r, percent, mouthPay;
	int years;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------�����----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "����i�� ���� ������\n";
		Sum = inputFloat(0, 2147483647);
		cout << endl;

		cout << "����i�� �ic���� �������!\n";
		mouthPay = inputFloat(0, 2147483647);
		cout << endl;

		cout << "����i�� �i���i��� ���i�\n";
		years = inputInt(0, 2147483647);
		cout << endl;
		years *= 12;

		percent = (((mouthPay * years) / Sum) - 1) * 100;
		cout << percent << " - �� �i������\n";

		cout << "\n����������? �����i�� ��� �� �������� ��� �����������, !exit ���� ������ ����� � ��������\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void task3_3() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;

	// string escritor_boofer;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------����������� �����----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		/*
		string damnbuff;
		ofstream file_escritor("mybenben.txt");
		cout << "������� ����� ��� ������ � ��������� ���� ������������ ����� �������� - 64\n";
		getline(cin, damnbuff);
		file_escritor << damnbuff << endl;
		file_escritor.close();
		*/
		string damnbuff;

		cout << "������� ����� ��������� ����� enter, ���� ���� ������� �����.\n";

		bool isExit2 = false;
		ofstream out("govno.txt");
		do {
			getline(cin, damnbuff);
			if (damnbuff == "0") {
				isExit2 = true;
				out.close();
				system("cls");
			}
			else {
				out << damnbuff << " ";
			}
		} while (!isExit2);

		cout << "���� ��� ������� ������!\n" << "��� ����������:\n\n";

		char buff[64]; // ����� �������������� �������� ������������ �� ����� ������
		ifstream file_lector("govno.txt"); // ������� ���� ��� ������

		file_lector.getline(buff, 64); // ������� ������ �� �����
		file_lector.close(); // ��������� ����
		cout << buff << endl; // ���������� ��� ������

		cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void task3_4() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------������----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		ifstream file_lector("govno.txt");
		int b;

		do
		{
			// ������� ������� �����
			if (file_lector >> b)
			{
				// ���� ������� ����� - �������
				cout << b << endl;
			}
			else
			{
				// ���� ������� �� �����, ������� ������
				file_lector.clear();
				// ���������� ������� �� ���������� �������
				file_lector.ignore(1, ' ');
			}
		} while (!file_lector.eof()); // eof() - �������, ������������ ����������� �� ������ � ���������

		cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			file_lector.close();
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void task3_5() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------���������� ����----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		bool q = true;
		do {
			char s[80];
			cout << ("������� ������ ������� � 30 ��������: \n");
			cin >> s;
			unsigned long i = strlen(s);
			if (i == 30) {
				q = false;
				antihypeSort(s, i);
				cout << ("��������������� ������ : %s\n", s);
				break;

			}
			cout << "�� ����� ������ ������� �� 30 ��������! \n";
		} while (q);

		cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}