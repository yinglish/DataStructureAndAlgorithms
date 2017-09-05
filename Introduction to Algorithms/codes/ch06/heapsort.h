#ifndef HEAPSORT_H_
#define HEAPSORT_H_

int parent(int i);

int left(int i);

int right(int i);

void max_heapify(int a[], int i, int heap_size);

void build_max_heap(int a[], int heap_size);

void heapsort(int a[], int array_size);

#endif