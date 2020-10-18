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
#include <fstream>


using namespace std;

enum Color : int
{
	BLACK = 0,
	RED = 1,
	GREEN = 2,
	BROWN = 3,
	BLUE = 4,
	MAGENTA = 5,
	CYAN = 6,
	GREY = 7,
	YELLOW = 8,
	LRED = 9,
	LGREEN = 10,
	LBLUE = 11,
	LMAGENTA = 12,
	LCYAN = 13,
	WHITE = 14
};

const int ColorCount = static_cast<int>(WHITE) + 1;

// Устанавливает указанный цвет в консоли
void SetColorConsole(Color color)
{
	static WORD WinColorFG[ColorCount] =
	{
		0,                                                                         // BLACK
		FOREGROUND_RED,                                                            // RED
		FOREGROUND_GREEN,                                                          // GREEN
		FOREGROUND_RED | FOREGROUND_GREEN,                                         // BROWN
		FOREGROUND_BLUE,                                                           // BLUE
		FOREGROUND_RED | FOREGROUND_BLUE,                                          // MAGENTA
		FOREGROUND_GREEN | FOREGROUND_BLUE,                                        // CYAN
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,                       // WHITE
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY,                  // YELLOW
		FOREGROUND_RED | FOREGROUND_INTENSITY,                                     // RED_BOLD
		FOREGROUND_GREEN | FOREGROUND_INTENSITY,                                   // GREEN_BOLD
		FOREGROUND_BLUE | FOREGROUND_INTENSITY,                                    // BLUE_BOLD
		FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY,                   // MAGENTA_BOLD
		FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY,                 // CYAN_BOLD
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY // WHITE_BOLD
	};

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, WinColorFG[color]);
}

// Использует стандартный цвет
void ResetColorConsole()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

// Генерируем рандомное число между значениями min и max.
// Предполагается, что функцию srand() уже вызывали
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	// Равномерно распределяем рандомное число в нашем диапазоне
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}


Color colours[15] = {
	BLACK, RED, GREEN,
	BROWN, BLUE, MAGENTA,
	CYAN, GREY, YELLOW, LRED,
	LGREEN, LBLUE, LMAGENTA, LCYAN,
	WHITE
};

void khanZamai() {
	int randCol = (rand() % 14) + 1;
	Color govnishe = colours[randCol];
	SetColorConsole(govnishe);
}


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

float inputFloat(int m, int M) {
	for (;;) {
		float valuea;
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

bool inputBool() {
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

double antihypeRoot(double x, double n)
{
	return pow(x, 1 / n);
}


/*-----------------------------------------Раздел с заданиями-----------------------------------------*/


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

/*-----------------------------------------Вторая неделя-----------------------------------------*/

void task2_1() {
	khanZamai();
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
		system("cls");
	} while (!isExit);
}

void task2_2() {
	khanZamai();
	string command_empty;
	bool isExit = false;

	double w, a, x;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Разветвление----------------\n\n\n\n\n\n\n\n\n\n";

	int exceptionCounter;
	do {
		exceptionCounter = 0;

		cout << "Введите значение параметра a:" << endl;
		a = inputDouble(-2147483647, 2147483647);

		cout << "Введите значение переменной x:" << endl;
		x = inputDouble(-2147483647, 2147483647);

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
				exceptionCounter++;
				cout << "Вы вышли за область предела функции (|x| > 0) и (a - x^2 >= 0)";

				cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
				cin >> command_empty;
				if (command_empty == "!exit") {
					return;
				}
				else {
					break;
				}
			}
			if (dripperCatcher == 5202) {
				exceptionCounter++;
				cout << "Вы вышли за область предела функции (|x| > 0)";

				cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
				cin >> command_empty;
				if (command_empty == "!exit") {
					return;
				}
				else {
					break;
				}
			}
			if (dripperCatcher == 5203) {
				exceptionCounter = 1;
				cout << "Вы вышли за область предела функции (a - x^2 >= 0)";

				cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
				cin >> command_empty;
				if (command_empty == "!exit") {
					break;
				}
			}
		}

		if (exceptionCounter == 0) {
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
			system("cls");
		}
	} while (!isExit);
}

void task2_3() {
	khanZamai();
	string command_empty;
	bool isExit = false;

	double z, b, x, y;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Функция----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "Введите значение параметра b:" << endl;
		b = inputDouble(-2147483647, 2147483647);

		cout << "Введите значение переменной x:" << endl;
		x = inputDouble(-2147483647, 2147483647);

		cout << "Введите значение переменной y:" << endl;
		y = inputDouble(-2147483647, 2147483647);

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

				cout << "\nПродолжим? Напишите всё что угодно\n";
				cin >> command_empty;
				break;
			}
			if (dripperCatcher == 5302) {
				cout << "Вы вышли за область предела функции (b - y > 0)";

				cout << "\nПродолжим? Напишите всё что угодно\n";
				cin >> command_empty;
				break;
			}
			if (dripperCatcher == 5303) {
				cout << "Вы вышли за область предела функции (b - x >= 0)";

				cout << "\nПродолжим? Напишите всё что угодно\n";
				cin >> command_empty;
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
		system("cls");
	} while (!isExit);
}

void task2_4() {
	khanZamai();
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
		system("cls");
	} while (!isExit);
}

void task2_5() {
	khanZamai();
	system("cls");
	string command_empty;
	bool isExit = false;

	double tabel, result;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Табуляция----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		cout << "Введите число для табулирования функции\n";
		tabel = inputDouble(-2147483647, 2147483647);
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
		system("cls");
	} while (!isExit);
}

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
				cout << "Нельзя делить на ноль! (12 ((1+r)n−1)) != 0)\n";

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
		cout << "C'est govno, Marie.. \n";



		cout << "\nПродолжим? Напишите всё что угодно для продолжения, !exit если хотите выйти из программы\n";
		cin >> command_empty;
		if (command_empty == "!exit") {
			isExit = true;
		}
		system("cls");
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
		khanZamai();
		cout << "Введите номер недели с домашним заданием (1-4)" << endl;
		cout << endl;
		cout << "№1 - Первая неделя\n";
		cout << "№2 - Вторая неделя\n";
		cout << "№3 - Третья неделя\n";
		cout << "№4 - Четвертая неделя (В процессе)\n";
		cout << "Ввод нуля завершит программу\n\n";

		semanaNumero = inputInt(0, 4);

		bool isExit = false;
		switch (semanaNumero) {
		case 1:
			do {
				khanZamai();
				system("cls");
				cout << "\n\n\n\n\n----------------Вы вышли в главное меню----------------\n\n\n\n\n" << endl;

				cout << "Для просмотра заданий введите номер задания (1-5)" << endl;
				cout << endl;
				cout << "№1 - задание \"Имя\"\n";
				cout << "№2 - задание \"Арифметика\" \n";
				cout << "№3 - задание \"Уравнение\" \n";
				cout << "№4 - задание \"Ещё уравнение\" \n";
				cout << "№5 - задание \"Лампа со шторой\" \n\n";
				cout << "Ввод нуля выйдет в меню выбора недели\n\n";

				taskNumber = inputInt(0, 5);
				system("cls");

				switch (taskNumber) {
				case 1: task1_1(); break;
				case 2: task1_2(); break;
				case 3: task1_3(); break;
				case 4: task1_4(); break;
				case 5: task1_5(); break;
				case 0: isExit = 1;
				}
				system("cls");
			} while (!isExit);

			break;
		case 2:
			do {
				khanZamai();
				system("cls");
				cout << "\n\n\n\n\n----------------Вы вышли в главное меню----------------\n\n\n\n\n" << endl;

				cout << "Для просмотра заданий введите номер задания (1-5)" << endl;
				cout << endl;
				cout << "№1 - задание \"Конус\"\n";
				cout << "№2 - задание \"Разветвление\"\n";
				cout << "№3 - задание \"Функция\"\n";
				cout << "№4 - задание \"Порядок\"\n";
				cout << "№5 - задание \"Табуляция\"\n\n";
				cout << "Ввод нуля выйдет в меню выбора недели\n\n";

				taskNumber = inputInt(0, 5);
				system("cls");

				switch (taskNumber) {
				case 1: task2_1(); break;
				case 2: task2_2(); break;
				case 3: task2_3(); break;
				case 4: task2_4(); break;
				case 5: task2_5(); break;
				case 0: isExit = 1;
				}

				system("cls");
			} while (!isExit);

			break;
		case 3:
			do {
				khanZamai();
				system("cls");
				cout << "\n\n\n\n\n----------------Вы вышли в главное меню----------------\n\n\n\n\n" << endl;

				cout << "Для просмотра заданий введите номер задания (1-5)" << endl;
				cout << endl;
				cout << "№1 - задание \"Заем\"\n";
				cout << "№2 - задание \"Ссуда\"\n";
				cout << "№3 - задание \"Копирование файла\"\n";
				cout << "№4 - задание \"Фильтр\"\n";
				cout << "№5 - задание \"Сортировка букв\"\n";
				cout << "Ввод нуля выйдет в меню выбора недели\n";

				taskNumber = inputInt(0, 5);
				system("cls");

				switch (taskNumber) {
				case 1: task3_1(); break;
				case 2: task3_2(); break;
				case 3: task3_3(); break;
				case 4: task3_4(); break;
				case 5: task3_5(); break;
				case 0: isExit = 1;
				}

				system("cls");
			} while (!isExit);

			break;
		case 4:
			do {
				khanZamai();
				system("cls");
				cout << "\n\n\n\n\n----------------Вы вышли в главное меню----------------\n\n\n\n\n" << endl;

				cout << "Для просмотра заданий введите номер задания (1-5)" << endl;
				cout << endl;
				cout << "№1 - задание \"Файл\"\n";
				cout << "№2 - задание \"Знак числа\" \n";
				cout << "№3 - задание \"Геометрические фигуры\" \n";
				cout << "№4 - задание \"Былая слава\" \n";
				cout << "№5 - задание \"Синусоида\"\n";
				cout << "№6 - задание \"Автоматный распознаватель\"\n";
				cout << "№7 - задание \"Генератор случайных чисел\"\n";
				cout << "Ввод нуля выйдет в меню выбора недели\n";

				taskNumber = inputInt(0, 7);
				system("cls");

				switch (taskNumber) {
				case 1: task4_1(); break;
				case 2: task4_2(); break;
				case 3: task4_3(); break;
				case 4: task4_4(); break;
				case 5: task4_5(); break;
				case 6: task4_1(); break;
				case 7: task4_1(); break;
				case 0: isExit = 1;
				}
				system("cls");
			} while (!isExit);

			break;
		case 0: exit(0); break;
		}
	}
}
