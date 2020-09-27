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

using namespace std;


/*-----------------------------------------������ � ���������������� ��������-----------------------------------------*/


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

bool inputBool () {
	for (;;) {
		bool localBool;
		if ((cin >> localBool).good()) {
			return localBool;
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


/*-----------------------------------------������ � ���������-----------------------------------------*/


/*-----------------------------------------������ ������-----------------------------------------*/

void task1_1() {
	system("cls");
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
	} while (!isExit);
}

void task1_2() {
	system("cls");
	double calculateNumberFirst, calculateNumberSecond, calculateResult;
	char calculateOperator;

	bool isExit = false;
	string command_empty;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------����������----------------\n\n\n\n\n\n\n\n\n\n";
	do {
		cout << "������� �������� ���������� �" << endl;
		calculateNumberFirst = inputDouble(-2147483648, 2147483647);

		cout << "������� �������� ���������� b" << endl;
		calculateNumberSecond = inputDouble(-2147483648, 2147483647);

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
			cout << "�����" << calculateNumberFirst << "�" << calculateNumberSecond << "�����" << calculateResult << endl;
			cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
			break;
		}
		case '-': {
			calculateResult = calculateNumberFirst - calculateNumberSecond;
			cout << "��������" << calculateNumberFirst << "�" << calculateNumberSecond << "�����" << calculateResult << endl;
			cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
			break;
		}
		case '*': {
			calculateResult = calculateNumberFirst * calculateNumberSecond;
			cout << "������������" << calculateNumberFirst << "�" << calculateNumberSecond << "�����" << calculateResult << endl;
			cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
			break;
		}
		case '/': {
			calculateResult = calculateNumberFirst * calculateNumberSecond;
			cout << "�������" << calculateNumberFirst << "�" << calculateNumberSecond << "�����" << calculateResult << endl;
			cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
			break;
		}
		}
	} while (!isExit);
}

void task1_3() {
	system("cls");
	bool isExit = false;
	string command_empty;
	double bLine, cLine, equationLineSolve;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------���������----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "��� ��������� ���� bx + c = 0 ������� ���������� b" << endl;
		bLine = inputDouble(-2147483648, 2147483647);

		cout << "��� ��������� ���� bx + c = 0 ������� ��������� ���������� c" << endl;
		cLine = inputDouble(-2147483648, 2147483647);

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

		cout << "\n\n\n\n ������� ��������� ����� " << equationLineSolve;
		cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
	} while (!isExit);
}

void task1_4() {
	system("cls");

	// ��� ��������� ���������� ������� ����������� ��������� ����� ��������, ��� ������ ������������� ��� �������������
	// ������������ ����� ������� �� ����, ����������� ��������� � ���������� �������.

	bool isExit = false;
	string command_empty;

	// �� ���� ����� ���� ������� ������ �����������, �������� ���� �����, �� � ������� ����� ��� ������� ������ �������� ����������.

	double aQuad, bQuad, cQuad, discriminant, equationSolve1, equationSolve2, equationSolveSolo, equationSolveDouble;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------��� ���������----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "��� ��������� ���� ax^2 + bx + c = 0 ������� ���������� a" << endl;
		aQuad = inputDouble(-2147483648, 2147483647);

		cout << "��� ��������� ���� ax^2 + bx + c = 0 ������� ���������� b" << endl;
		bQuad = inputDouble(-2147483648, 2147483647);

		cout << "��� ��������� ���� ax^2 + bx + c = 0 ������� ���������� c" << endl;
		cQuad = inputDouble(-2147483648, 2147483647);

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
			cout << "\n ��������� �� ����� ������� (������������ �������������)";

			cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
		}

	} while (!isExit);
}

void task1_5() {
	system("cls");

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
			cout << "\n � ������� �����.";

			cout << "\n���������? �������� �� ��� ������ ��� �����������, !exit ���� ������ ����� �� ���������\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
		}
	} while (!isExit);
}

/*-----------------------------------------������ ������-----------------------------------------*/

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


/*-----------------------------------------������� �������-----------------------------------------*/


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
		system("cls");
		cout << "������� ����� ������ � �������� �������� (1-2)" << endl;
		cout << endl;
		cout << "�1 - ������ ������\n";
		cout << "�2 - ������ ������\n";
		cout << "���� ���� �������� ���������\n\n";

		semanaNumero = inputInt(0, 2);
		switch (semanaNumero) {
			case 1:
				while (true) {
					system("cls");
					cout << "��� ��������� ������� ������� ����� ������� (1-5)" << endl;
					cout << endl;
					cout << "�1 - ������� \"���\"\n";
					cout << "�2 - ������� \"����������\" \n";
					cout << "�3 - ������� \"���������\" \n";
					cout << "�4 - ������� \"��� ���������\" \n";
					cout << "�5 - ������� \"����� �� ������\" \n\n";
					cout << "���� ���� ������ � ���� ������ ������\n\n";

					taskNumber = inputInt(0, 5);

					switch (taskNumber) {
						case 1: task1_1(); break;
						case 2: task1_2(); break;
						case 3: task1_3(); break;
						case 4: task1_4(); break;
						case 5: task1_5(); break;
						case 0: break;
					}

					cout << "\n\n\n\n\n----------------�� ����� � ������� ����----------------\n\n\n\n\n" << endl;
				}
				break;
			case 2:
				while (true) {
					system("cls");
					cout << "��� ��������� ������� ������� ����� ������� (1-5)" << endl;
					cout << endl;
					cout << "�1 - ������� \"�����\"\n";
					cout << "�2 - ������� \"������������\"\n";
					cout << "�3 - ������� \"�������\"\n";
					cout << "�4 - ������� \"�������\"\n";
					cout << "�5 - ������� \"���������\"\n\n";
					cout << "���� ���� ������ � ���� ������ ������\n\n";

					taskNumber = inputInt(0, 5);

					switch (taskNumber) {
						case 1: task2_1(); break;
						case 2: task2_2(); break;
						case 3: task2_3(); break;
						case 4: task2_4(); break;
						case 5: task2_5(); break;
						case 0: break;
					}

					cout << "\n\n\n\n\n----------------�� ����� � ������� ����----------------\n\n\n\n\n" << endl;
				}
				break;
			case 0: exit(0);
		break;
		}
	}
}