#include "../helpFunc/helpFunctions.h"
#include "weeks.h"
#include <iostream>
#include <string>
#define  NOMINMAX // Без этого define происходит кофликт библиотеки Windows.h и max() в функции inputInt
#include <Windows.h> // Реализация русского ввода/вывода
#include <cmath>
#define M_PI 3.14159265358979323846
#include <fstream>
#include <algorithm>
#include <iomanip>      // std::setw
#include <vector>

using namespace std;
void khanZamai();

/*-----------------------------------------Четвёртая неделя-----------------------------------------*/

void task4_1() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;
	float Zamai, Sum;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Файл----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		Sum = 0;

		cout << "Вводите 10 чисел поочерёдно через enter\n";
		ofstream damnson("fifa202n.txt");

		for (int i = 0; i < 10; i++) {
			Zamai = inputFloat(-2147483647, 2147483647);
			damnson << Zamai << endl;
		}
		damnson.close();


		cout << "Файл был успешно создан!\n\n";

		ifstream file_leer("fifa202n.txt");
		int b;

		do
		{
			// пробуем считать число
			if (file_leer >> b)
			{
				Sum += b;
			}
			else
			{
				file_leer.clear();
				file_leer.ignore(1, ' ');
			}
		} while (!file_leer.eof());

		cout << "Сумма чисел в файле равна: " << Sum << endl;

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

int sign(float x) {
	if (x > 0)
		return 1;
	else if (x == 0)
		return 0;
	else if (x < 0)
		return -1;
}

void task4_2() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;
	float numero;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Знак числа----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "Введите число\n";
		numero = inputFloat(-2147483647, 2147483647);

		if (sign(numero) == 1)
			cout << "Число " << numero << " - положительное.";
		else if (sign(numero) == 0)
			cout << "Число " << numero << " - не положительное и не отрицательное.";
		else if (sign(numero) == -1)
			cout << "Число " << numero << " - отрицательное.";

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

float areaDeRectangulo(float x, float y) {
	int result = x * y;
	return result;
}

float areaDeTriangulo(float x, float y, float z) {
	float poluPoker = (x + y + z) * 0.5;
	float result = sqrt(poluPoker * (poluPoker - x) * (poluPoker - y) * (poluPoker - z));
	return result;
}

float areaDeCirculo(float x) {
	float result = M_PI * pow(x, 2);
	return result;
}

void task4_3() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;
	int choice;
	float area, rect1, rect2, tri1, tri2, tri3, radius;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Геометрические фигуры----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "Плоащадь какой фигуры необходимо узнать?\n";
		cout << "1 - Прямоугольник\n";
		cout << "2 - Треугольник\n";
		cout << "3 - Окружность\n";
		choice = inputInt(1, 3);

		switch (choice) {
		case 1:
			cout << "Введите первую сторону прямоугольника\n";
			rect1 = inputFloat(0, 2147483647);
			cout << "Введите вторую сторону прямоугольника\n";
			rect2 = inputFloat(0, 2147483647);

			area = areaDeRectangulo(rect1, rect2);
			cout << "Площадь прямоугольника равна " << area << endl;
			break;
		case 2:
			cout << "Введите первую сторону треугольника\n";
			tri1 = inputFloat(0, 2147483647);
			cout << "Введите вторую сторону треугольника\n";
			tri2 = inputFloat(0, 2147483647);
			cout << "Введите третью сторону треугольника\n";
			tri3 = inputFloat(0, 2147483647);

			area = areaDeTriangulo(tri1, tri2, tri3);
			cout << "Площадь треугольника равна " << area << endl;
			break;
		case 3:
			cout << "Введите радиус окружности\n";
			radius = inputFloat(0, 2147483647);

			area = areaDeCirculo(radius);
			cout << "Площадь окружности равна " << area << endl;
			break;
		}

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void task4_4() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Былая слава----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		int y = 0;
		bool q = true;
		do {
			if (y < 6) {
				for (int i = 0; i < 8; i++) {
					cout << "* ";
				}
				if (y == 1 or y == 3 or y == 5) {
					for (int i = 7; i < 45; i++) {
						cout << " ";
					}
				}
				else
					for (int i = 7; i < 45; i++) {
						cout << "-";
					}
				if (y <= 6) {
					cout << "\n";
					y++;
				}
			}
			else if (y >= 6 and y < 13) {
				if (y == 7 or y == 9 or y == 11 or y == 13) {
					for (int i = 0; i < 54; i++) {
						cout << " ";
					}
				}
				else
					for (int i = 0; i < 54; i++) {
						std::cout << "-";
					}
				std::cout << "\n";
				y++;
			}
			else
				q = false;
		} while (q);

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void task4_5() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Синусоида----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		for (double y = 1.1; y > -1.1; y -= 0.1) {
			for (double x = -4; x < 4; x += 0.1) {
				if (abs(sin(x) - y) < 0.05)
					std::cout << "*";
				else if (x<0.05 && x>-0.05)
					std::cout << "|";
				else if (y<0.05 && y>-0.05)
					std::cout << "-";
				else
					std::cout << " ";
			}
			std::cout << '\n';
		}

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void task4_6() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;

	char romka[80];
	int temka, culpa, culpaTres;
	int resulto;
	int romkaNum[80];

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Автоматный распознаватель----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		culpa = 0;
		culpaTres = 0;
		resulto = 0;
		
		/*
		// обнуление массива
		fill_n(romka, 80, nullptr);
		*/

		cout << "Введите число в римской системе счисления\n";
		cin >> romka;
		temka = strlen(romka);

		/*----------------------------------------Блок с проверками--------------------------------------------*/

		for (int i = 0; i < temka; i++) {
			if (!((romka[i] == 'I') || (romka[i] == 'V') || (romka[i] == 'X') || (romka[i] == 'L') || (romka[i] == 'C') || (romka[i] == 'D') || (romka[i] == 'M'))) {
				culpa++;
			}
		}
		for (int j = 3; j < temka; j++) {
			if (romka[j] == romka[j - 1] && romka[j] == romka[j - 2] && romka[j] == romka[j - 3]) {
				culpaTres++;
			}
		}

		try {
			if (culpa != 0) {
				throw 7777;
			}
			if (culpaTres != 0) {
				throw 8888;
			}
		}
		catch (int culpaCatcher) {
			if (culpaCatcher == 7777) {
				cout << "Вы допустили ошибку при вводе, повторите\n";
				continue;
			}
			if (culpaCatcher == 8888) {
				cout << "Запись не может состоять из 4 цифр подряд\n";
				continue;
			}
		}

		/*----------------------------------------Основной блок--------------------------------------------*/

		// Заменим римские цифры в массиве на их значения в арабской системе счисления
		for (int k = 0; k <= temka; k++) {
			if (romka[k] == 'I') {
				romkaNum[k] = 1;
			}
			else if (romka[k] == 'V') {
				romkaNum[k] = 5;
			}
			else if (romka[k] == 'X') {
				romkaNum[k] = 10;
			}
			else if (romka[k] == 'L') {
				romkaNum[k] = 50;
			}
			else if (romka[k] == 'C') {
				romkaNum[k] = 100;
			}
			else if (romka[k] == 'D') {
				romkaNum[k] = 500;
			}
			else if (romka[k] == 'M') {
				romkaNum[k] = 1000;
			}
		}

		for (int m = 0; m < temka - 1; m++) {
			if (romkaNum[m] < romkaNum[m + 1]) {
				resulto -= romkaNum[m];
			}
			else {
				resulto += romkaNum[m];
			}
		}
		resulto += romkaNum[temka - 1];

		cout << "Введённое вами число в арабской записи равно " << resulto << endl;

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void task4_7() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;

	int s, m, i, c;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Генератор случайных чисел----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "Введите исходное число\n";
		s = inputInt(-2147483647, 2147483647);

		cout << "Введите первый параметр\n";
		m = inputInt(-2147483647, 2147483647);

		cout << "Введите второй параметр\n";
		i = inputInt(-2147483647, 2147483647);

		cout << "Введите третий параметр\n";
		c = inputInt(-2147483647, 2147483647);

		for (int n = 0; n < 20; n++) {
			s = (m * s + i) % c;
		}

		cout << "Случайное число равно " << s << endl;

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void task4_8() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;

	float a[3][4] = {
		{5, 2, 0, 10},
		{3, 5, 2, 5},
		{20, 0, 0, 0}
	};
	/*
	float b[4][2] = {
		{1.2, 0.5},
		{2.8, 0.4},
		{5, 1},
		{2, 1.5}
	};
	*/
	float b[4][2] = {
		{1.2, 0.5},
		{2.8, 0.4},
		{5, 1},
		{2, 1.5}
	};
	float c[3][2]{
		{0, 0},
		{0, 0},
		{0, 0}
	};

	float max1 = 0, max2 = 0, sum1 = 0, sum2 = 0, sumall = 0;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Умножение матриц----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		// Умножение матрицы :-) ;)
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 2; j++)
				for (int k = 0; k < 4; k++)
					c[i][j] += a[i][k] * b[k][j];

		// Вывод матриц в консоль )))
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 4; j++) {
				cout << setw(4) << a[i][j];
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 2; j++) {
				cout << setw(4) << b[i][j];
			}
			cout << endl;
		}
		cout << endl;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 2; j++) {
				cout << setw(5) << c[i][j];
			}
			cout << endl;
		}
		cout << endl;

		// Само задание жэс
		for (int i = 0; i < 3; i++) {
			if (c[i][1] > max1) {
				max1 = c[i][1];
			}
		}
		cout << "El primero maximo es " << max1 << endl;
		for (int i = 0; i < 3; i++) {
			if (c[i][2] > max2) {
				max2 = c[i][2];
			}
		}
		cout << "El segundo maximo es " << max2 << endl;

		for (int i = 0; i < 2; i++) {
			sum1 += c[1][i];
		}
		cout << "La suma primero es " << sum1 << endl;
		for (int i = 0; i < 2; i++) {
			sum2 += c[2][i];
		}
		cout << "La suma segundo es " << sum2 << endl;

		cout << "\nContinuamos? Escriba cualquier cosa para seguir, !exitsi quieres salir de la programa\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void task4_9() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;

	int inputn = 0, outputn = 0, finaldec = 0;
	string inputnum;
	vector<int> dec;
	vector<int> out;
	vector<char> charset;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Системы счисления----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "Введите исходное число ";
		
		begin11:  // Антихайповый костыль, главное - время
		cin >> inputnum;

		for (int i = 0; i < inputnum.length(); i++) {
			if (inputnum[i] > 47 && inputnum[i] < 58)
				dec.push_back(inputnum[i] - 48);
			else if (inputnum[i] > 64 && inputnum[i] < 91)
				dec.push_back(inputnum[i] - 55);
			else {
				cout << "Введите число цифрами \"0-9\" и заглавными буквами \"A-Z\"\n";
				goto begin11;
			}
		}
		while (inputn < 2 || inputn >36 || outputn < 2 || outputn >36) {
			cout << "Исходная СС?\n";
			cin >> inputn;
			cout << "Нужная CC?\n";
			cin >> outputn;
		}

		for (int i = 0; i < inputnum.length(); i++)
			if (inputnum[i] > 47 && inputnum[i] < 58 && inputnum[i] - 48 >= inputn) {
				cout << "Введите допустимое для " << inputn << "-ичной СС число - ";
				dec.clear();
				goto begin11;
			}

		int n = 0;
		for (int i = 0; i < dec.size() - n; i++) {
			swap(dec[i], dec[dec.size() - n - 1]);
			n++;
		}
		cout << '\n';
		for (int i = 0; i < dec.size(); i++)
			finaldec += dec[i] * pow(inputn, i);

		for (int i = 0; finaldec > 0; i++) {
			out.push_back(finaldec % outputn);
			finaldec /= outputn;
		}
		n = 0;
		for (int i = 0; i < out.size() - n; i++) {
			swap(out[i], out[out.size() - n - 1]);
			n++;
		}



		for (char c = 'A'; c <= 'Z'; c++) {
			charset.push_back(c);
		}

		vector<char> output(out.size());


		for (int i = 0; i < out.size(); i++) {
			if (out[i] >= 0 && out[i] < 10)
				output[i] = (out[i] + 48);
			else {
				for (int j = 10; j < 36; j++) {
					if (out[i] + 55 == j + 55)
						output[i] = charset[j - 10];
				}
			}
		}

		cout << "Число в " << outputn << "-ичной СС: ";
		for (int i = 0; i < output.size(); i++)
			cout << output[i];
		cout << '\n';

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}
