//power function program 
//P24

#include <stdio.h>

int power(int m, int n);

int main(){
	int i;
	printf("\nn power(2, n) power(-3, n)\n");
	for(i = 0; i < 10; ++i)
		printf("%d	%d	%d\n", i, power(2, i), power(-3, i));
	return 0;
}

int power(int base, int n){
	int i, p;
	p = 1;
	for(i = 1; i <= n; ++i)
		p = p * base;
	return p;
}


