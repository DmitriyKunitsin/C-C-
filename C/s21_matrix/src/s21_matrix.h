#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <stdlib.h>
#include <math.h>

#define FAILED_MATRIX 2
#define INCORRECT_MATRIX 1
#define OK 0

#define SUCCESS 1
#define FAILURE 0

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;
/*Создание матрицы*/
int s21_create_matrix(int rows, int columns, matrix_t *result);
/*Очищение матрицы*/
void s21_remove_matrix(matrix_t *A);
/*Сравнение*/
int s21_eq_matrix(matrix_t *A, matrix_t *B);
/*Сложение*/
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
/*Вычитание*/
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
/*Умножение матрицы на число*/
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
/*Умножение матрицы на матрицу*/
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
/*Функция для проверки матрицы 0 - ОК 1 - некоректная матрица 2 - несовпадающие размеры матриц;*/
int check_matrix_sub_and_sum(matrix_t *A, matrix_t *B);
/*Транспонирование матрицы*/
int s21_transpose(matrix_t *A, matrix_t *result);
/*Минор матрицы и матрица алгебраических дополнений */
int s21_calc_complements(matrix_t *A, matrix_t *result);
/*Определитель матрицы*/
int s21_determinant(matrix_t *A, double *result);
/*Обратная матрица*/
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif