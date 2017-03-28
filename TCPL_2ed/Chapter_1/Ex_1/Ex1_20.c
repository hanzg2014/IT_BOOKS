//Ex1_20	
//Page 34

#include <stdio.h>
#define MAXLINE 1000
#define TABSIZE 10

char line[MAXLINE];
char result[MAXLINE];

int get_line(char line[], int maxline);
int calculate_space(int pos, int tabsize);
void detab(char to[], char from[], int len_from);

int main(){	
	int len;	
	while((len = get_line(line, MAXLINE)) > 0){
		if (len > 0){	//ignore the null string
			detab(result, line, len);
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

int calculate_space(int pos, int tabsize){	//count how many spaces left until the next TAB stop		
	return (TABSIZE - pos % TABSIZE);
}

void detab(char to[], char from[], int len_from){
	int i, j, l, k;	//i, index of from[]; j, number of ' ' still need to be filled in the current segmentation; l, index of to[]; k, count need to input ' '
		for(i = 0, l = 0; i < len_from; i++){
			if(from[i] == '\t'){	
				j = calculate_space(l, TABSIZE);	//calculate how many spaces are still needed to be filled
				for (k = 0; k < j; k++){
					to[l] = '-';//print '-' for a corresponding number of times; use '-' instea of ' ', in order to make the result more obvious
					l++;
				}
			}
			else{
				to[l] = from[i];
				l++;
			}
		}
		to[l] = '\0';
}
