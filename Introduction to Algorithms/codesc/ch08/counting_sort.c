#include "counting_sort.h"

//#include <stdio.h>


void counting_sort(int a[], int b[], int array_size)
{
    int c[100] = {0};
    int i, j;

    for (i = 0; i < array_size; ++i)
    {
        c[a[i]]++;
    }

    for (j = 1; j < 100; ++j)
    {
        c[j] = c[j] + c[j - 1];
    }
    for (i = array_size - 1; i >= 0; --i)
    {
        //printf("%d, %d\n", c[a[i]], a[i]);
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }
}

void counting_sort_for_radix(int original[], int a[], int b[], int array_size)
{
    int c[100] = {0};
    int i, j;

    // copy original to b
    for (i = 0; i < array_size; ++i)
    {
        b[i] = original[i];
    }

    for (i = 0; i < array_size; ++i)
    {
        c[a[i]]++;
    }

    for (j = 1; j < 100; ++j)
    {
        c[j] = c[j] + c[j - 1];
    }
    for (i = array_size - 1; i >= 0; --i)
    {
        //printf("%d, %d\n", c[a[i]], a[i]);
        original[c[a[i]] - 1] = b[i];
        c[a[i]]--;
    }
}