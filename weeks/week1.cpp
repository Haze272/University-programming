#include "../helpFunc/helpFunctions.h"
#include "weeks.h"
#include <iostream>

using namespace std;
void khanZamai();

/*-----------------------------------------Первая неделя-----------------------------------------*/

void task1_1() {
	khanZamai();
	string yourName;
	string command_empty;
	bool isExit = false;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Вывод имени----------------\n\n\n\n\n\n\n\n\n\n";

	// Через do реализован механизм сессии в программе.
	// Пользователь, получая результат, может выбрать остаться ли ему в программе либо перейти в главное меню.
	// Исключения - операции в уравнениях, там try/catch ловит такие моменты как деление на ноль, переход к линейному уравнению итд.

	do {
		cout << "Как вас зовут?\n";

		cin >> yourName;
		cout << "Ваше имя - " << yourName << "\n";

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void task1_2() {
	khanZamai();
	system("cls");
	double calculateNumberFirst, calculateNumberSecond, calculateResult;
	char calculateOperator;

	bool isExit = false;
	string command_empty;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Арифметика----------------\n\n\n\n\n\n\n\n\n\n";
	do {
		cout << "Введите значение переменной а" << endl;
		calculateNumberFirst = inputDouble(-2147483647, 2147483647);

		cout << "Введите значение переменной b" << endl;
		calculateNumberSecond = inputDouble(-2147483647, 2147483647);

		cout << "Введите операцию, которую вы хотите совершить с введёнными переменными\n";
		cout << "\"+\" - Сложение\n" << "\"-\" - Вычитание\n" << "\"*\" - Умножение\n" << "\"/\" - Деление\n";

		// Ещё один подвид той же самой проверки. На этот раз переделан под символы.
		// Единственный минус, который я заметил, это то, что ввиду типа char сообщение о некорректности выводится ровно
		// столько раз, сколько символом присутствует в вводе пользователем.

		while (true) {
			char localOperator;
			cout << "Введите знак" << endl;
			if ((cin >> localOperator).good() && ((localOperator == '+') || (localOperator == '-') || (localOperator == '*') || (localOperator == '/'))) {
				calculateOperator = localOperator;
				break;
			}
			if (cin.fail()) {
				cin.clear();
				cout << "Неверный ввод, повторите." << endl;
			}
			else {
				cout << "Такого знака нет!\n";
			}
		}

		// switch() на вход принимает переменную, в зависимости от её значения работает соответстующий кейс.
		// Кейсов четыре, как и операций. Благодаря проверке можно избавится от множества if/else.

		switch (calculateOperator) {
		case '+': {
			calculateResult = calculateNumberFirst + calculateNumberSecond;
			cout << "Сумма " << calculateNumberFirst << " и " << calculateNumberSecond << " равна " << calculateResult << endl;
			cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
			break;
		}
		case '-': {
			calculateResult = calculateNumberFirst - calculateNumberSecond;
			cout << "Разность " << calculateNumberFirst << " и " << calculateNumberSecond << " равна " << calculateResult << endl;
			cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
			break;
		}
		case '*': {
			calculateResult = calculateNumberFirst * calculateNumberSecond;
			cout << "Произведение " << calculateNumberFirst << " и " << calculateNumberSecond << " равно " << calculateResult << endl;
			cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
			break;
		}
		case '/': {
			calculateResult = calculateNumberFirst / calculateNumberSecond;
			cout << "Частное " << calculateNumberFirst << " и " << calculateNumberSecond << " равно " << calculateResult << endl;
			cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
			break;
		}
		}
		system("cls");
	} while (!isExit);
}

void task1_3() {
	khanZamai();
	system("cls");
	bool isExit = false;
	string command_empty;
	double bLine, cLine, equationLineSolve;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Уравнение----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "Для уравнения вида bx + c = 0 введите коеффицент b" << endl;
		bLine = inputDouble(-2147483647, 2147483647);

		cout << "Для уравнения вида bx + c = 0 введите свободный коеффицент c" << endl;
		cLine = inputDouble(-2147483647, 2147483647);

		try {
			if (bLine == 0 && cLine != 0) {
				throw 4001;
			}
			if (bLine == 0 && cLine == 0) {
				throw 4002;
			}
		}
		catch (int dripCatcher) {
			if (dripCatcher == 4001) {
				cout << "\n\n\n\nВаш коеффицент b равен нулю! Вы поделили на ноль! (bx + c = 0 => bx = -c => x = -c/b)!\n";
				cout << "Катастрофа! Инициализирую выход в главное меню..!\n\n\n";
				break;
			}
			if (dripCatcher == 4002) {
				cout << "\n\n\n\nВаш коеффицент b и c равен нулю! Уравнение имеет бесконечное количество решений!\n";
				cout << "Инициализирую выход в главное меню..!\n\n\n";
				break;
			}
		}
		equationLineSolve = -cLine / bLine;

		cout << "\n\n\n\nРешение уравнения равно " << equationLineSolve;
		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
	} while (!isExit);
}

void task1_4() {
	khanZamai();
	// При написании реализации решения квадратного уравнения важно понимать, что помимо развествления при дискриминанте
	// присутствует также деление на ноль, бесконечное множество и отсутствие решения.

	bool isExit = false;
	string command_empty;

	// На деле можно было обойтсь шестью переменными, возможно даже пятью, но я подумал стоит для каждого случая выделеть переменную.

	double aQuad, bQuad, cQuad, discriminant, equationSolve1, equationSolve2, equationSolveSolo, equationSolveDouble;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Ещё уравнение----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "Для уравнения вида ax^2 + bx + c = 0 введите коеффицент a" << endl;
		aQuad = inputDouble(-2147483647, 2147483647);

		cout << "Для уравнения вида ax^2 + bx + c = 0 введите коеффицент b" << endl;
		bQuad = inputDouble(-2147483647, 2147483647);

		cout << "Для уравнения вида ax^2 + bx + c = 0 введите коеффицент c" << endl;
		cQuad = inputDouble(-2147483647, 2147483647);

		try {
			if (aQuad == 0 && bQuad != 0) {
				throw 5001;
			}
			if (aQuad == 0 && bQuad == 0 && cQuad != 0) {
				throw 5002;
			}
			if (aQuad == 0 && bQuad == 0 && cQuad == 0) {
				throw 5003;
			}
		}
		catch (int quadExep) {
			if (quadExep == 5001) {
				equationSolveSolo = -cQuad / bQuad;
				cout << "\nТак как коеффицент a равен нулю, то решение сводится к линейному уравнению вида bx + c = 0\n";
				cout << "Решение уравнения равно " << equationSolveSolo;

				cout << "\nВыхожу в главное меню..\n\n\n";
				break;
			}
			if (quadExep == 5002) {
				cout << "\nТак как коеффиценты a и b равны нулю, то решений у уравнения нет.\n";

				cout << "\nВыхожу в главное меню..\n\n\n";
				break;
			}
			if (quadExep == 5003) {
				cout << "\nТак как коеффиценты a, b и с равны нулю, то решений может быть бесконечное множество.\n";

				cout << "\nВыхожу в главное меню..\n\n\n";
				break;
			}
		}

		// Находим дискриминант по формуле D = b^2 - 4*a*c
		discriminant = pow(bQuad, 2) - 4 * aQuad * cQuad;

		// Вот и вторая тройка разветвления по дискриминанту. Я оставил для else именно отсутсвие решений ввиду того,
		// что туда может попасть ещё и неппавильно работающее решение (при какой-нибудь баге, например оно пойдёт в else).
		if (discriminant == 0) {
			equationSolveDouble = -bQuad / 2 * aQuad;
			cout << "\nТак как дискриминант равен нулю, то оба корня имеют значение " << equationSolveDouble;

			cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
		}
		else if (discriminant > 0) {
			equationSolve1 = (-bQuad + sqrt(discriminant)) / 2 * aQuad;
			equationSolve2 = (-bQuad - sqrt(discriminant)) / 2 * aQuad;
			cout << "Дискриминант больше нуля, значит первый корень равен: " << equationSolve1 << "; а второй " << equationSolve2;

			cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
		}
		else {
			cout << "\nУравнение не имеет решений (дискриминант отрицательный)";

			cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
		}
		system("cls");
	} while (!isExit);
}

void task1_5() {
	khanZamai();
	// В условии говориться, то светло может быть при двух случаях:
	// 1) На улице день и открыты шторы
	// 2) Включена лампа, причём если лампа включена то другие факторы не важны, всё равно будет светло.

	bool isExit = false;
	string command_empty;
	bool isDay, isCurtains, isLamp;

	do {
		cout << "На улице день? Напишите 1 - если да, 0 - если нет" << endl;
		isDay = inputBool();

		cout << "Открыты ли шторы? Напишите 1 - если да, 0 - если нет" << endl;
		isCurtains = inputBool();

		cout << "Включена ли лампа? Напишите 1 - если да, 0 - если нет" << endl;
		isLamp = inputBool();

		// Сама условная конструкция.
		if ((isDay == 1 && isCurtains == 1) || isLamp == 1) {
			cout << "\n В комнате светло!";

			cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
		}
		else {
			cout << "\nВ комнате темно.";

			cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
		}
		system("cls");
	} while (!isExit);
}