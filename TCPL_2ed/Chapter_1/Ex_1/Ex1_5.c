//Exercise 1-5
//Listed in Page 14

#include <stdio.h>

int main()
{
	int fahr;
	printf("\n%s\t%s\n", "F", "C");
	for(fahr = 300; fahr >= 0; fahr = fahr -20)
		printf("%3d\t%5.1f\n", fahr, (5.0/9.0) * (fahr - 32));
	return 0;
}