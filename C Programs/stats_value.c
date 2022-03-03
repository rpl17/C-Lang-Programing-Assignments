#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int *values;
int size;
int avg = 0.0;
int minValue = 0;
int maxValue = 0;
void *Avg(void *param);
void *Min(void *param);
void *Max(void *param);

void * Avg(void *param)
{

    int sum = 0;
    int i = 0;
    int *values;

    values = param;
    for (i = 0; i < size; i++)
        sum += values[i];
    avg = sum / (double) size;

    return (void *) 0;
}

void * Min(void *param)
{

    int i = 0;
    int *values;

    values = param;
    minValue = values[0];

    for (i = 0; i < size; i++) {
        if (values[i] < minValue)
            minValue = values[i];
    }

    return (void *) 0;
}

void * Max(void *param)
{

    int i = 0;
    int *values;

    values = param;
    maxValue = values[0];

    for (i = 0; i < size; i++) {
        if (values[i] > maxValue)
            maxValue = values[i];
    }

    return (void *) 0;
}
int main(int argc, char **argv)
{
    int i;
    --argc;
    ++argv;
    values = calloc(argc,sizeof(int));

    for (i = 0;  i < argc;  i++) {
        values[i] = atoi(argv[i]);
        size++;
    }
    pthread_t avgPt;
    pthread_t minPt;
    pthread_t maxPt;

    pthread_create(&avgPt, NULL, Avg, values);
    pthread_create(&minPt, NULL, Min, values);
    pthread_create(&maxPt, NULL, Max, values);

    pthread_join(avgPt, NULL);
    pthread_join(minPt, NULL);
    pthread_join(maxPt, NULL);

    printf("The average value: %d \n", avg);
    printf("The minimum value: %d \n", minValue);
    printf("The maximum value: %d \n", maxValue);
}


