#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main () {

    int inputNum = 0;


    cout << "Input number: ";
    cin >> inputNum;

    int number = inputNum;
    int last = 0;
    int total = 0;

    //loop through number until all the digits have been processed
    while (number > 1) {
        last = number % 10;
        if (last % 2 == 0) {
            total += last;
            //cout << "Total: " << total << endl;
        }

        // if the first digit is 7, return 0
        if ((last == 7) && (number < 10)) {
            cout << "Total: 0" << endl << endl << endl;
            exit(0);
        }
        number /= 10;
        //cout << "Number: " << number << endl;

    }

    cout << "Total: " << total << endl << endl << endl;

    return 0;
}