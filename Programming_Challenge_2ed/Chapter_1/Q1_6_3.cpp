#include <cstdio>
#include <ctime>

const int MAX_N = 50;
#define CLK_TCK  CLOCKS_PER_SEC

void PrintIntArray(int *k, int n){
	printf("{");
	for(int i = 0; i < n - 1; i++){
		printf("%d, ",k[i]);	
	}
	printf("%d}\n",k[n - 1]);
}

void InsertionSort(int *k, int n){
	int key;
	int i;
	for(int j = 1; j < n; j++){
		key = k[j];
		i = j - 1;
		while(i >= 0 && key < k[i]){
			k[i + 1] = k[i];
			i--;
		}
		k[i + 1] = key;
	}
}

bool BinarySearch(int *k, int n, int x){
	int i, l = 0, r = n - 1;
	while(r >= l){
		i = l + (r - l)/2;
		if(x < k[i]){
			r = i - 1;
		}
		else{
			if(x > k[i]){
				l = i + 1;
			}
			else{
				return true;
			}
		}
	}
	return false;
}

int main(){   

	int n, m, k[MAX_N];
	int v;
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

	InsertionSort(k, n);
	for(int a = 0; a < n; a++){
		if(flag)
			break;
		for(int b = 0; b < n; b++){
			if(flag)
				break;
			for(int c = 0; c < n; c++){
				if(BinarySearch(k, n, m - k[a] - k[b] - k[c])){
					flag = true;
					puts("It is possible");
					printf("%d + %d + %d + %d = %d\n", k[a], k[b], k[c], (m - k[a] - k[b] - k[c]), m);
					break;
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