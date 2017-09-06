#include "commons.h"
#include "heapsort.h"
#include <stdio.h>
#include <stdlib.h>

#define LENGTH 10

int main(void)
{
    int testarray[LENGTH];// = {3, 9, 11, 20, 23, 19, 1, 8, 13, 56};
    random_integer(testarray, LENGTH);
    printf("******************\n");
    printf("Test heapsort!\n");
    printf("Before heapsort:\n");
    showarray(testarray, LENGTH);
    heapsort(testarray, LENGTH);
    printf("After heapsort:\n");
    showarray(testarray, LENGTH);
    printf("******************\n");

    return 0;
}