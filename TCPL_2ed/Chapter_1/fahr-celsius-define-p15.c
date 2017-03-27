//the temperature conversion program using #define
//Listed in Page 15

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
	int fahr;
	printf("\n%s\t%s\n", "F", "C");
	for(fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3d\t%5.1f\n", fahr, (5.0/9.0) * (fahr - 32));
	return 0;
}