//
//
// Домашняя работа №1 по процедурному программированию
// Беркунов Степан Игоревич, ИНБО-15-20
//
//

#include <iostream>
#include <string>
#define  NOMINMAX // Без этого define происходит кофликт библиотеки Windows.h и max() в функции inputInt
#include <Windows.h> // Реализация русского ввода/вывода

using namespace std;

// Интересная и новая для меня проверка, которую мы вместе с Егором открыли в процессе решения заданий.
// Первый входной парамент задаёт минимум числа, а второй максимум, после посредством cin.good/cin.fail/cin.clear идёт проверка.

int inputInt(int m = INT_MIN, int M = INT_MAX)
{
	int N;
	for (;;) {
		if ((cin >> N).good() && (m <= N) && (N <= M)) return N;

		if (cin.fail()) {
			cin.clear();
			cout << "Неверный ввод, повторите." << endl;
		}
		else {
			cout << "Число вне допустимого диапазона значений. Повторите ввод.\n";
		}
		cin.ignore(numeric_limits<streamsize>::max(), '\n'); // <-- Я не знаю зачем эта строка, честно не смог понять. Однако из-за max() я не мог поставить windows.h
	}
}

void task1() {
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

void task2() {
	float calculateNumberFirst, calculateNumberSecond, calculateResult;
	char calculateOperator;

	// Объявим минимальное и максимальное вводимое значение для последующей проверки
	int calculateMinimum = -2147483648;
	int calculateMaximum = 2147483647;

	bool isExit = false;
	string command_empty;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Арифметика----------------\n\n\n\n\n\n\n\n\n\n";
	do {

		// Тут представлена почти та же самая проверка, что и в начале программы, однако без обертки в виде функции.
		// Вместо входных параметров значения границ определены заранее в программе.

		while (true) {
			float localNumberFirst;
			cout << "Введите значение переменной а" << endl;
			if ((cin >> localNumberFirst).good() && (calculateMinimum <= localNumberFirst) && (localNumberFirst <= calculateMaximum)) {
				calculateNumberFirst = localNumberFirst;
				break;
			}

			if (cin.fail()) {
				cin.clear();
				cout << "Неверный ввод, повторите." << endl;
			}
			else {
				cout << "Число вне допустимого диапазона значений. Повторите ввод.\n";
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		while (true) {
			float localNumberSecond;
			cout << "Введите значение переменной а" << endl;
			if ((cin >> localNumberSecond).good() && (calculateMinimum <= localNumberSecond) && (localNumberSecond <= calculateMaximum)) {
				calculateNumberSecond = localNumberSecond;
				break;
			}

			if (cin.fail()) {
				cin.clear();
				cout << "Неверный ввод, повторите." << endl;
			}
			else {
				cout << "Число вне допустимого диапазона значений. Повторите ввод.\n";
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

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

void task3() {

	// Написание формулы решения линейного уравнения не вызывает трудностей, однако важно понимать,
	// что надо учитывать деление на ноль, когда коеффицент при переменной равен нулю.
	// Также при всех нулевых коеффицентах уравнение имеет бесконечное множество решений.

	// Объявим минимальное и максимальное вводимое значение для последующей проверки
	float calculateMinimum = -2147483648;
	float calculateMaximum = 2147483647;
	bool isExit = false;
	string command_empty;
	float bLine, cLine, equationLineSolve;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Уравнение----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		while (true) {
			float localB;
			cout << "Для уравнения вида bx + c = 0 введите коеффицент b" << endl;
			if ((cin >> localB).good() && /*(localB != 0) &&*/ (calculateMinimum <= localB) && (localB <= calculateMaximum)) {
				bLine = localB;
				break;
			}
			/*
			else if (localB == 0) {
				cout << "\n\n\nКоеффицент b не может быть равен нулю!\n";
			}
			*/

			if (cin.fail()) {
				cin.clear();
				cout << "Неверный ввод, повторите." << endl;
			}
			else {
				cout << "Число вне допустимого диапазона значений. Повторите ввод.\n";
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
		while (true) {
			float localC;
			cout << "Для уравнения вида bx + c = 0 введите свободный коеффицент c" << endl;
			if ((cin >> localC).good() && (calculateMinimum <= localC) && (localC <= calculateMaximum)) {
				cLine = localC;
				break;
			}

			if (cin.fail()) {
				cin.clear();
				cout << "Неверный ввод, повторите." << endl;
			}
			else {
				cout << "Число вне допустимого диапазона значений. Повторите ввод.\n";
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		// try генерирует ошибки и с помощью throw посылает их в случае их появления.
		// catch, напротив, ловит коды ошибок и записывает их в int-овую переменную.
		
		try {
			if (bLine == 0 && cLine != 0) {
				throw 4001;
			}
			if (bLine == 0 && cLine == 0) {
				throw 4002;
			}
		}
		catch (int dripCatcher){
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

void task4() {

	// При написании реализации решения квадратного уравнения важно понимать, что помимо развествления при дискриминанте
	// присутствует также деление на ноль, бесконечное множество и отсутствие решения.

	// Объявим минимальное и максимальное вводимое значение для последующей проверки
	float calculateMinimum = -2147483648;
	float calculateMaximum = 2147483647;
	bool isExit = false;
	string command_empty;

	// На деле можно было обойтсь шестью переменными, возможно даже пятью, но я подумал стоит для каждого случая выделеть переменную.

	float aQuad, bQuad, cQuad, discriminant, equationSolve1, equationSolve2, equationSolveSolo, equationSolveDouble;

	cout << "\n\n\n\n\n\n\n\n\n\n----------------Ещё уравнение----------------\n\n\n\n\n\n\n\n\n\n";

	do {
		while (true) {
			float localA;
			cout << "Для уравнения вида ax^2 + bx + c = 0 введите коеффицент a" << endl;
			if ((cin >> localA).good() && (calculateMinimum <= localA) && (localA <= calculateMaximum)) {
				aQuad = localA;
				break;
			}

			if (cin.fail()) {
				cin.clear();
				cout << "Неверный ввод, повторите." << endl;
			}
			else {
				cout << "Число вне допустимого диапазона значений. Повторите ввод.\n";
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		while (true) {
			float localB;
			cout << "Для уравнения вида ax^2 + bx + c = 0 введите коеффицент a" << endl;
			if ((cin >> localB).good() && (calculateMinimum <= localB) && (localB <= calculateMaximum)) {
				bQuad = localB;
				break;
			}

			if (cin.fail()) {
				cin.clear();
				cout << "Неверный ввод, повторите." << endl;
			}
			else {
				cout << "Число вне допустимого диапазона значений. Повторите ввод.\n";
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		while (true) {
			float localC;
			cout << "Для уравнения вида ax^2 + bx + c = 0 введите коеффицент a" << endl;
			if ((cin >> localC).good() && (calculateMinimum <= localC) && (localC <= calculateMaximum)) {
				cQuad = localC;
				break;
			}

			if (cin.fail()) {
				cin.clear();
				cout << "Неверный ввод, повторите." << endl;
			}
			else {
				cout << "Число вне допустимого диапазона значений. Повторите ввод.\n";
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		// Первую тройку развествлений я реализовал через try/catch, потому что это подходит под смысл ошибок и исключений 
		// (т.е. следующие случаяи действительно нельзя назвать решенияем уравнения).

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

void task5() {

	// В условии говориться, то светло может быть при двух случаях:
	// 1) На улице день и открыты шторы
	// 2) Включена лампа, причём если лампа включена то другие факторы не важны, всё равно будет светло.

	bool isExit = false;
	string command_empty;
	bool isDay, isCurtains, isLamp;

	do {

		// Ещё один вариант нашей проверки, на этот раз модифицированный под булевые переменные.
		while (true) {
			bool localDay;
			cout << "На улице день? Напишите 1 - если да, 0 - если нет" << endl;
			if ((cin >> localDay).good()) {
				isDay = localDay;
				break;
			}

			if (cin.fail()) {
				cin.clear();
				cout << "Неверный ввод, повторите (0, если ночь, 1 - если день)." << endl;
			}
			else {
				cout << "Число вне допустимого диапазона значений (0 или 1). Повторите ввод.\n"; // <-- Это строчка не нужна, так как любое число кроме 1 или 0
																								 // сразу расценивается как ошибка cin
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
		}

		while (true) {
			bool localCurtains;
			cout << "Открыты ли шторы? Напишите 1 - если да, 0 - если нет" << endl;
			if ((cin >> localCurtains).good()) {
				isCurtains = localCurtains;
				break;
			}

			if (cin.fail()) {
				cin.clear();
				cout << "Неверный ввод, повторите (0, если шторы задвинуты , 1 - если открыты)." << endl;
			}
			else {
				cout << "Число вне допустимого диапазона значений (0 или 1). Повторите ввод.\n";
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		while (true) {
			bool localLamp;
			cout << "Включена ли лампа? Напишите 1 - если да, 0 - если нет" << endl;
			if ((cin >> localLamp).good()) {
				isLamp = localLamp;
				break;
			}

			if (cin.fail()) {
				cin.clear();
				cout << "Неверный ввод, повторите (0, если лампа выключена, 1 - если включена)." << endl;
			}
			else {
				cout << "Число вне допустимого диапазона значений (0 или 1). Повторите ввод.\n";
			}
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

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

int main() {

	// Установим кодировку для входных и выходных данных в консоли.
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);

	// Русская локализация.
	setlocale(LC_ALL, "Russian");

	cout << "Домашняя работа №1 Беркунова Степан" << endl;

	int taskNumber;

	while (true) {
		cout << "Для просмотра заданий введите номер задания (1-5)" << endl;
		cout << endl;
		cout << "№1 - задание \"Имя\"\n";
		cout << "№2 - задание \"Арифметика\" \n";
		cout << "№3 - задание \"Уравнение\" \n";
		cout << "№4 - задание \"Ещё уравнение\" \n";
		cout << "№5 - задание \"Лампа со шторой\" \n\n";

		// Нас интересует проверка, которая будет определять, ввёл ли пользователь число от 1 до 5.
		taskNumber = inputInt(1, 5);
		
		// Когда пользователь вводит номер задания и соответствующий case реазилуется, после этого работа главной функции не завешается и это может привести к ошибкам.
		// Поэтому сразу как только функция - задание выполнится, будет выход из switch.
		switch (taskNumber) {
			case 1: task1(); break;
			case 2: task2(); break;
			case 3: task3(); break;
			case 4: task4(); break;
			case 5: task5(); break;
		}

		cout << "\n\n\n\n\n----------------Вы вышли в главное меню----------------\n\n\n\n\n" << endl;
	}
}