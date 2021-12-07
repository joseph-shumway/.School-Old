#include <iostream>
#include "functions.h"

using std::cout;
using std::endl;

bool is_valid_range(int a, int b) {
	// TODO(student): validate input range
	if (a >= 10 && a <= b) {
		if (b < 10000) {
			return true;
		}
	}

	return false;
}

char classify_mv_range_type(int number) {
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise

	int x = number;
	int digit = 0;
	int lastDigit = 0;
	int slope = 0;
	int lastSlope = 0;

	lastDigit = x % 10;
	x /= 10;
	digit = x % 10;

	if (digit > lastDigit) {slope = -1;}
	else if (digit < lastDigit) {slope = 1;}
	else if (digit == lastDigit) {return 'N';}

	//cout << "1st--  lastSlope: " << lastSlope << "    slope: " << slope << "   digit: " << digit << "   lastDigit: " << lastDigit << "    x: " << x << endl;
	

	while (x >= 10) {
		lastDigit = digit;
		lastSlope = slope;

		x /= 10;
		digit = x % 10;
		

		

		if (digit > lastDigit) {
			slope = -1;;
		}
		if (digit < lastDigit) {
			slope = 1;
		}

		//cout << "       lastSlope: " << lastSlope << "    slope: " << slope << "   digit: " << digit << "   lastDigit: " << lastDigit << "    x: " << x << endl;
		
		if (digit == lastDigit) {return 'N';}

		if (slope == lastSlope) {return 'N';}


	}

	if (slope == -1) {return 'V';}
	if (slope == 1) {return 'M';}

	return 'N';
	
}

void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt

	int valleys = 0;
	int mountains = 0;
	char letter = 'a';
	int x = 0;

	for (int i = a; i <= b; i++) {
		letter = classify_mv_range_type(i);
		
		if (letter == 'M') {mountains++;}
		else if (letter == 'V') {valleys++;}
		x++;
		// cout << 'n';

	}
	cout << "There are " << mountains << " mountain ranges and "  << valleys << " valley ranges between " << a << " and " << b << "." << endl;


}