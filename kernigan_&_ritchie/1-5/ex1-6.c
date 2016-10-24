#include <stdio.h>

/* copy input to output */
void main()
{
    int c;

    /* following while equivalent to c = (getchar() != EOF)
     * so unless getchar() actually equals EOF c will always
     * equal 1 */
    while (c = getchar() != EOF)
        printf("%d\n", c);
}
