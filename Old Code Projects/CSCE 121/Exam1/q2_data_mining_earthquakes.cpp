#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int test[10] = { -12, 2, -2, 3, 5, -4, 78, -3, 19, 33};
	// the largest difference between values should be 82
	unsigned int answer = 0;
	int maxSum = 0;
	int sum = 0;


	// loop and compare 
	for (int i = 1; i < 10; i++)
	{
		// get the abs value of the difference
		sum = abs(test[i]) + abs(test[i-1]);

		// get the max of all the differences
		if (sum > maxSum) {
			maxSum = sum;
		}
	}
	
	// output the result
	cout << "Max Earthquake Difference: " << maxSum << endl << endl << endl;

	return 0;	
}
