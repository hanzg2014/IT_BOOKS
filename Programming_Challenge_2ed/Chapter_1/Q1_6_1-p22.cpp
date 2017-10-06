//Example 1_6_1 "三角形"
//Page 22

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
	int n, a[MAX_N];
	int ans = 0;

	printf("n: ");
	scanf("%d",&n);

	for(int i = 0; i < n; i++){
		printf("a[%d]: ",i);
		scanf("%d",&a[i]);
	}

	clock_t start = clock();

	for(int i = 0; i < n - 2; i++){
		for(int j = i + 1; j < n - 1; j++){
			for(int k = j + 1; k < n; k++){
				int len = a[i] + a[j] + a[k];
				int max_len = max(a[i], max(a[j],a[k]));
				int rest = len - max_len;

				if (rest > max_len)
					ans = max(ans, len);
			}
		}
	}

	if(ans == 0)
		printf("No valid triangle\n");
	else
		printf("The longest perimeter is %d\n", ans);

	clock_t end = clock();
	printf("Running time is %fs\n", (double)(end - start)/CLK_TCK);
	return 0;
}
