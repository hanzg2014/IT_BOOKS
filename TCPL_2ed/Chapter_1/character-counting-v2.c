//character counting program (double float version)
//P18

#include <stdio.h>

int main(){
	double nc;

	for(nc = 0.0; getchar()!=EOF; ++nc)
		;
	printf("\n");
	printf("%.0f\n",nc);
}

