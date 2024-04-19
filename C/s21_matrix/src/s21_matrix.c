#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = OK;

  if (rows < 1 || columns < 1) {
    result->columns = 0;
    result->rows = 0;
    result->matrix = NULL;
    error = INCORRECT_MATRIX;
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
  if (A->matrix == NULL) {
    error = FAILURE;
  } else if ((A->rows == B->rows) && (A->columns == B->columns)) {
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
  } else if ((A->rows < 1) && (A->columns < 1)) {
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
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;
  if (A->matrix == NULL || B->matrix == NULL) {
    error = INCORRECT_MATRIX;
  } else if (A->columns == B->rows) {
    error = s21_create_matrix(A->rows, B->columns, result);
    if (error == OK) {
      for (int i = 0; i < A->rows; ++i) {
        for (int k = 0; k < B->columns; ++k) {
          for (int j = 0; j < A->columns; ++j) {
            result->matrix[i][k] += A->matrix[i][j] * B->matrix[j][k];
          }
        }
      }
    }
  } else {
    error = FAILED_MATRIX;
  }
  return error;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = OK;
  if ((A->columns < 1) || (A->rows < 1)) {
    error = INCORRECT_MATRIX;
  } else if (A->matrix == NULL) {
    error = FAILED_MATRIX;
  } else {
    error = s21_create_matrix(A->columns, A->rows, result);
    if (error == OK) {
      for (int i = 0; i < A->rows; ++i) {
        for (int k = 0; k < A->columns; ++k) {
          result->matrix[k][i] = A->matrix[i][k];
        }
      }
    }
  }
  return error;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = OK;
  if (A->rows < 1 || A->columns < 1 || A->rows != A->columns) {
    error = INCORRECT_MATRIX;
  } else if (A->matrix == NULL) {
    error = FAILED_MATRIX;
  } else {
    error = s21_create_matrix(A->rows, A->columns, result);
    if (error == OK) {
      for (int i = 0; i < A->rows; ++i) {
        for (int j = 0; j < A->columns; ++j) {
          matrix_t minor;
          int rows = A->rows <= 1 ? 2 : A->rows;
          int colms = A->columns <= 1 ? 2 : A->columns;
          error = s21_create_matrix(rows - 1, colms - 1, &minor);
          if (error != OK) {
            break;
          }
          int subi = 0, subj = 0;
          for (int k = 0; k < A->rows; ++k) {
            if (k == i)
              continue;
            for (int l = 0; l < A->columns; ++l) {
              if (l == j)
                continue;
              minor.matrix[subi][subj] = A->matrix[k][l];
              subj++;
            }
            subi++;
            subj = 0;
          }
          double minor_det;
          error = s21_determinant(&minor, &minor_det);
          if (error != OK) {
            s21_remove_matrix(&minor);
            break;
          }
          result->matrix[i][j] = minor_det * pow((-1), i + j);
          s21_remove_matrix(&minor);
        }
      }
    }
  }
  return error;
}

int s21_determinant(matrix_t *A, double *result) {
  int error = OK;
  if (A->rows < 1 || A->columns < 1 || A->rows != A->columns) {
    error = INCORRECT_MATRIX;
  } else if (A->matrix == NULL) {
    error = FAILED_MATRIX;
  }
  if (A->columns == 1) {
    *result = A->matrix[0][0];
  } else if (A->columns == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else {
    *result = 0;
    matrix_t minor;
    for (int i = 0; i < A->columns; ++i) {
      int rows = A->rows <= 1 ? 2 : A->rows;
      int colms = A->columns <= 1 ? 2 : A->columns;
      error = s21_create_matrix(rows - 1, colms - 1, &minor);
      if (error == OK) {
        for (int j = 1; j < A->rows; ++j) {
          for (int k = 0; k < A->columns; ++k) {
            if (k < i) {
              minor.matrix[j - 1][k] = A->matrix[j][k];
            } else if (k > i) {
              minor.matrix[j - 1][k - 1] = A->matrix[j][k];
            }
          }
        }
        double minor_det;
        s21_determinant(&minor, &minor_det);
        *result += A->matrix[0][i] * minor_det * pow((-1), i + 0);
        s21_remove_matrix(&minor);
      } else {
        break;
      }
    }
  }
  return error;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = OK;
  if (A->columns != A->rows) {
    error = FAILED_MATRIX;
  } else if (A->matrix == NULL) {
    error = INCORRECT_MATRIX;
  } else {
    error = s21_create_matrix(A->rows, A->columns, result);
    if (error == OK) {
      double determent;
      error = s21_determinant(A, &determent);
      if (error == OK && determent != 0) {
        matrix_t minor = {0};
        error = s21_create_matrix(A->rows, A->columns, &minor);
        if (error == OK) {
          error = s21_calc_complements(A, &minor);
          if (error == OK) {
            error = s21_transpose(&minor, A);
            if (error == OK) {
              s21_mult_number(A, 1 / determent, result);
            }
          }
        }
        s21_remove_matrix(&minor);
      } else {
        error = FAILED_MATRIX;
      }
    }
  }
  return error;
}
int check_matrix_sub_and_sum(matrix_t *A, matrix_t *B) {
  int error = OK;
  if ((A->rows != B->rows) || (A->columns != B->columns)) {
    error = FAILED_MATRIX;
  } else if ((A->matrix == NULL) || (B->matrix == NULL)) {
    error = INCORRECT_MATRIX;
  }
  return error;
}