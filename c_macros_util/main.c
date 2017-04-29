#include <stdio.h>
#include <stdlib.h>
#include "util.h"


int main (void) {
  char str[] = "";

  if (STR_EMPTY(str)) {
    puts("String is empty.");
  }

  int arr[] = {22, 6, 28, -99};
  print_arr_int(arr, sizeof(arr)); // [22, 6, 28, -99]

  printf("%d", max_int(arr, sizeof(arr))); // 28

  printf("%d", min_int(arr, sizeof(arr))); // -99

  return EXIT_SUCCESS;
}
