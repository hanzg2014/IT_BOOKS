#include <cstdio>
#include <ctime>

const int MAX_N = 50;
#define CLK_TCK  CLOCKS_PER_SEC

int main(){   

	int n, m, k[MAX_N];
	bool flag = false;
	printf("n: ");
	scanf("%d",&n);
	printf("m: ");
	scanf("%d",&m);

	for(int i = 0; i < n; i++){
		printf("k[%d]: ",i);
		scanf("%d",&k[i]);
	}

	clock_t start = clock();
	for(int a = 0; a < n; a++){
		if(flag)
			break;
		for(int b = 0; b < n; b++){
			if(flag)
				break;
			for(int c = 0; c < n; c++){
				if(flag)
					break;
				for(int d = 0; d < n; d++){
					if(k[a] + k[b] + k[c] + k[d] == m){
						flag = true;
						puts("It is possible");
						break;
					}
				}
			}
		}
	}
	if(!flag)
		puts("It is impossible");

	clock_t end = clock();
	printf("Running time is %fs\n", (double)(end - start)/CLK_TCK);
	return 0;
}