#include "antihypeSort.h"

void antihypeSort(char* i, int n) {
	int a, b;
	char t;
	for (a = 0; a < n; a++)
		for (b = n - 1; b >= a; b--) {
			if (i[b - 1] > i[b]) {
				t = i[b - 1];
				i[b - 1] = i[b];
				i[b] = t;
			}
		}
}