/*
Заполнить матрицу числами от 1 до N2 ули
Пример:
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9
*/
#include "function.h"

int main(void) {
  int matrix[N][N];
  fillMatrixInSpiralOrder(matrix);
  printMatrix(matrix);
  return 0;
}