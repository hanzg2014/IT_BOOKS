//Ex1_20
//Page 34

#include <stdio.h>
#define MAXLINE 1000
#define TABSIZE 10
#define TAB '\t'
#define SPACE ' '

char line[MAXLINE];
char complete[MAXLINE];

int get_line(char line[], int maxline);
void space_complete(char to[], char from[], int len_from);

int calculate_space(int pos, int tabsize){	//count how many spaces left until the next TAB stop		
	return (TABSIZE - pos % TABSIZE);
}

int main(){	
	int len;	
	while((len = get_line(line, MAXLINE)) > 0){
		if (len > 0){	//ignore the null string
			int i, j, l, k;
			for(i = 0, l = 0; i < len; i++){
				if(line[i] == '\t'){
					j = calculate_space(l, TABSIZE);
					for (k = 0; k < j; k++){
						putchar('-');
						l++;
					}
				}
				else{
					putchar(line[i]);
					l++;
				}
			}
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
