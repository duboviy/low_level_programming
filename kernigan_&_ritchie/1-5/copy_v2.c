#include <stdio.h>

/* copy input to output; 2nd version */
void main()
{
    int c;

    while ((c = getchar()) != EOF)
        putchar(c);
}
