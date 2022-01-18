//#include <stdio.h>
int compute(int a, int b)
{
 	int result = 1;
 	while (a < b) {
		result *= (a+b);
		a++;
	}
	return result;
}

 int main(void)
 {
    int number;
	number = compute(4,6);
	//printf("number = %d\n", number);
 }