#include "randomized_select.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

inline static int partition(int a[], int low, int high);
inline static int randomized_partition(int a[], int low, int high);
inline static int generate_random_int(int low, int high);
inline static void swap_int(int *a, int *b);


int randomized_select(int a[], int p, int r, int i)
{
    int q, k;

    if (p == r)
        return a[p];
    
    q = randomized_partition(a, p, r);
    k = q - p + 1;
    //printf("q: %d, k: %d\n", q, k);

    if (i == k)  // if the pivot value is the answer
        return a[q];
    else if (i < k)
        return randomized_select(a, p, q - 1, i);
    else 
        return randomized_select(a, q + 1, r, i - k);
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

int randomized_partition(int a[], int low, int high)
{
    int pivot_index = generate_random_int(low, high);
    swap_int(&a[high], &a[pivot_index]);
    return partition(a, low, high);
}

int generate_random_int(int low, int high)
{
    srand(time(NULL));
    int value;
    value = rand() % (high - low + 1) + low;
    return value;
}
void swap_int(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}