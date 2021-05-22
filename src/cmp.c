#include "cmp.h"

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
