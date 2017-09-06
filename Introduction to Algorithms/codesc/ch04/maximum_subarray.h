#ifndef MAXIMUM_SUBARRAY_H_
#define MAXIMUM_SUBARRAY_H_

/* Result: record the result */
typedef struct result
{
    int left;
    int right;
    int sum;
} Result;

/* Find the maximum subarray */
Result * maximum_subarray(int a[], int low, int high);


/* Find the max-cross subarray */
Result * find_cross_max_array(int a[], int low, int mid, int high);

/* Find the maximum subarray with brute force*/
Result * brute_force_maxsub(int a[], int low, int high);
#endif