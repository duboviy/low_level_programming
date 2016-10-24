#include <stdio.h>

/* Copies input to output;
 * Replaces:
 * tabs to \t
 * backspace to \b
 * backslash to \\
 */

void main()
{
    int c;
    // ASCII stuff
    int t, b, bspace, bslash;
    t = 116;
    b = 98;
    bslash = 92;
    bspace = 127;

    while((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            putchar(bslash);
            putchar(t);
        }
        else if (c == '\\')
        {
            putchar(bslash);
            putchar(bslash);
        }
        else if (c == bspace)
        {
            putchar(bslash);
            putchar(b);
        }
        else
        {
            putchar(c);
        }
    }
}
