#include <stdio.h>

int main()
{
    int c;
        
        while ((c = getchar()) != EOF){
            putchar(c);             
            if (c == ' '|| c == '\t'){
                 printf("\n");       /* or putchar('\n'); */
            }
        }
        return 0;
}