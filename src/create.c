#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (!result || rows <= 0 || columns <= 0) return INCORRECT_MATRIX;
  result->rows = rows;
  result->columns = columns;
  result->matrix = calloc(rows, sizeof(double *));
  if (!result->matrix) exit(0);
  for (int i = 0; i < rows; ++i) {
    result->matrix[i] = calloc(columns, sizeof(double));
    if (!result->matrix[i]) exit(0);
  }
  return OK;
}
