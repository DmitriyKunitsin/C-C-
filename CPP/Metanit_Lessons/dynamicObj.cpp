#include <iostream>

int* createPtr(int value) {
  int* ptr{new int(value)};
  return ptr;
}

void usePtr() {
  int* obj = createPtr(555);
  std::cout << *obj << std::endl;
  delete obj;
  obj = nullptr;
}
int main() {
  int* ptr{new int};

  delete ptr;
  // или

  int* ptr2 = new int;

  delete ptr2;

  int* ptr3{new int()};  // 0

  delete ptr3;

  int* ptr4{new int(5)};  // 5

  delete ptr4;

  usePtr();
  // Выделение памяти под массив

  //   int* arr{new int[4]};  // массив состоит из чисел 0, 0, 0, 0
  // int* arr2 {new int[4] {1,2,3,4}}// массив состоит из чисел 1, 2, 3, 4
  // int* arr3 {new int[4] {1,2}}// массив состоит из чисел 1, 2, 0, 0
  int* arr{new int[4]{1, 2, 3, 4}};
  for (unsigned i{}; i < 4; ++i) {
    std::cout << arr[i] << "\t";
  }
  std::cout << std::endl;
  for (unsigned i{}; i < 4; ++i) {
    std::cout << *(arr + i) << "\t";
  }
  std::cout << std::endl;
  for (int* q{arr}; q != arr + 4; q++) {
    std::cout << *q << "\t";
  }
  std::cout << std::endl;
  delete[] arr;
  arr = nullptr;

  unsigned rows = 3;
  unsigned cols = 3;

  // Создание матрицы
  int** matrix{new int* [rows] {}};
  for (unsigned i{}; i < rows; ++i) {
    matrix[i] = new int[cols]{};
  }
  // Заполнение матрицы
  for (unsigned i{}; i < rows; ++i) {
    std::cout << "Enter data for " << (i + 1) << " row " << std::endl;
    for (unsigned j{}; j < cols; ++j) {
      std::cout << (j + 1) << " column " << std::endl;
      std::cin >> matrix[i][j];
    }
  }
  // Выводи матрицы
  for (unsigned i{}; i < rows; ++i) {
    for (unsigned j{}; j < cols; ++j) {
      std::cout << matrix[i][j] << "\t";
    }
    std::cout << std::endl;
  }
  // Удаление матрицы
  for (unsigned i{}; i < rows; ++i) {
    delete[] matrix[i];
  }
  delete[] matrix;
  return 0;
}