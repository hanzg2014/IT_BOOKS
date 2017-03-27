//Ex1_17
//Page 31

#include <stdio.h>
#define MAXLINE 1000
#define THRESHOLD_LENGTH 80

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main(){	
	int len;
	char line[MAXLINE];

	while((len = get_line(line, MAXLINE)) >= 0)
		if (len > 0)
			printf("\n%s\n", line);
	return 0;
}

int get_line(char s[], int lim){
	int c, i, state, in;

	state = OUT;
	for(i = 0, in = -1; i < lim - 1 && (c = getchar())!=EOF && c!='\n'; ++i){
		s[i] = c;
		if((c != '\t') && (c !=' '))
			in = i;
	}

	s[in + 1] = '\n';
	s[in + 2] = '\0';
	return in + 1;
}

