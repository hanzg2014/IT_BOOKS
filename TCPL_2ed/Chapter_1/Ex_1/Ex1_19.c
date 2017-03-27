//Ex1_19
//Page 31

#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char s[]);
void switch(char a, char b);
void copy(char to[], char from[]);


int main(){	
	int len;

	char line[MAXLINE];
	char reversed[MAXLINE]

	while((len = get_line(line, MAXLINE)) > 0)
		for (int i = 0; i <= (len - 1) / 2)
			reversed[i] = line[len - 1 - i]
		if(len >= 80){
			printf("\n%s\n", line);
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

void reverse(char s[]){

}

void copy(char to[], char from[]){
	int i;

	i = 0;
	while((to[i] = from[i])!='\0')
		++i;
}


