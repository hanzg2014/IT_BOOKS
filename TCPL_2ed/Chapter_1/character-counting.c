//character counting program (long int version)
//P17

#include <stdio.h>

int main(){
	long nc;

	nc = 0;
	while(getchar()!= EOF)
		++nc;
	printf("\n");
	printf("%ld\n",nc);
}

