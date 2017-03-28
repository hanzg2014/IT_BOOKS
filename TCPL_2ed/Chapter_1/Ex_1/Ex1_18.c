//Ex1_18
//Page 31

#include <stdio.h>
#define MAXLINE 1000
#define THRESHOLD_LENGTH 80

int get_line(char line[], int maxline);
void remove_trailing(char to[], char from[], int len_from);

int main(){	
	int len;
	char line[MAXLINE];
	char removed[MAXLINE];  

	while((len = get_line(line, MAXLINE)) > 0){
		//printf("\n%s\n", line);
		if (len == 1)
			printf("only newline");
		remove_trailing(removed, line, len);
		printf("\n%s\n", removed);
	}
	if (len == 0)
		printf("\nNull string!\n");
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

void remove_trailing(char to[], char from[], int len_from){
	int i, in;
	for(i = 0, in = -1; i < len_from; ++i){
		to[i] = from[i];
		if((from[i] != '\t') && (from[i] !=' ')&& (from[i] !='\n'))
			in = i;
	}

	++in;
	if (from[len_from - 1] == '\n'){
		to[in] = '\n';
		++in;
	}
	to[in] = '\0';  
}


