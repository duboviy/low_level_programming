#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300 */
void main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;      /* lower limit of temperature scale */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    celsius = lower;
    printf("------------------\n");
    printf("Fahrenheit|Celsius\n");
    printf("------------------\n");
    while (celsius <= upper) {
        fahr = (celsius / (5.0 / 9.0)) + 32;
        printf("%3.0f       %6.1f\n", fahr, celsius);
        celsius = celsius + step;
    }
}
