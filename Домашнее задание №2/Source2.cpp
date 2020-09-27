//
//
// �������� ������ �2 �� ������������ ����������������
// �������� ������ ��������, ����-15-20
//
//

#include <iostream>
#include <string>
#define  NOMINMAX // ��� ����� define ���������� ������� ���������� Windows.h � max() � ������� inputInt
#include <Windows.h> // ���������� �������� �����/������
#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;

int inputInt(int m, int M) {
	for (;;) {
		int valueChecking;
		if ((cin >> valueChecking).good() && (m <= valueChecking) && (valueChecking <= M) && (floor(valueChecking) == valueChecking)) {
			return valueChecking;
			break;
		}
		if (cin.fail()) {
			cin.clear();
			cout << "�������� ����, ���������. \n";
		}
		else {
			cout << "����� ��� ����������� ��������� ��������. ��������� ����. \n";
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

double inputDouble(int m, int M) {
	for (;;) {
		double valuea;
		if ((cin >> valuea).good() && (m <= valuea) && (valuea <= M)) {
			return valuea;
			break;
		}
		if (cin.fail()) {
			cin.clear();
			cout << "�������� ����, ���������. \n";
		}
		else {
			cout << "����� ��� ����������� ��������� ��������. ��������� ����. \n";
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

void task2_1() {
	system("cls");
	string command_empty;
	bool isExit = false;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------�����----------------\n\n\n\n\n\n\n\n\n\n";

	double Volume, Area, height, radiusOut, radiusIn, forming;

	do {
		cout << "������� ������ �������� ���������:\n";
		radiusOut = inputDouble(0, 2147483647);

		cout << "������� ������ �������� ���������:\n";
		radiusIn = inputDouble(0, 2147483647);

		cout << "������� ������:\n";
		height = inputDouble(0, 2147483647);

		cout << "������� ���������� ������:\n";
		forming = inputDouble(0, 2147483647);

		system("cls");

		Volume = M_PI / 3 * height * (pow(radiusOut, 2) + radiusOut * radiusIn + pow(radiusIn, 2));
		cout << "����� ������ ���������� ������ ����� " << Volume << endl;

		Area = M_PI * (pow(radiusOut, 2) + forming * (radiusOut + radiusIn) + pow(radiusIn, 2));
		cout << "������� ������ ���������� ������ ����� " << Area << endl;

		cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
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

	double w, a, x;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------������������----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "������� �������� ��������� a:" << endl;
		a = inputDouble(-2147483648, 2147483647);

		cout << "������� �������� ���������� x:" << endl;
		x = inputDouble(-2147483648, 2147483647);

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
				cout << "�� ����� �� ������� ������� ������� (|x| > 0) � (a - x^2 >= 0)";
				break;
			}
			if (dripperCatcher == 5202) {
				cout << "�� ����� �� ������� ������� ������� (|x| > 0)";
				break;
			}
			if (dripperCatcher == 5203) {
				cout << "�� ����� �� ������� ������� ������� (a - x^2 >= 0)";
				break;
			}
		}

		if (abs(x) < 1) {
			w = a * log(abs(x));
		}
		else if (abs(x) >= 1) {
			w = sqrt(a - pow(x, 2));
		}
		cout << "\n\n\n\n����� ����� " << w;

		cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
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

	double z, b, x, y;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------�������----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "������� �������� ��������� b:" << endl;
		b = inputDouble(-2147483648, 2147483647);

		cout << "������� �������� ���������� x:" << endl;
		x = inputDouble(-2147483648, 2147483647);

		cout << "������� �������� ���������� y:" << endl;
		y = inputDouble(-2147483648, 2147483647);

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
				cout << "�� ����� �� ������� ������� ������� (b - y > 0) � (b - x >= 0)";
				break;
			}
			if (dripperCatcher == 5302) {
				cout << "�� ����� �� ������� ������� ������� (b - y > 0)";
				break;
			}
			if (dripperCatcher == 5303) {
				cout << "�� ����� �� ������� ������� ������� (b - x >= 0)";
				break;
			}
		}

		z = log(b - y) * sqrt(b - x);
		cout << "\n\n\n\n������� ����� " << z;

		cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
	} while (!isExit);
}

void task2_4() {
	system("cls");
	string command_empty;
	bool isExit = false;

	int order;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------�������----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "������� �����, ��� �������� ��������� ����������� 10\n";

		order = inputInt(0, 2147483647);
		cout << "������������������ �����:\n";
		for (int i = 10; i > 0; i--) {
			order++;
			cout << order << endl;
		}

		cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
	} while (!isExit);
}

void task2_5() {
	system("cls");
	string command_empty;
	bool isExit = false;

	double tabel, result;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------���������----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "������� ����� ��� ������������� �������\n";
		tabel = inputDouble(-2147483648, 2147483647);
		cout << endl;
		tabel -= 4;
		int counter = 1;

		for (int i = 0; i < 17; i++) {
			cout << counter << ") ";
			if (tabel - 1 != 0) {
				result = (pow(tabel, 2) - 2 * tabel + 2) / (tabel - 1);
				cout << "��������� ��� x = " << tabel << "�����: " << result << endl << endl;
			}
			try {
				if (tabel - 1 == 0) {
					throw 5501;
				}
			}
			catch (int q) {
				cout << "��������� ��� x = 1\n" << "������, �� 0 ������ ������ (x - 1 != 0)" << endl << endl;
			}
			tabel += 0.5;
			counter++;
		}

		cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
	} while (!isExit);
}

int main() {

	// ��������� ��������� ��� ������� � �������� ������ � �������.
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// ������� �����������.
	setlocale(LC_ALL, "Russian");

	cout << "�������� ������ �1 ��������� ������" << endl;

	int taskNumber;

	while (true) {
		cout << "��� ��������� ������� ������� ����� ������� (1-5)" << endl;
		cout << endl;
		cout << "�1 - ������� \"�����\"\n";
		cout << "�2 - ������� \"������������\"\n";
		cout << "�3 - ������� \"�������\"\n";
		cout << "�4 - ������� \"�������\"\n";
		cout << "�5 - ������� \"���������\"\n\n";
		cout << "���� ���� �������� ���������\n\n";

		// ��� ���������� ��������, ������� ����� ����������, ��� �� ������������ ����� �� 1 �� 5.
		taskNumber = inputInt(0, 5);

		// ����� ������������ ������ ����� ������� � ��������������� case �����������, ����� ����� ������ ������� ������� �� ���������� � ��� ����� �������� � �������.
		// ������� ����� ��� ������ ������� - ������� ����������, ����� ����� �� switch.
		switch (taskNumber) {
		case 1: task2_1(); break;
		case 2: task2_2(); break;
		case 3: task2_3(); break;
		case 4: task2_4(); break;
		case 5: task2_5(); break;
		case 0: exit(0);
		}

		cout << "\n\n\n\n\n----------------�� ����� � ������� ����----------------\n\n\n\n\n" << endl;
	}
}