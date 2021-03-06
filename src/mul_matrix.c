#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (check_matrix(A) || check_matrix(B) || !result) return INCORRECT_MATRIX;
  if (A->columns != B->rows) return CALC_ERR;
  s21_create_matrix(A->rows, B->columns, result);
  for (int i = 0; i < result->rows; ++i)
    for (int j = 0; j < result->columns; ++j) {
      double sum = 0;
      for (int k = 0; k < A->columns; ++k)
        sum += A->matrix[i][k] * B->matrix[k][j];
      result->matrix[i][j] = sum;
    }
  return OK;
}
