#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getLine(char line[]);

void copy(char to[], char from[]);

/* print the longest input line */
void main()
{
    int len;                /* current line length */
    int max;                /* maximum length seen so far */
    char line[MAXLINE];     /* current input line */
    char longest[MAXLINE];  /* longest line saved here */

    max = 0;
    while((len = getLine(line)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) /* there was a line */
        printf("longest line is: %d chars long.\n", max);
        printf("printing the first %d chars of the line: %s\n", MAXLINE, longest);
    return 0;
}

/* getline: read a line into s, return length */
int getLine(char s[])
{
    int c, i;

    for (i=0; (c=getchar())!=EOF && c!='\n'; ++i) {
        if (i >= MAXLINE) {
            /* do nothing, line too long.
             * but increment i to keep track
             */
        } else {
            s[i] = c;
        }
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    if (i >= MAXLINE) {
        s[MAXLINE - 1] = '\0';
    } else {
        s[i] = '\0';
    }
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
