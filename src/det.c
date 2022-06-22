#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  if (check_matrix(A) || !result) return INCORRECT_MATRIX;
  if (A->columns != A->rows) return CALC_ERR;
  s21_create_matrix(A->rows, A->rows, result);
  matrix_t sub_matrix;
  for (int i = 0; i < A->rows; ++i) return OK;
  // not done yet
}

void create_sub_matrix(matrix_t *a, matrix_t *b, int ex) {
  s21_create_matrix(a->columns - 1, a->rows - 1, b);
  for (int i = 1; i < a->rows; ++i)
    for (int j = 0, j_for_b = 0; j < a->columns; ++j, ++j_for_b) {
      if (j == ex) {
        --j_for_b;
        continue;
      }
      b->matrix[i - 1][j_for_b] = a->matrix[i][j];
    }
}

int two_det(matrix_t *a) {
  return a->matrix[0][0] * a->matrix[1][1] - a->matrix[0][1] * a->matrix[1][0];
}