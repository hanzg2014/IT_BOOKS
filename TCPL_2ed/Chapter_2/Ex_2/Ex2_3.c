//Ex2_3  
//Page 46

#include <stdio.h>

int htoi(char s[]);

int main(void)
{
	char s[] = "0aa"; //string to be tested

    printf("\"%s\" is %d\n", s, htoi(s));
    return 0;
}

int htoi(char s[]){
	int i;
	int n;
	int res = 0;

	//for the optional part of '0x' or '0X'
	if ((s[0] == '0') && ((s[1] == 'x')||(s[1] == 'X')))
		i = 2;
	else 
		i = 0;
		
	for(; s[i]!='\0'; i++){
		if (s[i]<= 'F' && s[i] >= 'A')	
			n = s[i] - 'A' + 10;
		else if (s[i]<= 'f' && s[i] >= 'a')
			n = s[i] - 'a' + 10;
		else if (s[i]<= '9' && s[i] >= '0')
			n = s[i] - '0';
		else
			return -1;
		res = res * 16 + n;
	}
	return res;
}
