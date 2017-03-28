//Example 1_6_2
//Page 24

#include <cstdio>
#include <ctime>

const int MAX_N = 1000000;
const int MAX_LEN = 1000000;
#define CLK_TCK  CLOCKS_PER_SEC

int max(int a, int b){
	if (a >= b){
		return a;
	} 
	else{
		return b;
	}
}

int min(int a, int b){
	if (a <= b){
		return a;
	} 
	else{
		return b;
	}
}

int main(){   
	int L, n, x[MAX_N], y[MAX_N];
	int maxT = 0;
	int minT = 0;

	printf("L: ");
	scanf("%d",&L);
	printf("n: ");
	scanf("%d",&n);

	for(int i = 0; i < n; i++){
		printf("0 <= x[%d] <= %d: ",i,L);
		scanf("%d",&x[i]);
	}

	clock_t start = clock();

	for(int i = 0; i < n; i++){
		minT = max(minT, min(x[i], L - x[i]));
		maxT = max(maxT, max(x[i], L - x[i]));
	}

	printf("Maximum time is %ds, minimum time is %ds\n", maxT, minT);

	clock_t end = clock();
	printf("Running time is %fs\n", (double)(end - start)/CLK_TCK);
	return 0;
}
