//Exercise 1_12
//P21

#include <stdio.h>

#define IN 1
#define OUT 0

int main(){
	int c, state;

	state = OUT;

	while((c = getchar())!=EOF){
		if(c == '\t'|| c == ' '||c == '\n'){
			if(state == IN)
				putchar('\n');
			state = OUT;
		}
		else{
			state = IN;
			putchar(c);
		}
	}
	printf("\n");
}

// int main()
// {
//     int c;
        
//         while ((c = getchar()) != EOF){
//             putchar(c);             
//             if (c == ' '|| c == '\t'){
//                  printf("\n");       /* or putchar('\n'); */
//             }
//         }
//         return 0;
// }

