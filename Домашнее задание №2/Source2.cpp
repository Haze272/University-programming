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

int inputInt(int m = INT_MIN, int M = INT_MAX)
{
	int N;
	for (;;) {
		if ((cin >> N).good() && (m <= N) && (N <= M)) return N;

		if (cin.fail()) {
			cin.clear();
			cout << "�������� ����, ���������." << endl;
		}
		else {
			cout << "����� ��� ����������� ��������� ��������. ��������� ����.\n";
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // <-- � �� ���� ����� ��� ������, ������ �� ���� ������. ������ ��-�� max() � �� ��� ��������� windows.h
	}
}
double Inputfloat(int m, int M) {
	for (;;) {
		float valuea;
		cout << "������� �����. \n";
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
	double coneMinimum = 0;
	double coneMaximum = 2147483647;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------�����----------------\n\n\n\n\n\n\n\n\n\n";

	double Volume, Area, height, radiusOut, radiusIn, forming;

	do {
		/*
		while (true) {
			float localradiusOut;
			cout << "������� ������ �������� ���������:" << endl;
			if ((cin >> localradiusOut).good() && (coneMinimum <= localradiusOut) && (localradiusOut <= coneMaximum)) {
				radiusOut = localradiusOut;
				break;
			}

			if (cin.fail()) {
				cin.clear();
				cout << "�������� ����, ���������." << endl;
			}
			else {
				cout << "����� ��� ����������� ��������� ��������. ��������� ����.\n";
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		*/
		cout << "������� ������ �������� ���������:" << endl;
		radiusOut = inputInt(0, 2147483647);

		cout << "������� ������ �������� ���������:" << endl;
		radiusIn = inputInt(0, 2147483647);
		/*
		while (true) {
			float localradiusIn;
			cout << "������� ������ �������� ���������:" << endl;
			if ((cin >> localradiusIn).good() && (coneMinimum <= localradiusIn) && (localradiusIn <= coneMaximum)) {
				radiusIn = localradiusIn;
				break;
			}

			if (cin.fail()) {
				cin.clear();
				cout << "�������� ����, ���������." << endl;
			}
			else {
				cout << "����� ��� ����������� ��������� ��������. ��������� ����.\n";
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		*/
		while (true) {
			float localheight;
			cout << "������� ������:" << endl;
			if ((cin >> localheight).good() && (coneMinimum <= localheight) && (localheight <= coneMaximum)) {
				height = localheight;
				break;
			}

			if (cin.fail()) {
				cin.clear();
				cout << "�������� ����, ���������." << endl;
			}
			else {
				cout << "����� ��� ����������� ��������� ��������. ��������� ����.\n";
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		while (true) {
			float localforming;
			cout << "������� ���������� ������:" << endl;
			if ((cin >> localforming).good() && (coneMinimum <= localforming) && (localforming <= coneMaximum)) {
				forming = localforming;
				break;
			}

			if (cin.fail()) {
				cin.clear();
				cout << "�������� ����, ���������." << endl;
			}
			else {
				cout << "����� ��� ����������� ��������� ��������. ��������� ����.\n";
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

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
	double coneMinimum = 0;
	double coneMaximum = 2147483647;

	double w, a, x;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------������������----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		while (true) {
			float localParameter;
			cout << "������� �������� ��������� a:" << endl;
			if ((cin >> localParameter).good() && (coneMinimum <= localParameter) && (localParameter <= coneMaximum)) {
				a = localParameter;
				break;
			}

			if (cin.fail()) {
				cin.clear();
				cout << "�������� ����, ���������." << endl;
			}
			else {
				cout << "����� ��� ����������� ��������� ��������. ��������� ����.\n";
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		while (true) {
			float localVariable;
			cout << "������� �������� ���������� x:" << endl;
			if ((cin >> localVariable).good() && (coneMinimum <= localVariable) && (localVariable <= coneMaximum)) {
				x = localVariable;
				break;
			}

			if (cin.fail()) {
				cin.clear();
				cout << "�������� ����, ���������." << endl;
			}
			else {
				cout << "����� ��� ����������� ��������� ��������. ��������� ����.\n";
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
				cout << "�� ����� �� ������� ������� ������� (|x| > 0) � (a - x^2 >= 0)";
				break;
			}
			if (dripperCatcher == 5002) {
				cout << "�� ����� �� ������� ������� ������� (|x| > 0)";
				break;
			}
			if (dripperCatcher == 5003) {
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

		cout << "\n\n\n\n ����� ����� " << w;
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
	double coneMinimum = 0;
	double coneMaximum = 2147483647;

	double w, a, x;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------�������----------------\n\n\n\n\n\n\n\n\n\n";

	do {

	} while (!isExit);
}

void task2_4() {
	cout << "�� �� ���������!!! 4";
}

void task2_5() {
	cout << "�� �� ���������!!! 5";
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
		taskNumber = inputInt(1, 5);

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