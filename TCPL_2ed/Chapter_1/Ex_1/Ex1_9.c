//Exercise 1-9
//Page 19

#include <stdio.h>

int main(){
	int c, nb; 
	nb = 0;

	while((c = getchar())!=EOF){
		if(c == ' '){
			if(nb == 0){
				putchar(c);
				++nb;
			}
		}
		if(c != ' '){
			putchar(c);
			nb = 0;
		}
	}
}

