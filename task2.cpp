#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int x, result;

	cout << "Enter the number (from 100 up to 999)" << endl;
	cin >> x;

	// Инициализация исключений
	try {
		if (x <= 100 || x >= 999) {
			throw 100;
		}
	}
	catch (int q) {
		if (q == 100) {
			cout << "The value you have entered is not correct (from 100 up to 999)" << endl;
			exit(0);
		}
	}

	result = x / 100;
	cout << "The quantity of 100 is " << result << endl;
}
