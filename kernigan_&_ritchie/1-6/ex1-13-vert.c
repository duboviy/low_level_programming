#include <stdio.h>

/* prints a histogram of words vertically*/
void main()
{
    int wc_arr[1000];
    int w, wc, c, i, j;
    w = wc = 0;

    while ((c = getchar()) != EOF)
    {
        if ( c == ' ' || c == '\n' )
        {
            wc_arr[w++] = wc;
            wc = 0;
        }
        else
        {
            ++wc;
        }
    }
    // loop through array finding the max word count
    int max;
    max = 0;
    for (i = 0; i < w; ++i)
    {
        if (max < wc_arr[i])
        {
            max = wc_arr[i];
        }
    }
    // now that max is found loop through and print
    i = 0;
    for (i = 0; i < max; --max)
    {
        for (j = 0; j < w; ++j)
        {
            if (wc_arr[j] == max)
            {
                printf("%d", wc_arr[j]);
                putchar(32);
            }
            else if ( wc_arr[j] > max)
            {
                putchar(124);
                putchar(32);
            }
            else
            {
                // print two spaces to account for no
                // chars being here
                putchar(32);
                putchar(32);
            }
        }
        printf("\n");
    }
}
