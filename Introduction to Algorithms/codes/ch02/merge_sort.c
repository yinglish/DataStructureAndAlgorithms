#include "merge_sort.h"
#include <limits.h>
#include <stdlib.h>


/* p代表起始元素位置， r表示最后一个元素的位置（不是最后的past the last）*/
void merge(int a[], int p, int q, int r);
void merge_sort(int a[], int p, int q)
{
    int mid;
    if ((q - p) < 1)
        return;
    mid = (p + q) / 2;
    merge_sort(a, p, mid);
    merge_sort(a, mid + 1, q);
    merge(a, p, mid, q);
}

void merge(int a[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int *left = (int *)malloc(sizeof(int) * (n1 + 1));
    int *right = (int *)malloc(sizeof(int) * (n2 + 1));
    int i, j, k;
    // initialize left and right
    for (i = 0, k = p; i < n1; i++, k++)
    {
        left[i] = a[k];
    }
    left[i] = INT_MAX;
    for (j = 0; j < n2; ++j)
    {
        right[j] = a[k++];
    }
    right[j] = INT_MAX;
    for(i = 0, j = 0, k = p; k < r + 1; /*skip on purpose*/)
    {
        if (left[i] < right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }
    free(left);
    free(right);
}