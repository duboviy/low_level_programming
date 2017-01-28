/* Compute Pi using Monte Carlo approach */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <math.h>


static int points_all = 0;
static int points_in_square = 0;

static int i = 0;


int get_points_all_amount(void)
{
    do
	{
        printf("Enter a positive number for the amount of points you would like to generate? \n");
        scanf("%d", &points_all);
	}
	while (points_all <= 0);
	return points_all;
}

void *count(void *X)
{
    for (i = 0; i < points_all; i++)
    {
        double x = (double) rand() / RAND_MAX;
        double y = (double) rand() / RAND_MAX;

        if (((x * x) + (y * y)) <= 1)
        {
            points_in_square++;
        }
    }
    return NULL;
}

double get_approximate_pi_value(void)
{
    double points = 4.0 * points_in_square;
    double pi = points / points_all;
    return pi;
}

int main()
{
    srand(time(NULL));
    pthread_t thread;

    points_all = get_points_all_amount();

    pthread_create(&thread, NULL, &count, NULL);
    pthread_join(thread, NULL);

    double pi = get_approximate_pi_value();
    printf("The approximate value of pi for the desired amount of points (%d) is: %f \n", points_all, pi);

    return 0;
}
