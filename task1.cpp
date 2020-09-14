#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
	int s, V, T, km; 
	s = 45;
	
	cout << "Enter the speed value (km/h) 0<=V<=100" << endl;
	cin >> V;

	cout << "Enter the time value (hours) 1<=T<=100" << endl;
	cin >> T;

	// Реализуем исключения (При вводе некорректных данных)
	try {
		if (!(V >= 0 && V <= 100) && !(T >= 1 && T <= 100)) {
			throw 100;
		}
		else if (!(V >= 0 && V <= 100)) {
			throw 101;
		}
		else if (!(T >= 1 && T <= 100)) {
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

	km = (V * T) % s; // Так как трасса кольцевая, то от любого результата берем остаток от деления на длину кольцевой трассы
	cout << "When you'll arrive, you will be at " << km << " kilometer" << endl;
}
