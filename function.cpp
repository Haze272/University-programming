// Solving function
// Stepan Berkunov

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	float z, x, y, b;

	cout << "Enter the value of x" << endl;
	cin >> x;

	cout << "Enter the value of y" << endl;
	cin >> y;

	cout << "Enter the value of b" << endl;
	cin >> b;

	if (b - y != 0 && b - x >= 0) {
		z = log(b - y) * sqrt(b - x);
		cout << "Value of the function is " << z << endl;
	}
	else {
		cout << "Values of the variables isn't included in area of allowable values" << endl;
	}
}
