#include <stdio.h>

/* prints a histogram of words horizontally*/
void main()
{
    int wc_array[1000];
    int w, wc, c, i, j;
    w = wc = 0;

    while ((c = getchar()) != EOF)
    {
        if ( c == ' ' || c == '\n' )
        {
            wc_array[w++] = wc;
            wc = 0;
        }
        else
        {
            ++wc;
        }
    }
    for (i = 0; i < w; ++i)
    {
        for (j = 0; j < wc_array[i]; ++j)
        {
            putchar(45);
        }
        printf("%d\n", wc_array[i]);
    }
}
