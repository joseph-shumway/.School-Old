#include <iostream>
#include "functions.h"

using std::cout;
using std::cin;
using std::endl;

bool running = true;
int num1;
int num2;


int main() {
	
	// TODO(student): print prompt for input
	/*
	int asdf = 0;

	cin >> asdf;

	cout << classify_mv_range_type(asdf) << endl;
	exit(0);
	*/

	while (running) {
		cout << "Enter numbers 10 <= a <= b < 10000: ";
		cin >> num1;
		cin >> num2;

		if (!is_valid_range(num1, num2)) {
			cout << "Invalid Input" << endl;
		}
		else {
			running = false;
		}
	}
		count_valid_mv_numbers(num1, num2);

	//}
	
	// TODO(student): read the numbers from standard input

	// TODO(student): validate input (and reprompt on invalid input)

	// TODO(student): compute and display solution
	
	return 0;
}