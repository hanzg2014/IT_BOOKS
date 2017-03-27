//the temperature conversion program (floating-point version)
//listed in Page 12

#include <stdio.h>

int main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	fahr = lower;
	while(fahr <= upper){
		celsius = (5.0/9.0) * (fahr - 32);
		printf("%3.0f\t%6.1f\n", fahr, celsius);
		// printf("%3.f\t%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
	return 0;
}