#ifndef _UTIL_H_
#define _UTIL_H_

/* Types */

typedef char       int8;
typedef short      int16;
typedef int        int32;
typedef long long  int64;

typedef unsigned char       uint8;
typedef unsigned short      uint16;
typedef unsigned int        uint32;
typedef unsigned long long  uint64;

/* Macros */

#define STR_EMPTY(s)           ((s[0]) == '\0')
#define STR_EQUAL(a, b)        (strcmp((a), (b)) == 0)
#define STR_START_WITH(a, b)   (strncmp((a), (b), strlen((b))) == 0)
#define GET_LEN_INT(size)      ((size) / sizeof(int))

#undef MAX
#undef MIN

#define MAX(a, b)              ((a) > (b) ? (a) : (b))
#define MIN(a, b)              ((a) < (b) ? (a) : (b))

/* Prototypes */

void print_arr_int (int arr[], size_t size);
void print_arr_float (float arr[], size_t size);
int max_int (int arr[], size_t size);
int min_int (int arr[], size_t size);

#endif
