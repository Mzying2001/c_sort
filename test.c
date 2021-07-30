#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "c_sort.h"

int cmp_int(const void *a, const void *b)
{
    return *(const int *)a - *(const int *)b;
}

int cmp_double(const void *a, const void *b)
{
    return (int)(*(const double *)a - *(const double *)b);
}

#define LEN 20

int getrandom()
{
    return rand() % 100;
}

int a[LEN], b[LEN], c[LEN];
double d[LEN], e[LEN], f[LEN];
void init_arr()
{
    for (int i = 0; i < LEN; ++i)
        a[i] = getrandom();
    for (int i = 0; i < LEN; ++i)
        b[i] = getrandom();
    for (int i = 0; i < LEN; ++i)
        c[i] = getrandom();
    for (int i = 0; i < LEN; ++i)
        d[i] = getrandom();
    for (int i = 0; i < LEN; ++i)
        e[i] = getrandom();
    for (int i = 0; i < LEN; ++i)
        f[i] = getrandom();
}

int main()
{
    srand(time(NULL));

    puts("====================int类型测试====================");

    //qsort
    puts("[qsort]:");
    init_arr();
    //a
    qsort(a, LEN, sizeof(int), cmp_int);
    printf("a: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02d" + !i * 2, a[i]);
    puts("]");
    //b
    qsort(b, LEN, sizeof(int), cmp_int);
    printf("b: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02d" + !i * 2, b[i]);
    puts("]");
    //c
    qsort(c, LEN, sizeof(int), cmp_int);
    printf("c: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02d" + !i * 2, c[i]);
    puts("]");

    //bubbleSort
    puts("[bubbleSort]:");
    init_arr();
    //a
    bubbleSort(a, LEN, sizeof(int), cmp_int);
    printf("a: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02d" + !i * 2, a[i]);
    puts("]");
    //b
    bubbleSort(b, LEN, sizeof(int), cmp_int);
    printf("b: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02d" + !i * 2, b[i]);
    puts("]");
    //c
    bubbleSort(c, LEN, sizeof(int), cmp_int);
    printf("c: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02d" + !i * 2, c[i]);
    puts("]");

    //selectSort
    puts("[selectSort]:");
    init_arr();
    //a
    selectSort(a, LEN, sizeof(int), cmp_int);
    printf("a: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02d" + !i * 2, a[i]);
    puts("]");
    //b
    selectSort(b, LEN, sizeof(int), cmp_int);
    printf("b: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02d" + !i * 2, b[i]);
    puts("]");
    //c
    selectSort(c, LEN, sizeof(int), cmp_int);
    printf("c: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02d" + !i * 2, c[i]);
    puts("]");

    //insertSort
    puts("[insertSort]:");
    init_arr();
    //a
    insertSort(a, LEN, sizeof(int), cmp_int);
    printf("a: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02d" + !i * 2, a[i]);
    puts("]");
    //b
    insertSort(b, LEN, sizeof(int), cmp_int);
    printf("b: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02d" + !i * 2, b[i]);
    puts("]");
    //c
    insertSort(c, LEN, sizeof(int), cmp_int);
    printf("c: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02d" + !i * 2, c[i]);
    puts("]");

    //shellSort
    puts("[shellSort]:");
    init_arr();
    //a
    shellSort(a, LEN, sizeof(int), cmp_int);
    printf("a: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02d" + !i * 2, a[i]);
    puts("]");
    //b
    shellSort(b, LEN, sizeof(int), cmp_int);
    printf("b: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02d" + !i * 2, b[i]);
    puts("]");
    //c
    shellSort(c, LEN, sizeof(int), cmp_int);
    printf("c: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02d" + !i * 2, c[i]);
    puts("]");

    //quickSort
    puts("[quickSort]:");
    init_arr();
    //a
    quickSort(a, LEN, sizeof(int), cmp_int);
    printf("a: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02d" + !i * 2, a[i]);
    puts("]");
    //b
    quickSort(b, LEN, sizeof(int), cmp_int);
    printf("b: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02d" + !i * 2, b[i]);
    puts("]");
    //c
    quickSort(c, LEN, sizeof(int), cmp_int);
    printf("c: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02d" + !i * 2, c[i]);
    puts("]");

    //mergeSort
    puts("[mergeSort]:");
    init_arr();
    //a
    mergeSort(a, LEN, sizeof(int), cmp_int);
    printf("a: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02d" + !i * 2, a[i]);
    puts("]");
    //b
    mergeSort(b, LEN, sizeof(int), cmp_int);
    printf("b: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02d" + !i * 2, b[i]);
    puts("]");
    //c
    mergeSort(c, LEN, sizeof(int), cmp_int);
    printf("c: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02d" + !i * 2, c[i]);
    puts("]");

    //heapSort
    puts("[heapSort]:");
    init_arr();
    //a
    heapSort(a, LEN, sizeof(int), cmp_int);
    printf("a: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02d" + !i * 2, a[i]);
    puts("]");
    //b
    heapSort(b, LEN, sizeof(int), cmp_int);
    printf("b: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02d" + !i * 2, b[i]);
    puts("]");
    //c
    heapSort(c, LEN, sizeof(int), cmp_int);
    printf("c: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02d" + !i * 2, c[i]);
    puts("]");

    puts("====================double类型测试====================");

    //qsort
    puts("[qsort]:");
    init_arr();
    //d
    qsort(d, LEN, sizeof(double), cmp_double);
    printf("d: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02.0lf" + !i * 2, d[i]);
    puts("]");
    //e
    qsort(e, LEN, sizeof(double), cmp_double);
    printf("e: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02.0lf" + !i * 2, e[i]);
    puts("]");
    //f
    qsort(f, LEN, sizeof(double), cmp_double);
    printf("f: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02.0lf" + !i * 2, f[i]);
    puts("]");

    //bubbleSort
    puts("[bubbleSort]:");
    init_arr();
    //d
    bubbleSort(d, LEN, sizeof(double), cmp_double);
    printf("d: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02.0lf" + !i * 2, d[i]);
    puts("]");
    //e
    bubbleSort(e, LEN, sizeof(double), cmp_double);
    printf("e: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02.0lf" + !i * 2, e[i]);
    puts("]");
    //f
    bubbleSort(f, LEN, sizeof(double), cmp_double);
    printf("f: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02.0lf" + !i * 2, f[i]);
    puts("]");

    //selectSort
    puts("[selectSort]:");
    init_arr();
    //d
    selectSort(d, LEN, sizeof(double), cmp_double);
    printf("d: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02.0lf" + !i * 2, d[i]);
    puts("]");
    //e
    selectSort(e, LEN, sizeof(double), cmp_double);
    printf("e: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02.0lf" + !i * 2, e[i]);
    puts("]");
    //f
    selectSort(f, LEN, sizeof(double), cmp_double);
    printf("f: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02.0lf" + !i * 2, f[i]);
    puts("]");

    //insertSort
    puts("[insertSort]:");
    init_arr();
    //d
    insertSort(d, LEN, sizeof(double), cmp_double);
    printf("d: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02.0lf" + !i * 2, d[i]);
    puts("]");
    //e
    insertSort(e, LEN, sizeof(double), cmp_double);
    printf("e: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02.0lf" + !i * 2, e[i]);
    puts("]");
    //f
    insertSort(f, LEN, sizeof(double), cmp_double);
    printf("f: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02.0lf" + !i * 2, f[i]);
    puts("]");

    //shellSort
    puts("[shellSort]:");
    init_arr();
    //d
    shellSort(d, LEN, sizeof(double), cmp_double);
    printf("d: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02.0lf" + !i * 2, d[i]);
    puts("]");
    //e
    shellSort(e, LEN, sizeof(double), cmp_double);
    printf("e: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02.0lf" + !i * 2, e[i]);
    puts("]");
    //f
    shellSort(f, LEN, sizeof(double), cmp_double);
    printf("f: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02.0lf" + !i * 2, f[i]);
    puts("]");

    //quickSort
    puts("[quickSort]:");
    init_arr();
    //d
    quickSort(d, LEN, sizeof(double), cmp_double);
    printf("d: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02.0lf" + !i * 2, d[i]);
    puts("]");
    //e
    quickSort(e, LEN, sizeof(double), cmp_double);
    printf("e: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02.0lf" + !i * 2, e[i]);
    puts("]");
    //f
    quickSort(f, LEN, sizeof(double), cmp_double);
    printf("f: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02.0lf" + !i * 2, f[i]);
    puts("]");

    //mergeSort
    puts("[mergeSort]:");
    init_arr();
    //d
    mergeSort(d, LEN, sizeof(double), cmp_double);
    printf("d: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02.0lf" + !i * 2, d[i]);
    puts("]");
    //e
    mergeSort(e, LEN, sizeof(double), cmp_double);
    printf("e: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02.0lf" + !i * 2, e[i]);
    puts("]");
    //f
    mergeSort(f, LEN, sizeof(double), cmp_double);
    printf("f: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02.0lf" + !i * 2, f[i]);
    puts("]");

    //heapSort
    puts("[heapSort]:");
    init_arr();
    //d
    heapSort(d, LEN, sizeof(double), cmp_double);
    printf("d: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02.0lf" + !i * 2, d[i]);
    puts("]");
    //e
    heapSort(e, LEN, sizeof(double), cmp_double);
    printf("e: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02.0lf" + !i * 2, e[i]);
    puts("]");
    //f
    heapSort(f, LEN, sizeof(double), cmp_double);
    printf("f: [");
    for (int i = 0; i < LEN; ++i)
        printf(", %02.0lf" + !i * 2, f[i]);
    puts("]");

    puts("====================测试结束====================");

    return 0;
}