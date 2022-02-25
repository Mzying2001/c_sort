#ifndef C_SORT_H
#define C_SORT_H

#include <string.h>
#include <stdlib.h>

#define _OFFSET(ptr, off, ele_size) \
    ((char *)(ptr) + (off) * (ele_size))

typedef int (*CompareFunc)(const void *, const void *);

void bubbleSort(
    void *arr,
    size_t count,
    size_t ele_size,
    CompareFunc cmpf)
{
    if (count < 2 || ele_size == 0)
        return;

    void *buf = malloc(ele_size);
    if (buf == NULL)
        return;

    int flag;
    for (size_t i = 0; i < count - 1; ++i)
    {
        flag = 1;
        for (size_t j = 0; j < count - i - 1; ++j)
        {
            if (cmpf(
                    _OFFSET(arr, j + 1, ele_size),
                    _OFFSET(arr, j, ele_size)) < 0)
            {
                flag = 0;
                memcpy(
                    buf,
                    _OFFSET(arr, j, ele_size),
                    ele_size);
                memcpy(
                    _OFFSET(arr, j, ele_size),
                    _OFFSET(arr, j + 1, ele_size),
                    ele_size);
                memcpy(
                    _OFFSET(arr, j + 1, ele_size),
                    buf,
                    ele_size);
            }
        }
        if (flag)
            break;
    }

    free(buf);
}

void selectSort(
    void *arr,
    size_t count,
    size_t ele_size,
    CompareFunc cmpf)
{
    if (count < 2 || ele_size == 0)
        return;

    void *buf = malloc(ele_size);
    if (buf == NULL)
        return;

    for (size_t i = 0, index; i < count - 1; ++i)
    {
        index = i;
        for (size_t j = i + 1; j < count; ++j)
        {
            if (cmpf(
                    _OFFSET(arr, j, ele_size),
                    _OFFSET(arr, index, ele_size)) < 0)
                index = j;
        }
        if (index != i)
        {
            memcpy(
                buf,
                _OFFSET(arr, index, ele_size),
                ele_size);
            memcpy(
                _OFFSET(arr, index, ele_size),
                _OFFSET(arr, i, ele_size),
                ele_size);
            memcpy(
                _OFFSET(arr, i, ele_size),
                buf,
                ele_size);
        }
    }

    free(buf);
}

void insertSort(
    void *arr,
    size_t count,
    size_t ele_size,
    CompareFunc cmpf)
{
    if (count < 2 || ele_size == 0)
        return;

    void *buf = malloc(ele_size);
    if (buf == NULL)
        return;

    size_t insert_index;

    for (size_t i = 1; i < count; ++i)
    {
        insert_index = i - 1;
        memcpy(
            buf,
            _OFFSET(arr, i, ele_size),
            ele_size);

        while (insert_index != ((size_t)0 - 1) &&
               cmpf(buf, _OFFSET(arr, insert_index, ele_size)) < 0)
        {
            memcpy(
                _OFFSET(arr, insert_index + 1, ele_size),
                _OFFSET(arr, insert_index, ele_size),
                ele_size);
            --insert_index;
        }

        memcpy(
            _OFFSET(arr, insert_index + 1, ele_size),
            buf,
            ele_size);
    }

    free(buf);
}

void shellSort(
    void *arr,
    size_t count,
    size_t ele_size,
    CompareFunc cmpf)
{
    if (count < 2 || ele_size == 0)
        return;

    void *buf = malloc(ele_size);
    if (buf == NULL)
        return;

    size_t insert_index;
    size_t gap = count;

    while (gap /= 2)
    {
        for (size_t i = gap; i < count; ++i)
        {
            insert_index = i - gap;
            memcpy(
                buf,
                _OFFSET(arr, i, ele_size),
                ele_size);

            while (cmpf(buf, _OFFSET(arr, insert_index, ele_size)) < 0)
            {
                memcpy(
                    _OFFSET(arr, insert_index + gap, ele_size),
                    _OFFSET(arr, insert_index, ele_size),
                    ele_size);

                if (insert_index < gap)
                {
                    insert_index -= gap;
                    break;
                }
                else
                {
                    insert_index -= gap;
                }
            }

            memcpy(
                _OFFSET(arr, insert_index + gap, ele_size),
                buf,
                ele_size);
        }
    }

    free(buf);
}

void _quickSort(
    void *arr,
    void *buf,
    size_t low,
    size_t high,
    size_t ele_size,
    CompareFunc cmpf)
{
    if (low >= high)
        return;

    size_t l = low;
    size_t h = high;
    memcpy(
        buf,
        _OFFSET(arr, high, ele_size),
        ele_size);

    while (l < h)
    {
        while (l < h &&
               cmpf(_OFFSET(arr, l, ele_size), buf) <= 0)
            ++l;
        if (l < h)
            memcpy(
                _OFFSET(arr, h--, ele_size),
                _OFFSET(arr, l, ele_size),
                ele_size);

        while (l < h &&
               cmpf(_OFFSET(arr, h, ele_size), buf) >= 0)
            --h;
        if (l < h)
            memcpy(
                _OFFSET(arr, l++, ele_size),
                _OFFSET(arr, h, ele_size),
                ele_size);
    }

    memcpy(
        _OFFSET(arr, l, ele_size),
        buf,
        ele_size);

    if (l)
        _quickSort(arr, buf, low, l - 1, ele_size, cmpf);
    if (l + 1)
        _quickSort(arr, buf, l + 1, high, ele_size, cmpf);
}

void quickSort(
    void *arr,
    size_t count,
    size_t ele_size,
    CompareFunc cmpf)
{
    if (count < 2 || ele_size == 0)
        return;

    void *buf = malloc(ele_size);
    if (buf == NULL)
        return;

    _quickSort(arr, buf, 0, count - 1, ele_size, cmpf);
    free(buf);
}

void _mergeSort(
    void *arr,
    void *buf,
    size_t low,
    size_t high,
    size_t ele_size,
    CompareFunc cmpf)
{
    if (low >= high)
        return;

    size_t mid = low + (high - low) / 2;
    _mergeSort(arr, buf, low, mid, ele_size, cmpf);
    _mergeSort(arr, buf, mid + 1, high, ele_size, cmpf);

    size_t i = low;
    size_t j = mid + 1;
    size_t k = 0;
    while (i <= mid && j <= high)
    {
        if (cmpf(
                _OFFSET(arr, j, ele_size),
                _OFFSET(arr, i, ele_size)) < 0)
        {
            memcpy(
                _OFFSET(buf, k++, ele_size),
                _OFFSET(arr, j++, ele_size),
                ele_size);
        }
        else
        {
            memcpy(
                _OFFSET(buf, k++, ele_size),
                _OFFSET(arr, i++, ele_size),
                ele_size);
        }
    }
    while (i <= mid)
    {
        memcpy(
            _OFFSET(buf, k++, ele_size),
            _OFFSET(arr, i++, ele_size),
            ele_size);
    }
    while (j <= high)
    {
        memcpy(
            _OFFSET(buf, k++, ele_size),
            _OFFSET(arr, j++, ele_size),
            ele_size);
    }
    while (high != low - 1)
    {
        memcpy(
            _OFFSET(arr, high--, ele_size),
            _OFFSET(buf, --k, ele_size),
            ele_size);
    }
}

void mergeSort(
    void *arr,
    size_t count,
    size_t ele_size,
    CompareFunc cmpf)
{
    if (count < 2 || ele_size == 0)
        return;

    void *buf = malloc(count * ele_size);
    if (buf == NULL)
        return;

    _mergeSort(arr, buf, 0, count - 1, ele_size, cmpf);
    free(buf);
}

void _adjustHeap(
    void *arr,
    void *buf,
    size_t count,
    size_t index,
    size_t ele_size,
    CompareFunc cmpf)
{
    memcpy(
        buf,
        _OFFSET(arr, index, ele_size),
        ele_size);

    for (size_t k = index * 2 + 1;
         k < count;
         k = k * 2 + 1)
    {
        if (k + 1 < count &&
            cmpf(
                _OFFSET(arr, k, ele_size),
                _OFFSET(arr, k + 1, ele_size)) < 0)
            ++k;

        if (cmpf(buf, _OFFSET(arr, k, ele_size)) < 0)
        {
            memcpy(
                _OFFSET(arr, index, ele_size),
                _OFFSET(arr, k, ele_size),
                ele_size);

            index = k;
        }
        else
        {
            break;
        }
    }

    memcpy(
        _OFFSET(arr, index, ele_size),
        buf,
        ele_size);
}

void heapSort(
    void *arr,
    size_t count,
    size_t ele_size,
    CompareFunc cmpf)
{
    if (count < 2 || ele_size == 0)
        return;

    void *buf = malloc(ele_size);
    if (buf == NULL)
        return;

    for (size_t i = count / 2 - 1; i != ((size_t)0 - 1); --i)
        _adjustHeap(arr, buf, count, i, ele_size, cmpf);

    for (size_t j = count - 1; j > 0; --j)
    {
        memcpy(
            buf,
            _OFFSET(arr, j, ele_size),
            ele_size);
        memcpy(
            _OFFSET(arr, j, ele_size),
            arr,
            ele_size);
        memcpy(
            arr,
            buf,
            ele_size);
        _adjustHeap(arr, buf, j, 0, ele_size, cmpf);
    }

    free(buf);
}

#endif
