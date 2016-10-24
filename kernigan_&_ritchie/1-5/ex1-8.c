#include <stdio.h>

/* count blanks, tabs, and newlines */
void main()
{
    int c;
    int nl, bl, tab;

    nl = 0;
    bl = 0;
    tab = 0;
    while((c = getchar()) != EOF)
    {
        if (c == '\n')
            ++nl;
        if (c == '\t')
            ++tab;
        if (c == ' ')
            ++bl;
    }
    printf("newlines: %d, tabs: %d, blanks: %d\n", nl, tab, bl);
}
