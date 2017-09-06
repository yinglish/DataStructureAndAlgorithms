#include <stdio.h>
#include <stdlib.h>
#include "insertion_sort.h"
#include "commons.h"
#include "merge_sort.h"
#define LENGTH 10

int main(void)
{
    int testmerge[LENGTH];
    printf("*****************\n");
    printf("Test insertion sort:\n");
    int a[LENGTH] = {3, 7, 2, 9, 14, 17, 1, 8, 5, 10};
    printf("Before insertion sorting:\n");
    showarray(a, LENGTH);
    insertion_sort(a, LENGTH);
    printf("After insertion sorting:\n");
    showarray(a, LENGTH);
    printf("*****************\n");
    printf("*****************\n");
    printf("Test merge sort:\n");
    random_integer(testmerge, LENGTH);
    printf("Before merge sorting:\n");
    showarray(testmerge, LENGTH);
    merge_sort(testmerge, 0, LENGTH - 1);
    printf("After merge sorting:\n");
    showarray(testmerge, LENGTH);
    printf("*****************\n");

    return 0;
}