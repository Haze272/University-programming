#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	float w, x, a, e;
	e = exp(1);

	cout << "Enter the value of x variable" << endl;
	cin >> x;

	cout << "Enter the value of a parameter" << endl;
	cin >> a;

	if (abs(x) < 1) {
		w = a * log(abs(x));
		cout << w << endl;
	}
	else if (abs(x) >= 1) {
		w = sqrt(a - pow(x, 2));
		cout << w << endl;
	}
}