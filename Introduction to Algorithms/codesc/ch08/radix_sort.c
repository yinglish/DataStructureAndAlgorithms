#include "radix_sort.h"
#include "counting_sort.h"

#include <stdio.h>
#include "commons.h"

#define LENGTH 10  // Assume that the lenth of array is 10

/* this implementation is awfull, need reconstruction */
void radix_sort(int a[], int n, int digits_number)
{
    int i, j, k;
    int digit[LENGTH];
    int residuals[LENGTH];
    int for_counting_sort[LENGTH];
    
    for (i = 0; i < digits_number; ++i)
    {
        // copy original array, original array may change 
        // after a counting sort
        for (j = 0; j < n; ++j)
        residuals[j] = a[j];

        for (j = 0; j < n; ++j)
        {
            // handle the (j + 1)th digit, assume the base is 10
            for (k = 0; k < i; ++k)
            {
                residuals[j] = residuals[j] / 10; 
            }
            digit[j] = residuals[j] % 10; 
        }
        counting_sort_for_radix(a, digit, for_counting_sort, n);
    }
}
