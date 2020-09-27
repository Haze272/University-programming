//
//
// Все домашние работы по процедурному программированию
// Беркунов Степан Игоревич, ИНБО-15-20
//
//

#include <iostream>
#include <string>
#define  NOMINMAX // Без этого define происходит кофликт библиотеки Windows.h и max() в функции inputInt
#include <Windows.h> // Реализация русского ввода/вывода
#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;


/*-----------------------------------------Раздел с вспомогательными функциям-----------------------------------------*/


int inputInt(int m, int M) {
	for (;;) {
		int valueChecking;
		if ((cin >> valueChecking).good() && (m <= valueChecking) && (valueChecking <= M) && (floor(valueChecking) == valueChecking)) {
			return valueChecking;
			break;
		}
		if (cin.fail()) {
			cin.clear();
			cout << "Неверный ввод, повторите. \n";
		}
		else {
			cout << "Число вне допустимого диапазона значений. Повторите ввод. \n";
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

double inputDouble(int m, int M) {
	for (;;) {
		double valuea;
		if ((cin >> valuea).good() && (m <= valuea) && (valuea <= M)) {
			return valuea;
			break;
		}
		if (cin.fail()) {
			cin.clear();
			cout << "Неверный ввод, повторите. \n";
		}
		else {
			cout << "Число вне допустимого диапазона значений. Повторите ввод. \n";
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

bool inputBool () {
	for (;;) {
		bool localBool;
		if ((cin >> localBool).good()) {
			return localBool;
			break;
		}
		if (cin.fail()) {
			cin.clear();
			cout << "Неверный ввод, повторите. \n";
		}
		else {
			cout << "Число вне допустимого диапазона значений. Повторите ввод. \n";
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}


/*-----------------------------------------Раздел с заданиями-----------------------------------------*/


/*-----------------------------------------Первая неделя-----------------------------------------*/

void task1_1() {
	system("cls");
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
	} while (!isExit);
}

void task1_2() {
	system("cls");
	double calculateNumberFirst, calculateNumberSecond, calculateResult;
	char calculateOperator;

	bool isExit = false;
	string command_empty;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Арифметика----------------\n\n\n\n\n\n\n\n\n\n";
	do {
		cout << "Введите значение переменной а" << endl;
		calculateNumberFirst = inputDouble(-2147483648, 2147483647);

		cout << "Введите значение переменной b" << endl;
		calculateNumberSecond = inputDouble(-2147483648, 2147483647);

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
			cout << "Сумма" << calculateNumberFirst << "и" << calculateNumberSecond << "равна" << calculateResult << endl;
			cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
			break;
		}
		case '-': {
			calculateResult = calculateNumberFirst - calculateNumberSecond;
			cout << "Разность" << calculateNumberFirst << "и" << calculateNumberSecond << "равна" << calculateResult << endl;
			cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
			break;
		}
		case '*': {
			calculateResult = calculateNumberFirst * calculateNumberSecond;
			cout << "Произведение" << calculateNumberFirst << "и" << calculateNumberSecond << "равно" << calculateResult << endl;
			cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
			break;
		}
		case '/': {
			calculateResult = calculateNumberFirst * calculateNumberSecond;
			cout << "Частное" << calculateNumberFirst << "и" << calculateNumberSecond << "равно" << calculateResult << endl;
			cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
			break;
		}
		}
	} while (!isExit);
}

void task1_3() {
	system("cls");
	bool isExit = false;
	string command_empty;
	double bLine, cLine, equationLineSolve;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Уравнение----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "Для уравнения вида bx + c = 0 введите коеффицент b" << endl;
		bLine = inputDouble(-2147483648, 2147483647);

		cout << "Для уравнения вида bx + c = 0 введите свободный коеффицент c" << endl;
		cLine = inputDouble(-2147483648, 2147483647);

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

		cout << "\n\n\n\n Решение уравнения равно " << equationLineSolve;
		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
	} while (!isExit);
}

void task1_4() {
	system("cls");

	// При написании реализации решения квадратного уравнения важно понимать, что помимо развествления при дискриминанте
	// присутствует также деление на ноль, бесконечное множество и отсутствие решения.

	bool isExit = false;
	string command_empty;

	// На деле можно было обойтсь шестью переменными, возможно даже пятью, но я подумал стоит для каждого случая выделеть переменную.

	double aQuad, bQuad, cQuad, discriminant, equationSolve1, equationSolve2, equationSolveSolo, equationSolveDouble;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Ещё уравнение----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "Для уравнения вида ax^2 + bx + c = 0 введите коеффицент a" << endl;
		aQuad = inputDouble(-2147483648, 2147483647);

		cout << "Для уравнения вида ax^2 + bx + c = 0 введите коеффицент b" << endl;
		bQuad = inputDouble(-2147483648, 2147483647);

		cout << "Для уравнения вида ax^2 + bx + c = 0 введите коеффицент c" << endl;
		cQuad = inputDouble(-2147483648, 2147483647);

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
			cout << "\n Уравнение не имеет решений (дискриминант отрицательный)";

			cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
		}

	} while (!isExit);
}

void task1_5() {
	system("cls");

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
			cout << "\n В комнате темно.";

			cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
			cin >> command_empty;
			if (command_empty == "!exit") {
				isExit = true;
			}
		}
	} while (!isExit);
}

/*-----------------------------------------Вторая неделя-----------------------------------------*/

void task2_1() {
	system("cls");
	string command_empty;
	bool isExit = false;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Конус----------------\n\n\n\n\n\n\n\n\n\n";

	double Volume, Area, height, radiusOut, radiusIn, forming;

	do {
		cout << "Введите радиус большего основания:\n";
		radiusOut = inputDouble(0, 2147483647);

		cout << "Введите радиус меньшего основания:\n";
		radiusIn = inputDouble(0, 2147483647);

		cout << "Введите высоту:\n";
		height = inputDouble(0, 2147483647);

		cout << "Введите образующую конуса:\n";
		forming = inputDouble(0, 2147483647);

		system("cls");

		Volume = M_PI / 3 * height * (pow(radiusOut, 2) + radiusOut * radiusIn + pow(radiusIn, 2));
		cout << "Объём вашего усечённого конуса равен " << Volume << endl;

		Area = M_PI * (pow(radiusOut, 2) + forming * (radiusOut + radiusIn) + pow(radiusIn, 2));
		cout << "Площадь вашего усечённого конуса равна " << Area << endl;

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
	} while (!isExit);
}

void task2_2() {
	system("cls");
	string command_empty;
	bool isExit = false;

	double w, a, x;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Разветвление----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "Введите значение параметра a:" << endl;
		a = inputDouble(-2147483648, 2147483647);

		cout << "Введите значение переменной x:" << endl;
		x = inputDouble(-2147483648, 2147483647);

		try {
			if (abs(x) <= 0 && a - pow(x, 2) < 0) {
				throw 5201;
			}
			if (abs(x) <= 0) {
				throw 5202;
			}
			if (a - pow(x, 2) < 0) {
				throw 5203;
			}
		}
		catch (int dripperCatcher) {
			if (dripperCatcher == 5201) {
				cout << "Вы вышли за область предела функции (|x| > 0) и (a - x^2 >= 0)";
				break;
			}
			if (dripperCatcher == 5202) {
				cout << "Вы вышли за область предела функции (|x| > 0)";
				break;
			}
			if (dripperCatcher == 5203) {
				cout << "Вы вышли за область предела функции (a - x^2 >= 0)";
				break;
			}
		}

		if (abs(x) < 1) {
			w = a * log(abs(x));
		}
		else if (abs(x) >= 1) {
			w = sqrt(a - pow(x, 2));
		}
		cout << "\n\n\n\nОтвет равен " << w;

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
	} while (!isExit);
}

void task2_3() {
	system("cls");
	string command_empty;
	bool isExit = false;

	double z, b, x, y;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Функция----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "Введите значение параметра b:" << endl;
		b = inputDouble(-2147483648, 2147483647);

		cout << "Введите значение переменной x:" << endl;
		x = inputDouble(-2147483648, 2147483647);

		cout << "Введите значение переменной y:" << endl;
		y = inputDouble(-2147483648, 2147483647);

		try {
			if (b - y <= 0 && b - x < 0) {
				throw 5301;
			}
			if (b - y <= 0) {
				throw 5302;
			}
			if (b - x < 0) {
				throw 5303;
			}
		}
		catch (int dripperCatcher) {
			if (dripperCatcher == 5301) {
				cout << "Вы вышли за область предела функции (b - y > 0) и (b - x >= 0)";
				break;
			}
			if (dripperCatcher == 5302) {
				cout << "Вы вышли за область предела функции (b - y > 0)";
				break;
			}
			if (dripperCatcher == 5303) {
				cout << "Вы вышли за область предела функции (b - x >= 0)";
				break;
			}
		}

		z = log(b - y) * sqrt(b - x);
		cout << "\n\n\n\nФункция равна " << z;

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
	} while (!isExit);
}

void task2_4() {
	system("cls");
	string command_empty;
	bool isExit = false;

	int order;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Порядок----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "Введите число, для которого выведутся последующие 10\n";

		order = inputInt(0, 2147483647);
		cout << "Последовательность равна:\n";
		for (int i = 10; i > 0; i--) {
			order++;
			cout << order << endl;
		}

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
	} while (!isExit);
}

void task2_5() {
	system("cls");
	string command_empty;
	bool isExit = false;

	double tabel, result;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Табуляция----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "Введите число для табулирования функции\n";
		tabel = inputDouble(-2147483648, 2147483647);
		cout << endl;
		tabel -= 4;
		int counter = 1;

		for (int i = 0; i < 17; i++) {
			cout << counter << ") ";
			if (tabel - 1 != 0) {
				result = (pow(tabel, 2) - 2 * tabel + 2) / (tabel - 1);
				cout << "Результат для x = " << tabel << "равен: " << result << endl << endl;
			}
			try {
				if (tabel - 1 == 0) {
					throw 5501;
				}
			}
			catch (int q) {
				cout << "Результат для x = 1\n" << "Ошибка, на 0 делить нельзя (x - 1 != 0)" << endl << endl;
			}
			tabel += 0.5;
			counter++;
		}

		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
	} while (!isExit);
}


/*-----------------------------------------Главная функция-----------------------------------------*/


int main() {

	// Установим кодировку для входных и выходных данных в консоли.
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Русская локализация.
	setlocale(LC_ALL, "Russian");

	cout << "Домашняя работа №1 Беркунова Степан" << endl;

	int taskNumber;
	int semanaNumero;

	while (true) {
		system("cls");
		cout << "Введите номер недели с домашним заданием (1-2)" << endl;
		cout << endl;
		cout << "№1 - Первая неделя\n";
		cout << "№2 - Вторая неделя\n";
		cout << "Ввод нуля завершит программу\n\n";

		semanaNumero = inputInt(0, 2);
		switch (semanaNumero) {
			case 1:
				while (true) {
					system("cls");
					cout << "Для просмотра заданий введите номер задания (1-5)" << endl;
					cout << endl;
					cout << "№1 - задание \"Имя\"\n";
					cout << "№2 - задание \"Арифметика\" \n";
					cout << "№3 - задание \"Уравнение\" \n";
					cout << "№4 - задание \"Ещё уравнение\" \n";
					cout << "№5 - задание \"Лампа со шторой\" \n\n";
					cout << "Ввод нуля выйдет в меню выбора недели\n\n";

					taskNumber = inputInt(0, 5);

					switch (taskNumber) {
						case 1: task1_1(); break;
						case 2: task1_2(); break;
						case 3: task1_3(); break;
						case 4: task1_4(); break;
						case 5: task1_5(); break;
						case 0: break;
					}

					cout << "\n\n\n\n\n----------------Вы вышли в главное меню----------------\n\n\n\n\n" << endl;
				}
				break;
			case 2:
				while (true) {
					system("cls");
					cout << "Для просмотра заданий введите номер задания (1-5)" << endl;
					cout << endl;
					cout << "№1 - задание \"Конус»\"\n";
					cout << "№2 - задание \"Разветвление\"\n";
					cout << "№3 - задание \"Функция\"\n";
					cout << "№4 - задание \"Порядок\"\n";
					cout << "№5 - задание \"Табуляция\"\n\n";
					cout << "Ввод нуля выйдет в меню выбора недели\n\n";

					taskNumber = inputInt(0, 5);

					switch (taskNumber) {
						case 1: task2_1(); break;
						case 2: task2_2(); break;
						case 3: task2_3(); break;
						case 4: task2_4(); break;
						case 5: task2_5(); break;
						case 0: break;
					}

					cout << "\n\n\n\n\n----------------Вы вышли в главное меню----------------\n\n\n\n\n" << endl;
				}
				break;
			case 0: exit(0);
		break;
		}
	}
}