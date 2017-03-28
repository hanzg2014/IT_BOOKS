//Ex1_19
//Page 31

#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char to[], char from[], int len);

int main(){	
	int len;

	char line[MAXLINE];
	char reversed[MAXLINE];

	while((len = get_line(line, MAXLINE)) > 0){	//ignore the null string
		reverse(reversed, line, len);
		printf("\nReversed string: %s", reversed);
		putchar('\n');
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

void reverse(char to[], char from[], int len_from){
	int i, range;

	if (from[len_from - 1] == '\n')		//if the original string ends with a '\n'
		range = len_from - 1;
	else	//if the original string ends with an EOF
		range = len_from;

	for(i = 0; i < range; i++)
		to[range - 1 - i] = from[i];	//copy the original string in reversed order
	to[range] = '\0';	//end the new string with a '\0'
}

