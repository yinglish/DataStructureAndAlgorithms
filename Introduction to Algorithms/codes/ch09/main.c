#include "find_max_min.h"
#include "commons.h"
#include "randomized_select.h"
#include <stdio.h>

int main(void)
{
    int testarray1[5] = {1, 2, 3, 4, 5};
    int testarray2[6] = {9, 8, 3, 5, 23, 7};
    int min, max;
    printf("****************\n");
    printf("Test find_max_min!\n");
    printf("The array is:\n");
    showarray(testarray1, 5);
    find_max_min(testarray1, 5, &min, &max);
    printf("The min is: %d, the max is: %d\n", min, max);
    printf("The array is:\n");
    showarray(testarray2, 6);
    find_max_min(testarray2, 6, &min, &max);
    printf("The min is: %d, the max is: %d\n", min, max);
    printf("****************\n");

    printf("****************\n");
    printf("Test randomized select!\n");
    printf("The array is: \n");
    showarray(testarray1, 5);
    printf("The 3rd smalles element is: %d\n", 
    randomized_select(testarray1, 0, 4, 3));
    printf("The array is: \n");
    showarray(testarray2, 6);
    printf("The 3rd smalles element is: %d\n", 
    randomized_select(testarray2, 0, 5, 3));
    printf("****************\n");

    return 0;
}