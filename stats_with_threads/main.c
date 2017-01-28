#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


typedef struct datastruct
{
    int size;
    int *values;
} datastruct;

void *avg_func(datastruct *ptr);
void *min_func(datastruct *ptr);
void *max_func(datastruct *ptr);

static double avg;
static int min;
static int max;


main(int argc, char *argv[])
{
    while(argc <=1)
    {
        printf("Incorrect input. No arguments entered.\n");
        exit(0);
	}

    int i = 0;
    int values[argc-1];
    for(i; i < (argc -1); i++)
    {
        values[i] = atoi(argv[i+1]);
    }

    pthread_t thread1, thread2, thread3;

    int  t1, t2, t3;

    printf("Running: %s\n\n", argv[0]);

    datastruct ds = {argc - 1, values};

    /* Three independent threads and each will execute appropriate function*/
    t1 = pthread_create(&thread1, NULL, (void *) avg_func, &ds);
    if(t1)
    {
        fprintf(stderr,"Error - pthread_create() return code: %d\n", t1);
        exit(EXIT_FAILURE);
    }

    t2 = pthread_create(&thread2, NULL, (void *) min_func, &ds);
    if(t2)
    {
        fprintf(stderr,"Error - pthread_create() return code: %d\n",t2);
        exit(EXIT_FAILURE);
    }

    t3 = pthread_create(&thread3, NULL, (void *) max_func, &ds);
    if(t3)
    {
        fprintf(stderr,"Error - pthread_create() return code: %d\n", t3);
        exit(EXIT_FAILURE);
    }

    /* Main thread continues after all threads are complete. */

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);

    printf("Average: %g\n", avg);
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);

    exit(EXIT_SUCCESS);
}

void *avg_func(datastruct *ptr)
{
    int sz = ptr->size;
    int i;

    for(i = 0; i < sz; i++)
    {
        avg += (ptr->values[i]);
    }
    avg = (double)avg / sz;
}

void *min_func(datastruct *ptr)
{
    int sz = ptr->size;
    int i;

    min = (ptr->values[0]);
    for(i = 1; i < sz; i++)
    {
        if(min > (ptr->values[i]))
        {
            min = (ptr->values[i]);
        }
    }
}

void *max_func(datastruct *ptr)
{
    int sz = ptr->size;
    int i;

    max = ptr->values[0];

    for(i = 1; i < sz; i++)
    {
        if(max < ptr->values[i])
        {
            max = ptr->values[i];
        }
    }
}
