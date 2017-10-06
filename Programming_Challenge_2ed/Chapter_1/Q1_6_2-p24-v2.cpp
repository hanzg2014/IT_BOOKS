//Example 1_6_2-v2 (with direction added)
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

void print_direction(int* dir, int n){
	printf("Directions: ");
	for(int i = 0; i < n; i++){
		if (dir[i]== -1)
			printf("Left ");
		else
			if (dir[i] == 1)
				printf("Right ");
			else
	 			printf("Either ");
	}
	printf("\n");
}

//The hypothesis is that x[n+1] is to the right side of x[n] on the rod with a length of L
int main(){   
	int L, n, x[MAX_N];
	int dir[MAX_N];
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
		if (x[i]<= L/2){
			dir[i] = -1;
		}
		else{
			dir[i] = 1;
		}
		maxT = max(maxT, max(x[i], L - x[i]));
	}

//Are there better method for deciding the directions?
//What are the default values for C++ int arrays?

	printf("\n");
	printf("Minimum time is %ds\n", minT);
	print_direction(dir, n);

	printf("Maximum time is %ds\n", maxT);
	if (L-x[0] >= x[n])
		dir[0] = 1;
	else
		dir[n] = -1;
	print_direction(dir, n);
	clock_t end = clock();

	printf("\nRunning time is %fs\n", (double)(end - start)/CLK_TCK);
	return 0;
}
