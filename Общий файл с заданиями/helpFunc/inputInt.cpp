#include "inputInt.h"

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