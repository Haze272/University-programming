#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int D, S, result, chocolatesInBox;

	cout << "Enter the quantity of children (1 <= x <= 10)" << endl;
	cin >> D;

	cout << "Enter the quantity of chocolates (1 <= m <= 100)" << endl;
	cin >> S;

	// Будет 3 условия: когда оба значеиния некорректные и по одному когда не удовлетворяется одному из условий
	try {
		if (!(D >= 1 && D <= 10) && !(S >= 1 && S <= 100)) {
			throw 100;
		}
		else if (!(D >= 1 && D <= 10)) {
			throw 101;
		}
		else if (!(S >= 1 && S <= 100)) {
			throw 102;
		}
	}
	catch (int m) { // Когда одно из ислючений проходило в try, то оно отправляло код ошибки, catch принимает код ошибки и обрабатывает её
		if (m == 100) {
			cout << "You entered incorrect numbers of children and chocolates (1 <= x <= 10) and (1 <= m <= 100)" << endl;
			exit(0);
		}
		else if (m == 101) {
			cout << "You entered incorrect number of children (1 <= x <= 10)" << endl;
			exit(0);
		}
		else if (m == 102) {
			cout << "You entered incorrect number chocolates (1 <= m <= 100)" << endl;
			exit(0);
		}
	}

	// Вычислим, сколько шоколадок получит каждый ребенок
	result = S / D;
	cout << "Every child will recive " << result << " chocolates" << endl;

	// Если шоколадки не получится поделить между ребятами, то остаток от деления мы запишем в переменную
	chocolatesInBox = S % D;
	if (chocolatesInBox != 0) {
		cout << chocolatesInBox << " chocolate/(s) will be in the box" << endl;
	}
}
