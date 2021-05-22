#ifndef __CMP_H__
#define __CMP_H__

typedef int (*compare)(void *, void *);

int cmp_char(void *a, void *b);

int cmp_short(void *a, void *b);

int cmp_int(void *a, void *b);

int cmp_long(void *a, void *b);

int cmp_longlong(void *a, void *b);

int cmp_float(void *a, void *b);

int cmp_double(void *a, void *b);

int cmp_char_greater(void *a, void *b);

int cmp_short_greater(void *a, void *b);

int cmp_int_greater(void *a, void *b);

int cmp_long_greater(void *a, void *b);

int cmp_longlong_greater(void *a, void *b);

int cmp_float_greater(void *a, void *b);

int cmp_double_greater(void *a, void *b);

#endif