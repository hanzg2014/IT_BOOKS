//Exercise 1-4
//Listed in Page 13

#include <stdio.h>

int main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = -17;
	upper = 148;
	step = 11;

	celsius = lower;
	printf("\n%s\t%s\n", "Celsius", "Fahrenheit");
	while(celsius <= upper){
		fahr = (9.0/5.0) * celsius + 32;
		printf("%3.0f\t%6.1f\n", celsius, fahr);
		celsius = celsius + step;
	}
	return 0;
}