//Ex1_16
//Page 30

#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main(){	
	int len;
	int max;
	int agg;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	agg = 0;
	while((len = get_line(line, MAXLINE)) > 0){
		agg = agg + len;
		if(len > max){
			max = len;
			copy(longest, line);
		}
	}

	putchar('\n');
	if(max > 0){
		printf("\nText total length: %d", agg);
		printf("\nLongest line: %s\nLength: %d\n", longest, max);
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

void copy(char to[], char from[]){
	int i;

	i = 0;
	while((to[i] = from[i])!='\0')
		++i;
}


