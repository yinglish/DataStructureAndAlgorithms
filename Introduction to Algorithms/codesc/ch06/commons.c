#include "commons.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void showarray(int a[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void random_integer(int a[], int n)
{
    int i;
    srand(time(0));
    for (i = 0; i < n; ++i)
    {
        a[i] = rand() % 100;
    }
}

void swap_int(int *a, int *b)
{
    int temp= *a;
    *a = *b;
    *b = temp;
}