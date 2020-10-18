#include "inputFloat.h"

float inputFloat(int m, int M) {
	for (;;) {
		float valuea;
		if ((cin >> valuea).good() && (m <= valuea) && (valuea <= M)) {
			return valuea;
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