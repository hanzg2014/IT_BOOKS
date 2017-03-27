//line counting program (long int version)
//P19

#include <stdio.h>

int main(){
	int c, nl;
	nl = 0;
	while((c = getchar())!=EOF)
		if(c == '\n') ++nl;
	printf("\n");
	printf("%d\n",nl);
}

