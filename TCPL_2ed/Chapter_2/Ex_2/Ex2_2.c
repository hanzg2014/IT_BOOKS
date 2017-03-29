//Ex2_2    
//Page 42

#include <stdio.h>

#define MAXLINE 1000




int main(){   

    int c; 
    char s[MAXLINE];

    int i = 0;
    int lim = MAXLINE;

    while(i < lim -1){
        c = getchar();
        if(c == '\n')
            break;
        if(c == EOF)
            break;
        s[i] = c;
        i++;
    }

    printf("%s\n", s);

    return 0;
}
