#include "../helpFunc/helpFunctions.h"
#include "weeks.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void khanZamai();

/*-----------------------------------------Третья неделя-----------------------------------------*/

void task3_1() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;

	float Sum, r, percent, mouthPay;
	int years;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Заем----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "Введите сумму займа\n";
		Sum = inputFloat(0, 2147483647);
		cout << endl;

		cout << "Введите значение процента в %: (0 - 100)\n";
		percent = inputFloat(0, 100);
		cout << endl;

		r = percent / 100;

		cout << "Введите количество лет\n";
		years = inputInt(0, 2147);
		cout << endl;

		try {
			if (pow((1 + r), years) == 1) {
				throw 6001;
			}
		}
		catch (int antihypeCatcher) {
			if (antihypeCatcher == 6001) {
				cout << "Нельзя делить на ноль! (12 ((1+r)n?1)) != 0)\n";

				cout << "\nПродолжим? Напишите всё что угодно\n";
				cin >> command_empty;
				break;
			}
		}

		mouthPay = (Sum * r * pow(1 + r, years)) / (12 * (pow(1 + r, years) - 1));
		cout << "\nМесячная выплата равна " << mouthPay << endl;

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void task3_2() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;

	float Sum, r, percent, mouthPay;
	int years;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Ссуда----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "Введiть суму позики\n";
		Sum = inputFloat(0, 2147483647);
		cout << endl;

		cout << "Введiть мicячну виплату!\n";
		mouthPay = inputFloat(0, 2147483647);
		cout << endl;

		cout << "Введiть кiлькiсть рокiв\n";
		years = inputInt(0, 2147483647);
		cout << endl;
		years *= 12;

		percent = (((mouthPay * years) / Sum) - 1) * 100;
		cout << percent << " - це вiдсоток\n";

		cout << "\nПродовжимо? Напишiть все що завгодно для продовження, !exit якщо хочете вийти з програми\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void task3_3() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;

	// string escritor_boofer;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Копирование файла----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		/*
		string damnbuff;
		ofstream file_escritor("mybenben.txt");
		cout << "Введите текст для записи в текстовый файл максимальное число символов - 64\n";
		getline(cin, damnbuff);
		file_escritor << damnbuff << endl;
		file_escritor.close();
		*/
		string damnbuff;

		cout << "Вводите слова поочерёдно через enter, ввод нуля означит конец.\n";

		bool isExit2 = false;
		ofstream out("govno.txt");
		do {
			getline(cin, damnbuff);
			if (damnbuff == "0") {
				isExit2 = true;
				out.close();
				system("cls");
			}
			else {
				out << damnbuff << " ";
			}
		} while (!isExit2);

		cout << "Файл был успешно создан!\n" << "Его содержимое:\n\n";

		char buff[64]; // буфер промежуточного хранения считываемого из файла текста
		ifstream file_lector("govno.txt"); // открыли файл для чтения

		file_lector.getline(buff, 64); // считали строку из файла
		file_lector.close(); // закрываем файл
		cout << buff << endl; // напечатали эту строку

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void task3_4() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Фильтр----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		ifstream file_lector("govno.txt");
		int b;

		do
		{
			// пробуем считать число
			if (file_lector >> b)
			{
				// если считали число - выводим
				cout << b << endl;
			}
			else
			{
				// если считали не число, очищаем ошибки
				file_lector.clear();
				// пропускаем символы до следующего пробела
				file_lector.ignore(1, ' ');
			}
		} while (!file_lector.eof()); // eof() - функция, определяющая закончились ли данные в источнике

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			file_lector.close();
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void task3_5() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Сортировка букв----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		bool q = true;
		do {
			char s[80];
			cout << ("Введите строку длинную в 30 символов: \n");
			cin >> s;
			unsigned long i = strlen(s);
			if (i == 30) {
				q = false;
				antihypeSort(s, i);
				cout << ("Отсортированная строка : %s\n", s);
				break;

			}
			cout << "вы ввели строку длинной не 30 символов! \n";
		} while (q);

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}
