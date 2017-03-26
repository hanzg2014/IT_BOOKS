#include <stdio.h>

int main(void){
	

//P16 getchar()	#1
	/*
	int c;
	c = getchar();
	while(c != EOF){
		putchar(c);
		c = getchar();
	}
	*/

//P17 getchar() #2
	/*
	int c;
	while((c = getchar()) != EOF){
		putchar(c);
	}
	*/

	printf("hello, \c world\n");
	printf("Audible or visual alert. \a\n");
	printf("Form feed. \f");
	printf("This escape, \r, moves the active position to the initial position of the current line.\n")
	printf("Vertical tab \v is tricky, as its behaviour is unspecified under certain conditions.\n");
	return 0;
}




/*
//P8 Fahrenheit to Celsius



*/
