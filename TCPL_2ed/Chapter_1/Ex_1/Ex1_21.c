//Ex1_20    
//Page 34

#include <stdio.h>
#define MAXLINE 1000
// #define TABSIZE 4   //'\t' occupies 4 blanks in sublime
#define TABSIZE 8   //'\t' occupies 8 blanks in terminal

char line[MAXLINE];
char result[MAXLINE];

int get_line(char line[], int maxline);
int calculate_blanks(int pos, int len_blanks, int tabsize);
int calculate_tabs(int pos, int len_blanks, int tabsize);
void entab(char to[], char from[], int len_from);

int main(){    
    int len;    
    while((len = get_line(line, MAXLINE)) > 0){
        if (len > 0){    //ignore the null string
            entab(result, line, len);
            printf("\n%s", result);
        }
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

// nt = (pos % tabsize + j) / tabsize //number of TABs needed
// i - nt * tabsize  //number of blanks still needed


int calculate_blanks(int pos, int len_blanks, int tabsize){    //count how many blanks are neededß
    if (pos % tabsize <= len_blanks)
        return pos % tabsize;
    else
        return len_blanks;
}

int calculate_tabs(int pos, int len_blanks, int tabsize){    //count how many blanks are needed
    if (pos % tabsize <= len_blanks)
        return (len_blanks - pos % tabsize) / tabsize + 1;
    else
        return 0;
}

void entab(char to[], char from[], int len_from){
    int i, j, k, l, m, n;    //i, index of from[]; j, number of consecutive blanks
    for(i = 0, j = 0, k = 0, l = 0; i < len_from; i++){
        if(from[i] == ' '){    
            j++;
        }
        else{
            if(j > 0){
                l = calculate_blanks(i, j, TABSIZE);  //l, number of blanks needed  
                m = calculate_tabs(i, j, TABSIZE);    //m, number of TABs needed 
                
                for (n = 0; n < m; n++){    //n, number for count
                    to[k] = '\t';
                    k++;
                }

                for (n = 0; n < l; n++){    //
                    to[k] = '-';
                    k++;
                }

                j = 0;
            }
            to[k] = from[i];
            k++;
        }
    }
    to[k] = '\0';
}

