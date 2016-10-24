#include <stdio.h>
#include <stdlib.h>

#define TABWIDTH 8

void main(void)
{
    int i;
    int c, col, spaces;

    col = 0;
    while((c = getchar()) != EOF) {
        if (c == '\t') {
            spaces = TABWIDTH - col % TABWIDTH;
            for (i = 0; i < spaces; ++i)
                putchar(' ');
            col = col + spaces;
        } else {
            putchar(c);
            col = col + 1;
            if (c == '\n')
                col = 0;
        }
    }
}
