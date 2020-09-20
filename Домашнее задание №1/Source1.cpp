#include <iostream>
#include <string>
#define  NOMINMAX // ��� ����� define ���������� ������� ���������� Windows.h � max() � �������  inputInt
#include <Windows.h>

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
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

void task1() {
	string yourName;

	cout << "����� �����\n";
	cout << "��� ��� �����?\n";
	
	cin >> yourName;
	cout << "���� ��� - " << yourName << "\n";
}

void task2() {
	float calculateNumberFirst, calculateNumberSecond;
	char calculateOperator;
	// ������� ����������� � ������������ �������� �������� ��� ����������� ��������
	int calculateMinimum = -2147483648;
	int calculateMaximum = 2147483647;

	while (true) {
		float localNumberFirst;
		cout << "������� �������� ���������� �" << endl;
		if ((cin >> localNumberFirst).good() && (calculateMinimum <= localNumberFirst) && (localNumberFirst <= calculateMaximum)) {
			calculateNumberFirst = localNumberFirst;
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
	cout << "�� �������� ���������� ������..\n";
}

void task3() {
	cout << "����� - ��� ����3\n";
}

void task4() {
	cout << "����� - ��� ����4\n";
}

void task5() {
	cout << "����� - ��� ����5\n";
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	setlocale (LC_ALL, "Russian");

	cout << "�������� ������ �1 ��������� ������" << endl;

	int taskNumber;

	while (true) {
		cout << "��� ��������� ������� ������� ����� ������� (1-5)" << endl;
		cout << endl;
		cout << "�1 - ������� \"���\"\n";
		cout << "�2 - ������� \"����������\" \n";
		cout << "�3 - ������� \"���������\" \n";
		cout << "�4 - ������� \"��� ���������\" \n";
		cout << "�5 - ������� \"����� �� ������\" \n\n";

		// ��� ���������� ��������, ������� ����� ����������, ��� �� ������������ ����� �� 1 �� 5.
		taskNumber = inputInt(1, 5);
		switch (taskNumber) {
			case 1: task1(); break;
			case 2: task2(); break;
			case 3: task3(); break;
			case 4: task4(); break;
			case 5: task5(); break;
		}

		cout << "\n�� ����� �� ���������� ������, ����\n" << endl;
	}
}