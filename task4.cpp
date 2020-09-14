#include <iostream>
#include <cstdlib>

using namespace std;

int remain;
void preLatest(int G) {
	if (G / 10 == 0) {
		cout << "Bodybag! " << remain << endl;
	}
	else {
		remain = G % 10;
		G = G / 10;

		cout << G << endl;
		cout << remain << endl;
		cout << endl;

		preLatest(G);
	}
}

int main() {
	int X;
	
	cout << "Enter the number (10 <= X <= 10000)" << endl;
	cin >> X;
	cout << endl;

	try {
		if (!(X >= 10 && X <= 10000)) {
			throw 100;
		}
	}
	catch (int m) {
		if (m == 100) {
			cout << "You have entered incorrect value! (10 <= X <= 10000)" << endl;
			exit(0);
		}
	}

	preLatest(X);
}
