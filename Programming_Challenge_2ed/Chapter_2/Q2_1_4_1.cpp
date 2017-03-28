#include <cstdio>
#define MAX_N 20

//minuend
int n, k, a[MAX_N];

bool DFS(int i, int minuend){
	if(i == n) return (minuend == 0);
	if(DFS(i + 1, minuend)) return true;
	if(DFS(i + 1, minuend - a[i])) return true;
	return false;
}

int main(){
	printf("n: ");
	scanf("%d",&n);
	printf("k: ");
	scanf("%d",&k);

	for(int i = 0; i < n; i++){
		printf("a[%d]: ",i);
		scanf("%d",&a[i]);
	}

	if(DFS(0, k)){
		printf("It is possible\n");
	}
	else{
		printf("It is impossible\n");
	}

	return 0;
}