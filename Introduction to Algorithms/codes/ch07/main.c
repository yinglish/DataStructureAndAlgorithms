#include "quicksort.h"
#include "commons.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LENGTH 10

void test(void);

int main(void)
{
    //test();
    int test_array[LENGTH];
    int test_array1[LENGTH];
    random_integer(test_array, LENGTH);
    printf("******************\n");
    printf("Test quicksort:\n");
    printf("Before quicksort:\n");
    showarray(test_array, LENGTH);
    printf("After quicksort:\n");
    quicksort(test_array, 0, LENGTH - 1);
    showarray(test_array, LENGTH);
    printf("******************\n");

    random_integer(test_array1, LENGTH);
    printf("******************\n");
    printf("Test randomized quicksort:\n");
    printf("Before randomized quicksort:\n");
    showarray(test_array1, LENGTH);
    printf("After randomized quicksort:\n");
    random_quicksort(test_array1, 0, LENGTH - 1);
    showarray(test_array1, LENGTH);
    printf("******************\n");

    return 0;
}

void test(void)
{
    int testarray[] = {3, 8, 6, 9, 5};
    int i;
    printf("******************\n");
    printf("After partision:\n");
    i = partition(testarray, 0, 4);
    printf("i: %d\n", i);
    showarray(testarray, 5);
    printf("******************\n");
}