#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getLine(char line[], int maxline);

void copy(char to[], char from[]);

void reverse(char to[], char from[], int len);

/* print the longest input line */
void main()
{
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char rev[MAXLINE];  /* longest line saved here */

    max = 0;
    while((len = getLine(line, MAXLINE)) > 0){
        reverse(rev, line, len);
        printf("%s\n", rev);
    }

    return 0;
}

/* getline: read a line into s, return length */
int getLine(char s[], int lim)
{
    int c, i;

    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/* copy: copy 'from' into 'to'; assume 'to' is big enough */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}
/* reverse: reverse 'from' to 'to'; assume 'to' is big enough */
void reverse(char to[], char from[], int len)
{
    int i, j;
    i = len;
    j = 0;
    while(i >= 0) {
        if (from[i] == '\0') {
            --i;
        } else {
            to[j] = from[i];
            ++j;
            --i;
        }
    }
    to[++j] = '\0';
}
