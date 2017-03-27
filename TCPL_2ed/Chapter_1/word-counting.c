//word counting program 
//P20

#include <stdio.h>

#define IN 1
#define OUT 0

int main(){
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;

	while((c = getchar())!=EOF){
		++nc;
		if(c == '\n') 
			++nl;
		if(c == '\t'|| c == ' '||c == '\n')
			state = OUT;
		else if(state == OUT){
			state = IN;
			++nw;
		}
	}

	printf("\n");
	printf("lines: %d\nwords: %d\ncharacters: %d\n",nl,nw,nc);
}

