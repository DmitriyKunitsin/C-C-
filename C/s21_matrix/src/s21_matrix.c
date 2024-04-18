

#include "s21_matrix.h"
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = OK;

  if (rows < 1 || columns < 1) {
    result->columns = 0;
    result->rows = 0;
    result->matrix = NULL;
    error = FAILED_MATRIX;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix != NULL) {

      for (int i = 0; i < rows; ++i) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          error = INCORRECT_MATRIX;
          break;
        }
      }
    } else {
      error = INCORRECT_MATRIX;
    }
  }
  return error;
}

void s21_remove_matrix(matrix_t *A) {
  if (A->matrix == NULL) {
    A->columns = 0;
    A->rows = 0;
  } else {
    for (int i = 0; i < A->rows; ++i) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->rows = 0;
    A->columns = 0;
    A->matrix = NULL;
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int error = SUCCESS;
  if ((A->rows == B->rows) && (A->columns == B->columns)) {
    for (int i = 0; i < A->rows; ++i) {
      for (int k = 0; k < A->columns; ++k) {
        if (fabs(A->matrix[i][k] - B->matrix[i][k]) > 1e-7) {
          error = FAILURE;
        }
      }
    }
  } else {
    error = FAILURE;
  }

  return error;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = check_matrix_sub_and_sum(A, B);
  if (error == OK) {
    error = s21_create_matrix(A->rows, A->columns, result);
    if (error == OK) {
      for (int i = 0; i < A->rows; ++i) {
        for (int k = 0; k < A->columns; ++k) {
          result->matrix[i][k] = A->matrix[i][k] + B->matrix[i][k];
        }
      }
    }
  }
  return error;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = check_matrix_sub_and_sum(A, B);
  if (error == OK) {
    error = s21_create_matrix(A->rows, A->columns, result);
    if (error == OK) {
      for (int i = 0; i < A->rows; ++i) {
        for (int k = 0; k < A->columns; ++k) {
          result->matrix[i][k] = A->matrix[i][k] - B->matrix[i][k];
        }
      }
    }
  }
  return error;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = OK;
  if (A->matrix == NULL) {
    error = INCORRECT_MATRIX;
  } else if ((A->rows > 1) && (A->columns > 1)) {
    error = FAILED_MATRIX;
  } else {
    error = s21_create_matrix(A->rows, A->columns, result);
    if (error == OK) {
      for (int i = 0; i < A->rows; ++i) {
        for (int k = 0; k < A->columns; ++k) {
          result->matrix[i][k] = number * A->matrix[i][k];
        }
      }
    }
  }

  return error;
}
/*
Все операции (кроме сравнения матриц) должны возвращать результирующий код:

0 - OK
1 - Ошибка, некорректная матрица
2 - Ошибка вычисления (несовпадающие размеры матриц; матрица, для которой нельзя
провести вычисления и т.д.)
*/
int check_matrix_sub_and_sum(matrix_t *A, matrix_t *B) {
  int error = OK;
  if ((A->rows != B->rows) || (A->columns != B->columns)) {
    error = FAILED_MATRIX;
  } else if ((A->matrix == NULL) || (B->matrix == NULL)) {
    error = INCORRECT_MATRIX;
  }
  return error;
}