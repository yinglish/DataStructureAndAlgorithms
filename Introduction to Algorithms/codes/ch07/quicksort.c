#include "quicksort.h"
#include "commons.h"

#include <stdio.h>

int partition(int a[], int low, int high);

int random_partition(int a[], int low, int high);

void quicksort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = partition(a, low, high);
        quicksort(a, low, mid - 1);
        quicksort(a, mid + 1, high);
    }
}

void random_quicksort(int a[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = random_partition(a, low, high);
        //printf("mid is: %d\n", mid);
        random_quicksort(a, low, mid - 1);
        random_quicksort(a, mid + 1, high);
    }
}

int partition(int a[], int low, int high)
{
    int i = low - 1, j;
    int pivot = a[high];
    for (j = low; j < high; ++j)
    {
        if (a[j] <= pivot)
        {
            swap_int(&a[++i], &a[j]);
        }
    }
    swap_int(&a[++i], &a[high]);

    return i;
}

int random_partition(int a[], int low, int high)
{
    int pivot_index = generate_random_int(low, high);
    //printf("pivot_index is: %d\n", pivot_index);
    swap_int(&a[high], &a[pivot_index]);
    return partition(a, low, high);
}