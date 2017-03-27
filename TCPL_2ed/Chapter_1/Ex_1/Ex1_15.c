//Exercise 1_15
//Page 27

#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float fc_conversion(float fahr){
	return (5.0/9.0) * (fahr - 32);
}

int main(){
	int fahr;
	int lower, upper, step;

	printf("\n%s\t%s\n", "F", "C");
	for(fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
		printf("%3d\t%5.1f\n", fahr, fc_conversion(fahr));
	return 0;
}
