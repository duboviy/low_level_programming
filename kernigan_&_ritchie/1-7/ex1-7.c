#include <stdio.h>

/* print Fahrenheit-Celsius table
   for fahr = 0, 20, ..., 300 */
float fahr_to_cel(int fahr);

void main()
{
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;      /* lower limit of temperature scale */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    fahr = lower;
    while (fahr <= upper) {
        celsius = fahr_to_cel(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    return 0;
}

/* far_to_cel: convert far temp passed in to cel */
float fahr_to_cel(int fahr)
{
    return (5.0 / 9.0) * (fahr - 32);
}
