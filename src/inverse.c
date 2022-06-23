#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (check_matrix(A) || !result) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return CALC_ERR;
  double det = 0;
  s21_determinant(A, &det);
  int res = 0;
  if (det) {
    matrix_t complement, transpose;
    s21_calc_complements(A, &complement);
    s21_transpose(&complement, &transpose);
    s21_remove_matrix(&complement);
    s21_mult_number(&transpose, 1 / det, result);
    s21_remove_matrix(&transpose);
  } else {
    res = 2;
  }
  return res;
}
