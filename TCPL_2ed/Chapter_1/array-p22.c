//array program 
//P22

#include <stdio.h>

int main(){
	int c, i, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; i++)
		ndigit[i] = 0;

	//there only one line of expression within the while-loop scope
	while((c = getchar())!=EOF)
		if(c >= '0' && c <= '9')
			++ndigit[c-'0'];
		else if(c == '\t'|| c == ' '||c == '\n')
			++nwhite;
		else
			++nother;

	printf("digits: ");
	for (i = 0; i < 10; i++)
		printf(" %d", ndigit[i]);
	printf(", whitespaces: %d, others: %d\n", nwhite, nother);
}


