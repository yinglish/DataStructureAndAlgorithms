#include "maximum_subarray.h"
#include <stdlib.h>
#include <limits.h>

int sumarray(int a[], int i, int j);

Result * maximum_subarray(int a[], int low, int high)
{
    Result *left, *cross, *right;
    int mid;

    // allocate memory
    left = (Result *)malloc(sizeof(Result));
    cross = (Result *)malloc(sizeof(Result));
    right = (Result *)malloc(sizeof(Result));

    if (low == high)
    {
        left->left = low;
        left->right = low;
        left->sum = a[low];
        free(cross);
        free(right);
        return left;
    }
    else
    {
        mid = (low + high) / 2;
        left = maximum_subarray(a, low, mid);
        right = maximum_subarray(a, mid + 1, high);
        cross = find_cross_max_array(a, low, mid, high);
        if (left->sum >= cross->sum && left->sum >= right->sum)
        {
            free(cross);
            free(right);
            return left;
        }
        else if (cross->sum > left->sum && cross->sum >= right->sum) 
        {
            free(left);
            free(right);
            return cross;
        }
        else
        {
            free(cross);
            free(left);
            return right;
        }          
    }
    

}

Result * find_cross_max_array(int a[], int low, int mid, int high)
{
    int left_sum = -INT_MAX, right_sum = -INT_MAX, sum = 0;
    int i, j;
    Result * cross = (Result *)malloc(sizeof(Result));
    cross->left = cross->right = mid;
    for (i = mid; i >= 0; --i)
    {
        sum += a[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            cross->left = i;
        }
    }
    sum = 0;
    for (j = mid + 1; j <= high; ++j)
    {
        sum += a[j];
        if (sum > right_sum)
        {
            right_sum = sum;
            cross->right = j;
        }
    }
    cross->sum = left_sum + right_sum;
    return cross;

}

Result * brute_force_maxsub(int a[], int low, int high)
{
    Result * final_result = (Result *)malloc(sizeof(Result));
    final_result->sum = -INT_MAX;
    int i, j, sum;
    for (i = low; i <= high; ++i)
        for (j = i; j <= high; ++j)
        {
            sum = sumarray(a, i, j);
            if (final_result->sum < sum)
            {
                final_result->left = i;
                final_result->right = j;
                final_result->sum = sum;
            }
        }
    return final_result;
}

int sumarray(int a[], int i, int j)
{
    int sum = 0;
    int index;
    for (index = i; index <= j; ++index)
    {
        sum += a[index];
    }

    return sum;
}