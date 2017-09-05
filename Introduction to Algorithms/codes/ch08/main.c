#include "counting_sort.h"
#include "commons.h"
#include "radix_sort.h"
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

int main(void)
{
    int test_array[LENGTH];
    int test_array1[LENGTH];
    int result_array[LENGTH];

    random_integer(test_array, LENGTH);
    printf("****************\n");
    printf("Test counting sort!\n");
    printf("Befor counting sort:\n");
    showarray(test_array, LENGTH);
    printf("After counting sort:\n");
    counting_sort(test_array, result_array, LENGTH);
    showarray(result_array, LENGTH);
    printf("****************\n");

    random_integer(test_array1, LENGTH);
    printf("****************\n");
    printf("Test radix sort!\n");
    printf("Befor radix sort:\n");
    showarray(test_array1, LENGTH);
    printf("After radix sort:\n");
    radix_sort(test_array1, LENGTH, 2);
    showarray(test_array1, LENGTH);
    printf("****************\n");

    return 0;
}