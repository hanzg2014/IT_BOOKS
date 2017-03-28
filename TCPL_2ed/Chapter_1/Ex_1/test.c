#include <stdio.h>

#define TABSIZE 10   // 定义一个tab为10个size
#define MAX_BUFFER 1000
#define SPACE '-' //为了显示方便，这里用‘-’ 代替空格‘ ’

int CaculatorTabLength(int l, int tabsize) //计算组成一个tab缺少的SPACE个数
{
   return(tabsize - l%tabsize); //这儿取余数是这个算法的核心，耐心瞅瞅o(∩∩)o..
}

int mgetline(char s[], int lim)
{ 
   int c, i;
   for(i = 0; i < lim-1 && (c=getchar())!=EOF && c!='\n';i++)
         s[i] = c;
   if(c == '\n')
   {
      s[i] = '\n';
       i++;
   }
   s[i] = '\0';
   return i;
}

int main(void)
{
   int len;
   char line[MAX_BUFFER];
   while(len = mgetline(line,MAX_BUFFER))
   {
       int i,j,l,t;
       for(i = 0, i = 0; i < len; i++)
       { 
            if(line[i] == '\t')
            {
                 j = CaculatorTabLength(l,TABSIZE);
                 for(t = 0; t < j; t++)
                  {
                       putchar(SPACE);
                       l++;
                    }
             }
            else
              {
                    putchar(line[i]);
                    l++;
                }
       }
   }
    return 0;
}