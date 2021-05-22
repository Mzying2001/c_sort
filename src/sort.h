#ifndef __SORT_H__
#define __SORT_H__

#include <stddef.h>
#include "cmp.h"

#define _ARR_AT(arr, ele_size, index) ((char *)(arr) + (index) * (ele_size))

void bubbleSort(void *arr, int len, size_t ele_size, compare cmp);

void selectSort(void *arr, int len, size_t ele_size, compare cmp);

void insertSort(void *arr, int len, size_t ele_size, compare cmp);

void shellSort(void *arr, int len, size_t ele_size, compare cmp);

void quickSort(void *arr, int len, size_t ele_size, compare cmp);

void mergeSort(void *arr, int len, size_t ele_size, compare cmp);

void heapSort(void *arr, int len, size_t ele_size, compare cmp);

#endif
