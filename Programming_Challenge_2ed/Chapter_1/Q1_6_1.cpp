#include <cstdio>
#include <ctime>

const int MAX_N = 100;
const int MIN_N = 5;
#define CLK_TCK  CLOCKS_PER_SEC

int max(int a, int b){
	if (a >= b){
		return a;
	} 
	else{
		return b;
	}
}

int main(){   
	int n, k[MAX_N];
	int ans = 0;
	int ma = 0;
	int len = 0;
	int res = 0;
	int result[3];
	printf("n: ");
	scanf("%d",&n);

	for(int i = 0; i < n; i++){
		printf("k[%d]: ",i);
		scanf("%d",&k[i]);
	}

	clock_t start = clock();

	for(int a = 0; a < n - 2; a++){
		for(int b = a + 1; b < n - 1; b++){
			for(int c = b + 1; c < n; c++){
				len = k[a] + k[b] + k[c];
				ma = max(k[a], max(k[b],k[c]));
				res = len - ma;
				if (res > ma){
					ans = len;
					result[0] = k[a];
					result[1] = k[b];
					result[2] = k[c];
				}
			}
		}
	}

	if(ans == 0)
		printf("No valid triangle\n");
	else
		printf("The largest length is %d with {%d, %d, %d}\n", ans, result[0], result[1], result[2]);

	clock_t end = clock();
	printf("Running time is %fs\n", (double)(end - start)/CLK_TCK);
	return 0;
}
