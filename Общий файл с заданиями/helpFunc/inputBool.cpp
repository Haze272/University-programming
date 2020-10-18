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
			cout << "Неверный ввод, повторите. \n";
		}
		else {
			cout << "Число вне допустимого диапазона значений. Повторите ввод. \n";
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}