#include <cstdio>
#define MAX_N 20


int n, k, a[MAX_N];

bool DFS(int i, int sum){
	if(i == n) return (sum == k);
	if(DFS(i + 1, sum)) return true;
	if(DFS(i + 1, sum + a[i])) return true;
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

	if(DFS(0, 0)){
		printf("It is possible\n");
	}
	else{
		printf("It is impossible\n");
	}

	return 0;
}