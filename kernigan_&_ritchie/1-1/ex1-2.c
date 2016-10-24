#include <stdio.h>

void main()
{
    printf("hello, world\c");
}

/*
 * Produces the following error:
 * ex1-2.c: In function ‘main’:
 * ex1-2.c:5:12: warning: unknown escape sequence: '\c'
 *      printf("hello, world\c");
 *                  ^
 */
