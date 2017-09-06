#include <stdio.h>
#include <stdlib.h>
#include "maximum_subarray.h"
#include "commons.h"

int main(void)
{
    Result * final_result, *brute_result;
    int testarray[] = {13, -3, -25, 20, -3, -16,
                       -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    printf("******************\n");;
    printf("Test maximum_subarray!\n");
    printf("The test array is: \n");
    showarray(testarray, 16);
    final_result = maximum_subarray(testarray, 0, 15);
    printf("The maximum subarray is %d to %d.\n", final_result->left + 1, final_result->right + 1);
    printf("The sum is: %d\n", final_result->sum);
    printf("Test maximum_subarray with brute method!\n");
    showarray(testarray, 16);
    brute_result = brute_force_maxsub(testarray, 0, 15);
    printf("The maximum subarray is %d to %d.\n", brute_result->left + 1, brute_result->right + 1);
    printf("The sum is: %d\n", brute_result->sum);
    printf("*****************\n");
    free(final_result);
    free(brute_result);

    return 0;
}