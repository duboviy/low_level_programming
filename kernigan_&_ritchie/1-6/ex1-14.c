#include <stdio.h>

/* prints a histogram of frequencies of different characters vertically.
 * program only prints ascii chars 0 - 127
 */
#define ASCII_MAX 126

void main()
{
    int cc_arr[ASCII_MAX];
    int w, wc, c, i, j;
    w = wc = i = 0;

    // initialize array to zero
    for (i = 0; i < ASCII_MAX; ++i)
    {
        cc_arr[i] = 0;

    }

    while ((c = getchar()) != EOF)
    {
        cc_arr[c] = cc_arr[c] + 1;
    }

    // loop through array finding the max word count
    int max;
    max = 0;
    for (i = 0; i < ASCII_MAX; ++i)
    {
        if (max < cc_arr[i])
        {
            max = cc_arr[i];
        }
    }

    // now that max is found loop through and print
    i = 0;
    for (i = 0; i < max; --max)
    {
        for (j = 0; j < ASCII_MAX; ++j)
        {
            if (cc_arr[j] == max)
            {
                putchar(j);
                putchar(32);
            }
            else if ( cc_arr[j] >= max)
            {
                putchar(124);
                putchar(32);
            }
            else
            {
                //putchar(32);
            }
        }
        printf("\n");
    }
}
