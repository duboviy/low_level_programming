#include <stdio.h>

/* Prints its input one word per line*/
void main()
{
    int c;

    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            putchar('\n');
        }
        else {
            putchar(c);
        }
    }
}
