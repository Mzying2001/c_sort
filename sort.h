#ifndef _INC_SORT
#define _INC_SORT

#include <stdlib.h>
#include <string.h>

typedef int (*compare)(void *, void *);

#define _ARR_AT(arr, ele_size, index) ((char *)(arr) + (index) * (ele_size))

int cmp_char(void *a, void *b)
{
    return *(char *)a < *(char *)b;
}

int cmp_short(void *a, void *b)
{
    return *(short *)a < *(short *)b;
}

int cmp_int(void *a, void *b)
{
    return *(int *)a < *(int *)b;
}

int cmp_long(void *a, void *b)
{
    return *(long *)a < *(long *)b;
}

int cmp_longlong(void *a, void *b)
{
    return *(long long *)a < *(long long *)b;
}

int cmp_float(void *a, void *b)
{
    return *(float *)a < *(float *)b;
}

int cmp_double(void *a, void *b)
{
    return *(double *)a < *(double *)b;
}

int cmp_char_greater(void *a, void *b)
{
    return *(char *)a > *(char *)b;
}

int cmp_short_greater(void *a, void *b)
{
    return *(short *)a > *(short *)b;
}

int cmp_int_greater(void *a, void *b)
{
    return *(int *)a > *(int *)b;
}

int cmp_long_greater(void *a, void *b)
{
    return *(long *)a > *(long *)b;
}

int cmp_longlong_greater(void *a, void *b)
{
    return *(long long *)a > *(long long *)b;
}

int cmp_float_greater(void *a, void *b)
{
    return *(float *)a > *(float *)b;
}

int cmp_double_greater(void *a, void *b)
{
    return *(double *)a > *(double *)b;
}

void bubbleSort(void *arr, int len, size_t ele_size, compare cmp)
{
    void *temp = malloc(len * ele_size);
    for (int i = 0, flag; i < len - 1; ++i)
    {
        flag = 1;
        for (int j = 0; j < len - i - 1; ++j)
        {
            if (cmp(_ARR_AT(arr, ele_size, j + 1), _ARR_AT(arr, ele_size, j)))
            {
                flag = 0;
                memcpy(temp, _ARR_AT(arr, ele_size, j), ele_size);
                memcpy(_ARR_AT(arr, ele_size, j), _ARR_AT(arr, ele_size, j + 1), ele_size);
                memcpy(_ARR_AT(arr, ele_size, j + 1), temp, ele_size);
            }
        }
        if (flag)
            break;
    }
    free(temp);
}

void quickSort(void *arr, int left, int right, size_t ele_size, compare cmp)
{
    if (left >= right)
        return;

    int l = left, r = right;
    void *p = malloc(ele_size);
    memcpy(p, _ARR_AT(arr, ele_size, right), ele_size);

    while (l < r)
    {
        while (l < r && cmp(_ARR_AT(arr, ele_size, l), p))
            l++;
        if (l < r)
            memcpy(_ARR_AT(arr, ele_size, r--), _ARR_AT(arr, ele_size, l), ele_size);

        while (l < r && !cmp(_ARR_AT(arr, ele_size, r), p))
            r--;
        if (l < r)
            memcpy(_ARR_AT(arr, ele_size, l++), _ARR_AT(arr, ele_size, r), ele_size);
    }

    memcpy(_ARR_AT(arr, ele_size, l), p, ele_size);
    free(p);

    quickSort(arr, left, r - 1, ele_size, cmp);
    quickSort(arr, l + 1, right, ele_size, cmp);
}

void quickSort(void *arr, int len, size_t ele_size, compare cmp)
{
    quickSort(arr, 0, len - 1, ele_size, cmp);
}

void mergeSort(void *arr, int left, int right, void *buffer, size_t ele_size, compare cmp)
{
    if (left >= right)
        return;

    int mid = (left + right) / 2;
    mergeSort(arr, left, mid, buffer, ele_size, cmp);
    mergeSort(arr, mid + 1, right, buffer, ele_size, cmp);

    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right)
    {
        if (cmp(_ARR_AT(arr, ele_size, j), _ARR_AT(arr, ele_size, i)))
            memcpy(_ARR_AT(buffer, ele_size, k++), _ARR_AT(arr, ele_size, j++), ele_size);
        else
            memcpy(_ARR_AT(buffer, ele_size, k++), _ARR_AT(arr, ele_size, i++), ele_size);
    }
    while (i <= mid)
        memcpy(_ARR_AT(buffer, ele_size, k++), _ARR_AT(arr, ele_size, i++), ele_size);
    while (j <= right)
        memcpy(_ARR_AT(buffer, ele_size, k++), _ARR_AT(arr, ele_size, j++), ele_size);
    while (right >= left)
        memcpy(_ARR_AT(arr, ele_size, right--), _ARR_AT(buffer, ele_size, --k), ele_size);
}

void mergeSort(void *arr, int len, size_t ele_size, compare cmp)
{
    void *buffer = malloc(len * ele_size);
    mergeSort(arr, 0, len - 1, buffer, ele_size, cmp);
    free(buffer);
}

#endif
