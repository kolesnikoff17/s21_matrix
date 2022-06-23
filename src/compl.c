#include "s21_matrix.h"

void create_sub_matrix(matrix_t *a, matrix_t *b, int ex_i, int ex_j) {
  s21_create_matrix(a->columns - 1, a->rows - 1, b);
  for (int i = 0, i_b = 0; i < a->rows; ++i, ++i_b) {
    if (i == ex_i) {
      --i_b;
      continue;
    }
    for (int j = 0, j_b = 0; j < a->columns; ++j, ++j_b) {
      if (j == ex_j) {
        --j_b;
        continue;
      }
      b->matrix[i_b][j_b] = a->matrix[i][j];
    }
  }
}

int two_det(matrix_t *a) {
  return a->matrix[0][0] * a->matrix[1][1] - a->matrix[0][1] * a->matrix[1][0];
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (check_matrix(A) || !result) return INCORRECT_MATRIX;
  if (A->rows != A->columns) return CALC_ERR;
  s21_create_matrix(A->rows, A->rows, result);
  matrix_t sub_matrix, recursive;
  for (int i = 0; i < A->rows; ++i)
    for (int j = 0; j < A->columns; ++j) {
      create_sub_matrix(A, &sub_matrix, i, j);
      if (sub_matrix.rows == 2) {
        result->matrix[i][j] = ((i + j) % 2 ? -1 : 1) * two_det(&sub_matrix);
      } else if (sub_matrix.rows == 1) {
        result->matrix[i][j] = ((i + j) % 2 ? -1 : 1) * **(sub_matrix.matrix);
      } else {
        s21_calc_complements(&sub_matrix, &recursive);
        for (int k = 0; k < sub_matrix.rows; ++k)
          result->matrix[i][j] +=
              sub_matrix.matrix[0][k] * recursive.matrix[0][k];
        if ((i + j) % 2) result->matrix[i][j] *= -1;
        s21_remove_matrix(&recursive);
      }
      s21_remove_matrix(&sub_matrix);
    }
  return OK;
}
