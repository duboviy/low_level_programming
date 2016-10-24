#include <stdio.h>

/* Copies input to output, but replaces multiple spaces with
 * one space.
 */

void main()
{
    int c;
    int bl_flag;
    bl_flag = 0;

    while((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            // first blank mark flag
            if( bl_flag == 0)
            {
                bl_flag = 1;
                putchar(c);
            }
            // consecutive blank; ignore it
            if ( bl_flag == 1)
                ;
        }

        else
        {
            // not a blank mark flag
            bl_flag = 0;
            putchar(c);
        }
    }
}
