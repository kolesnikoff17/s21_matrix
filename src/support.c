#include <stdio.h>

#include "s21_matrix.h"

int check_matrix(matrix_t* a) {
  int res = OK;
  if (!a || a->rows <= 0 || a->columns <= 0) {
    res = INCORRECT_MATRIX;
  }
  return res;
}

// void print_matrix(matrix_t* a) {
//   printf("\n");
//   for (int i = 0; i < a->rows; ++i)
//     for (int j = 0; j < a->columns; ++j) {
//       printf("%lf ", a->matrix[i][j]);
//       if (j == a->columns - 1) printf("\n");
//     }
// }
