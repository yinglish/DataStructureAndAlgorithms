#include "find_max_min.h"

inline static void swap_int(int *a, int *b)
{
    int temp= *a;
    *a = *b;
    *b = temp;
}

void find_max_min(int a[], int array_size, int  *min, int *max)
{
    int i, j;
    // only one element
    if (array_size == 1)
    {
        *min = *max = a[0];
        return;
    }
    // array size is odd
    if (array_size % 2 == 1)
    {
        *min = *max = a[0];
        for (i = 1; i < array_size; i += 2)
        {
            if (a[i] <= a[i + 1])
            {
                if (a[i] < *min)
                    *min = a[i];
                if (a[i + 1] > *max)
                    *max = a[i + 1];
            }
            else
            {
                if (a[i + 1] < *min)
                    *min = a[i + 1];
                if (a[i] > *max)
                    *max = a[i];
            }
        }
    }
    else
    {
        if (a[0] <= a[1])
        {
            *min = a[0];
            *max = a[1];
        }
        else
        {
            *min = a[1];
            *max = a[0];
        }

        for (j = 2; j < array_size; j += 2)
        {
            if (a[j] <= a[j + 1])
            {
                if (a[j] < *min)
                    *min = a[j];
                if (a[j + 1] > *max)
                    *max = a[j + 1];
            }
            else
            {
                if (a[j + 1] < *min)
                    *min = a[j + 1];
                if (a[j] > *max)
                    *max = a[j];
            }          
        }
    }
}