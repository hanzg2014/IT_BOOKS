//Exercise 1_14
//Page 24

#include <stdio.h>
#define ARRAY_SIZE 128

// int transpose(int i){
// 	switch(i){
// 		case 7:	return '\a';
// 		break;
// 		case 127:

// 	}

// }

int main(){
	int c, i, j;
	int nc[ARRAY_SIZE];

	for (i = 0; i < ARRAY_SIZE; i++)
		nc[i] = 0;

	//there only one line of expression within the while-loop scope
	while((c = getchar())!=EOF)
		++nc[c];
		
	printf("\nASCII|Histogram	(Frequencies)\n");
	for (i = 0; i < ARRAY_SIZE; i++){
		if(nc[i]>0){
			printf("%5d| ", i);
			// printf("%3d %c: %4d ", i, i, nc[i]);
			for(j = 0; j < nc[i]; j++)
				printf("%c", '#');
			printf("	(%d)", nc[i]);
			putchar('\n');
		}
	}
}


  // 转义字符 意义 ASCII码值(十进制) 
  // \a 响铃(BEL) 007 
  // \b 退格(BS) 008 
  // \f 换页(FF) 012 
  // \n 换行(LF) 010 
  // \r 回车(CR) 013 
  // \t 水平制表(HT) 009 
  // \v 垂直制表(VT) 011 
  // \\ 反斜杠 092 
  // \? 问号字符 063 
  // \' 单引号字符 039 
  // \" 双引号字符 034 
  // \0 空字符(NULL) 000 
