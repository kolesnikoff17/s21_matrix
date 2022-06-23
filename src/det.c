#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (check_matrix(A) || !result) return INCORRECT_MATRIX;
  if (A->columns != A->rows) return CALC_ERR;
  matrix_t complement;
  s21_calc_complements(A, &complement);
  *result = 0;
  for (int i = 0; i < A->rows; ++i)
    *result += A->matrix[0][i] * complement.matrix[0][i];
  s21_remove_matrix(&complement);
  return OK;
}
