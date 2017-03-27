//Exercise 1_13 
//P24

#include <stdio.h>
#include <assert.h>

#define IN 1
#define OUT 0
#define MAX_WORD_LEN 10

int main(){
	int c, i, j, l, state;
	int nlength[MAX_WORD_LEN + 1];

	state = OUT;
	l = 0;

	for (i = 0; i < MAX_WORD_LEN + 1; i++)
		nlength[i] = 0;

	while((c = getchar())!=EOF){
		if(c == '\t'|| c == ' '||c == '\n'){
			++nlength[l];
			state = OUT;
			l = 0;
		}
		else{
			++l;
			assert(l <= MAX_WORD_LEN);	//to ensure that the length of anywords will not surpass the preset maximum word length
			state = IN;
		} 
	}

	printf("\n|Len|Histogram	(Count)\n");
	for (i = 0; i < MAX_WORD_LEN + 1; i++){
		printf("|%3d|", i);
		for(j = 0; j < nlength[i]; j++)
			printf("%c", '#');
		printf("	(%d)", nlength[i]);
		putchar('\n');
	}
	printf("\n");
}


