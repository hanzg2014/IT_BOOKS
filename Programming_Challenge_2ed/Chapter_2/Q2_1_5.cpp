#include <cstdio>
#define MAX_M 100
#define MAX_N 100

int M, N;
int tmp, total = 0;
char field[MAX_M][MAX_N];

void DFS(int x, int y){
	field[x][y] = '.';
	for(int dx = -1; dx <= 1; dx++){
		for(int dy = -1; dy <= 1; dy++){
			//nxではなく, xでもいけそう
			int nx = x + dx;
			int ny = y + dy;
			if((nx >= 0) && (nx < M) && (ny >= 0) && (ny <= N) && (field[nx][ny] == 'W')){
				DFS(nx, ny);
			}
		}
	}
	return;
}

int main(){
	printf("M: ");
	scanf("%d",&M);
	printf("N: ");
	scanf("%d",&N);

	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			printf("[%d][%d] (1: Water; 2: '.')", i + 1, j + 1);
			scanf("%d",&tmp);
			if(tmp == 1)
				field[i][j] = 'W';
			else
				field[i][j] = '.';
		}
	}

	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			printf("%c",field[i][j]);
		}
		printf("\n");
	}

	for(int i = 0; i < M; i++){
		for(int j = 0; j < N; j++){
			if(field[i][j] == 'W'){
				DFS(i, j);
				total++;
			}
		}
	}

	printf("%d\n", total);

	return 0;
}