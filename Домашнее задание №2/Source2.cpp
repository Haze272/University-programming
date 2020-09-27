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

void task2_1() {
	string command_empty;
	bool isExit = false;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------����� �����----------------\n\n\n\n\n\n\n\n\n\n";

	cout << "�� �� ���������!!! 1";
}

void task2_2() {
	cout << "�� �� ���������!!! 2";
}

void task2_3() {
	cout << "�� �� ���������!!! 3";
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