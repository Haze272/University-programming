#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int s, v, t, km; 
	s = 45;
	
	cout << "Enter the speed value (km/h) 0<=V<=100" << endl;
	cin >> v;

	cout << "Enter the time value (hours) 1<=T<=100" << endl;
	cin >> t;

	// Реализуем исключения (При вводе некорректных данных)
	try {
		if (!(v >= 0 && v <= 100) && !(t >= 1 && t <= 100)) {
			throw 100;
		}
		else if (!(v >= 0 && v <= 100)) {
			throw 101;
		}
		else if (!(t >= 1 && t <= 100)) {
			throw 102;
		}
	}
	catch (int m) {
		if (m == 100) {
			cout << "Your speed and time value aren't correct (0<=V<=100) and (1<=T<=100)" << endl;
			exit(0);
		}
		else if (m == 101) {
			cout << "Your speed value isn't correct (0<=V<=100)" << endl;
			exit(0);
		}
		else if (m == 102) {
			cout << "Your time value isn't correct(1<=T<=100)" << endl;
			exit(0);
		}
	}

	km = (v * t) % s; // Так как трасса кольцевая, то от любого результата берем остаток от деления на длину кольцевой трассы
	cout << "When you'll arrive, you will be at " << km << " kilometer" << endl;
}
