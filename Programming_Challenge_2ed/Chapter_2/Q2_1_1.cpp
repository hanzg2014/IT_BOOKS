#include <cstdio>
#include <ctime>
#define MAX_N 50
#define CLK_TCK  CLOCKS_PER_SEC

int memo[MAX_N + 1];

int fact(int n){
	if (n == 0)	return n;
	return (n * fact(n - 1));
}


int fib(int n){
	if (n <= 1)	return n;
	if (memo[n] != 0) return memo[n];
	return (memo[n] = fib(n - 1) + fib(n - 2));
}
	
int main(){

	clock_t start = clock();
	printf("%d\n", fib(25));


	clock_t end = clock();
	printf("Running time is %fs\n", (double)(end - start)/CLK_TCK);
	return 0;
}