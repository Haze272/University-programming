#include "../helpFunc/helpFunctions.h"
#include "weeks.h"
#include <iostream>

using namespace std;
void khanZamai();

/*-----------------------------------------������ ������-----------------------------------------*/

void task1_1() {
	khanZamai();
	string yourName;
	string command_empty;
	bool isExit = false;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------����� �����----------------\n\n\n\n\n\n\n\n\n\n";

	// ����� do ���������� �������� ������ � ���������.
	// ������������, ������� ���������, ����� ������� �������� �� ��� � ��������� ���� ������� � ������� ����.
	// ���������� - �������� � ����������, ��� try/catch ����� ����� ������� ��� ������� �� ����, ������� � ��������� ��������� ���.

	do {
		cout << "��� ��� �����?\n";

		cin >> yourName;
		cout << "���� ��� - " << yourName << "\n";

		cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void task1_2() {
	khanZamai();
	system("cls");
	double calculateNumberFirst, calculateNumberSecond, calculateResult;
	char calculateOperator;

	bool isExit = false;
	string command_empty;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------����������----------------\n\n\n\n\n\n\n\n\n\n";
	do {
		cout << "������� �������� ���������� �" << endl;
		calculateNumberFirst = inputDouble(-2147483647, 2147483647);

		cout << "������� �������� ���������� b" << endl;
		calculateNumberSecond = inputDouble(-2147483647, 2147483647);

		cout << "������� ��������, ������� �� ������ ��������� � ��������� �����������\n";
		cout << "\"+\" - ��������\n" << "\"-\" - ���������\n" << "\"*\" - ���������\n" << "\"/\" - �������\n";

		// ��� ���� ������ ��� �� ����� ��������. �� ���� ��� ��������� ��� �������.
		// ������������ �����, ������� � �������, ��� ��, ��� ����� ���� char ��������� � �������������� ��������� �����
		// ������� ���, ������� �������� ������������ � ����� �������������.

		while (true) {
			char localOperator;
			cout << "������� ����" << endl;
			if ((cin >> localOperator).good() && ((localOperator == '+') || (localOperator == '-') || (localOperator == '*') || (localOperator == '/'))) {
				calculateOperator = localOperator;
				break;
			}
			if (cin.fail()) {
				cin.clear();
				cout << "�������� ����, ���������." << endl;
			}
			else {
				cout << "������ ����� ���!\n";
			}
		}

		// switch() �� ���� ��������� ����������, � ����������� �� � �������� �������� �������������� ����.
		// ������ ������, ��� � ��������. ��������� �������� ����� ��������� �� ��������� if/else.

		switch (calculateOperator) {
		case '+': {
			calculateResult = calculateNumberFirst + calculateNumberSecond;
			cout << "����� " << calculateNumberFirst << " � " << calculateNumberSecond << " ����� " << calculateResult << endl;
			cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
			break;
		}
		case '-': {
			calculateResult = calculateNumberFirst - calculateNumberSecond;
			cout << "�������� " << calculateNumberFirst << " � " << calculateNumberSecond << " ����� " << calculateResult << endl;
			cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
			break;
		}
		case '*': {
			calculateResult = calculateNumberFirst * calculateNumberSecond;
			cout << "������������ " << calculateNumberFirst << " � " << calculateNumberSecond << " ����� " << calculateResult << endl;
			cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
			break;
		}
		case '/': {
			calculateResult = calculateNumberFirst / calculateNumberSecond;
			cout << "������� " << calculateNumberFirst << " � " << calculateNumberSecond << " ����� " << calculateResult << endl;
			cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
			break;
		}
		}
		system("cls");
	} while (!isExit);
}

void task1_3() {
	khanZamai();
	system("cls");
	bool isExit = false;
	string command_empty;
	double bLine, cLine, equationLineSolve;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------���������----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "��� ��������� ���� bx + c = 0 ������� ���������� b" << endl;
		bLine = inputDouble(-2147483647, 2147483647);

		cout << "��� ��������� ���� bx + c = 0 ������� ��������� ���������� c" << endl;
		cLine = inputDouble(-2147483647, 2147483647);

		try {
			if (bLine == 0 && cLine != 0) {
				throw 4001;
			}
			if (bLine == 0 && cLine == 0) {
				throw 4002;
			}
		}
		catch (int dripCatcher) {
			if (dripCatcher == 4001) {
				cout << "\n\n\n\n��� ���������� b ����� ����! �� �������� �� ����! (bx + c = 0 => bx = -c => x = -c/b)!\n";
				cout << "����������! ������������� ����� � ������� ����..!\n\n\n";
				break;
			}
			if (dripCatcher == 4002) {
				cout << "\n\n\n\n��� ���������� b � c ����� ����! ��������� ����� ����������� ���������� �������!\n";
				cout << "������������� ����� � ������� ����..!\n\n\n";
				break;
			}
		}
		equationLineSolve = -cLine / bLine;

		cout << "\n\n\n\n������� ��������� ����� " << equationLineSolve;
		cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void task1_4() {
	khanZamai();
	// ��� ��������� ���������� ������� ����������� ��������� ����� ��������, ��� ������ ������������� ��� �������������
	// ������������ ����� ������� �� ����, ����������� ��������� � ���������� �������.

	bool isExit = false;
	string command_empty;

	// �� ���� ����� ���� ������� ������ �����������, �������� ���� �����, �� � ������� ����� ��� ������� ������ �������� ����������.

	double aQuad, bQuad, cQuad, discriminant, equationSolve1, equationSolve2, equationSolveSolo, equationSolveDouble;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------��� ���������----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "��� ��������� ���� ax^2 + bx + c = 0 ������� ���������� a" << endl;
		aQuad = inputDouble(-2147483647, 2147483647);

		cout << "��� ��������� ���� ax^2 + bx + c = 0 ������� ���������� b" << endl;
		bQuad = inputDouble(-2147483647, 2147483647);

		cout << "��� ��������� ���� ax^2 + bx + c = 0 ������� ���������� c" << endl;
		cQuad = inputDouble(-2147483647, 2147483647);

		try {
			if (aQuad == 0 && bQuad != 0) {
				throw 5001;
			}
			if (aQuad == 0 && bQuad == 0 && cQuad != 0) {
				throw 5002;
			}
			if (aQuad == 0 && bQuad == 0 && cQuad == 0) {
				throw 5003;
			}
		}
		catch (int quadExep) {
			if (quadExep == 5001) {
				equationSolveSolo = -cQuad / bQuad;
				cout << "\n��� ��� ���������� a ����� ����, �� ������� �������� � ��������� ��������� ���� bx + c = 0\n";
				cout << "������� ��������� ����� " << equationSolveSolo;

				cout << "\n������ � ������� ����..\n\n\n";
				break;
			}
			if (quadExep == 5002) {
				cout << "\n��� ��� ����������� a � b ����� ����, �� ������� � ��������� ���.\n";

				cout << "\n������ � ������� ����..\n\n\n";
				break;
			}
			if (quadExep == 5003) {
				cout << "\n��� ��� ����������� a, b � � ����� ����, �� ������� ����� ���� ����������� ���������.\n";

				cout << "\n������ � ������� ����..\n\n\n";
				break;
			}
		}

		// ������� ������������ �� ������� D = b^2 - 4*a*c
		discriminant = pow(bQuad, 2) - 4 * aQuad * cQuad;

		// ��� � ������ ������ ������������ �� �������������. � ������� ��� else ������ ��������� ������� ����� ����,
		// ��� ���� ����� ������� ��� � ����������� ���������� ������� (��� �����-������ ����, �������� ��� ����� � else).
		if (discriminant == 0) {
			equationSolveDouble = -bQuad / 2 * aQuad;
			cout << "\n��� ��� ������������ ����� ����, �� ��� ����� ����� �������� " << equationSolveDouble;

			cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
		}
		else if (discriminant > 0) {
			equationSolve1 = (-bQuad + sqrt(discriminant)) / 2 * aQuad;
			equationSolve2 = (-bQuad - sqrt(discriminant)) / 2 * aQuad;
			cout << "������������ ������ ����, ������ ������ ������ �����: " << equationSolve1 << "; � ������ " << equationSolve2;

			cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
		}
		else {
			cout << "\n��������� �� ����� ������� (������������ �������������)";

			cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
		}
		system("cls");
	} while (!isExit);
}

void task1_5() {
	khanZamai();
	// � ������� ����������, �� ������ ����� ���� ��� ���� �������:
	// 1) �� ����� ���� � ������� �����
	// 2) �������� �����, ������ ���� ����� �������� �� ������ ������� �� �����, �� ����� ����� ������.

	bool isExit = false;
	string command_empty;
	bool isDay, isCurtains, isLamp;

	do {
		cout << "�� ����� ����? �������� 1 - ���� ��, 0 - ���� ���" << endl;
		isDay = inputBool();

		cout << "������� �� �����? �������� 1 - ���� ��, 0 - ���� ���" << endl;
		isCurtains = inputBool();

		cout << "�������� �� �����? �������� 1 - ���� ��, 0 - ���� ���" << endl;
		isLamp = inputBool();

		// ���� �������� �����������.
		if ((isDay == 1 && isCurtains == 1) || isLamp == 1) {
			cout << "\n � ������� ������!";

			cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
		}
		else {
			cout << "\n� ������� �����.";

			cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
		}
		system("cls");
	} while (!isExit);
}