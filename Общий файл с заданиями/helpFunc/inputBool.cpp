#include "inputBool.h"

bool inputBool() {
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