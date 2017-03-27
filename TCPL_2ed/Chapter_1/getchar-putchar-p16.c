//getchar-putchar
//P16
		
#include <stdio.h>

int main(void){
	
	int c;
	c = getchar();
	while(c != EOF){
		putchar(c);
		c = getchar();
	}
	return 0;
}

