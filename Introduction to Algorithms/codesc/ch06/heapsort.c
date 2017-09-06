#include "heapsort.h"
#include "commons.h"
#include <stdio.h>
#include <unistd.h>

int parent(int i)
{
    return (i - 1) / 2;
}

int left(int i)
{
    return 2 * i + 1;
}

int right(int i)
{
    return 2 * i + 2;
}

void max_heapify(int a[], int i, int heap_size)
{
    //printf("max_heapify start:\n");
    int l = left(i);
    int r = right(i);
    int largest = i;
    //printf("l: %d, r:%d; lar: %d\n", l, r, largest);
    if (l < heap_size && a[l] > a[i])
    {
        largest = l;
    }
    if (r < heap_size && a[r] > a[largest])
    {
        largest = r;
    }
    //printf("largest = %d\n", largest);
    //sleep(5);

    if (largest != i)
    {
        swap_int(&a[largest], &a[i]);
        max_heapify(a, largest, heap_size);
    }

}

void build_max_heap(int a[], int heap_size)
{
    int i;
    for (i = (heap_size - 1) / 2; i >= 0; --i)
    {
        max_heapify(a, i, heap_size);
    }

}

void heapsort(int a[], int array_size)
{
    int i, heap_size = array_size;
    build_max_heap(a, heap_size);
    //printf("after building max heap:\n");
    //showarray(a, 10);
    for (i = array_size - 1; i > 0; --i)
    {
        swap_int(&a[0], &a[i]);
        heap_size--;
        max_heapify(a, 0, heap_size);
    }
}