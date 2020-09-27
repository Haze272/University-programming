#include <iostream>
#include <string>
#include <limits>
#include <string_view>

using namespace std;

int GetIntFromCin(string_view prompt) {
    double input{ 0x0 };
    while (true) {
        input = 0x0;
        cout << prompt << " : " << flush;
        if ((cin >> input).good()) {
            if (input == static_cast<int>(input)) {
                break;
            }
            cout << endl << "You Inter a Float or Double! Try agane!" << endl << flush;
        }
        if (cin.fail()) {
            cin.clear();
            cout << endl << "Wrong Retry please:" << endl << flush;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return static_cast<int>(input);
}

int GetIntFromCinWithLimits(string_view prompt, int min = numeric_limits<int>::min(), int max = numeric_limits<int>::max()) {
    int ret{ 0 };
    while (true) {
        ret = GetIntFromCin(prompt);
        if (ret < min || ret > max) {
            cout << endl << "Wrong By limits!" << endl << flush;
            continue;
        }
        break;
    }

    return ret;
}

int main() {
    int val = GetIntFromCinWithLimits("Enter nun", 0, 100);
    cout << "You enter a " << val << endl;

    return 0;
}