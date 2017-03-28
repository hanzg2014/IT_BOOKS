//Ex1_22
//Page 34

#include <stdio.h>
#define MAXLINE 1000
#define LINEFOLD 80 //it seems that one line in Mac's default sized termianl can hold about 80 characters

#define IN 1
#define OUT 0

char line[MAXLINE];
char folded[MAXLINE];

int get_line(char line[], int maxline);
void fold(char to[], char from[], int len_from);

int main(){    
    int len;    
    while((len = get_line(line, MAXLINE)) > 0){
        if (len > 0)   //ignore the null string
            fold(folded, line, len);
        else
            printf("\nnull string\n");
    }
    return 0;
}

int get_line(char s[], int lim){
    int c, i;

    for(i = 0; i < lim - 1 && (c = getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;

    if(c == '\n'){
        s[i] = c;
        ++i;
    }

    s[i] = '\0';
    return i;
}

void fold(char to[], char from[], int len_from){
    int i, j, k, l, state;    //(absolute)i, index of from[];    j, number of consecutive blanks
    j = 0; //(relative)position of characters in the folded[]
    k = -1; //(relative)last tail, index of the final character of the most recently processed word
    l = 0; //(relative)current head, index of the first character of the word currently under processing

    for(i = 0, j = 0, k = -1, l = 0, state = OUT; i < len_from; i++){
        if (j < LINEFOLD ){ //still within one line
            if ((from[i]!=' ') && (from[i]!='\t')){
                if (state == OUT)
                    l = j;
                state = IN;
                to[j] = from[i];
                j++;
            }
            else{
                if (state == IN)
                    k = j - 1;
                state = OUT;
                to[j] = from[i];
                j++;
            }
        }  
        else{
            k++;
            to[k] = '\n';
            k++;
            to[k] = '\0';
            j = 0;
            k = -1;
            l = 0;
            state = OUT
            printf("\n%s", to);
        }
    }
    to[j] = '\0';   //final line of the folded lines
}



