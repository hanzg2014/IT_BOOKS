#include <stdio.h>
#define MAXLINE 1000
#define TABSIZE 4
int gline(char line[]);
int main()
{
    int i, j, len, ns;
    char line[MAXLINE];
    while ((len = gline(line)) > 0) {
        for (i = 0, j = 0, ns = 0; j < len; j++)
            if (line[j] != ' ') {o
                while (ns > 0) {
                    line[i++] = ' ';
                    ns--;
                }
                line[i++] = line[j];
            }
            else {
                ns++;
                if (ns == TABSIZE) {
                    line[i++] = '\t';
                    ns = 0;
                }
            }
        while (ns > 0) {
            line[i++] = ' ';
            ns--;
        }
        line[i++] = 0;
        printf("%s", line);
    }
    return 0;
}
int gline(char line[])
{
    int c, i;
    for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}