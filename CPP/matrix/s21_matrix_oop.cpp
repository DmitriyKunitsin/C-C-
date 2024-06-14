#include "s21_matrix_oop.h"

int main() {
  S21Matrix test;
  S21Matrix test2(5, 5);
  S21Matrix test3(test2);
  S21Matrix test4(std::move(test2));

  return 0;
}

S21Matrix::S21Matrix() {
  this->rows_ = 0;
  this->cols_ = 0;
  this->matrix_ = nullptr;
}
S21Matrix::S21Matrix(int row, int col) { CreatedMatrix(row, col); };
S21Matrix::S21Matrix(const S21Matrix& other) {
  CopyMatrix(other);
  std::cout << "Copy" << std::endl;
}  // конструктор копирования

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
    other.ZeroMatrix();
  std::cout << "Move" << std::endl;
}  // конструктор перемещения

S21Matrix::~S21Matrix() { RemoveMatrix(); }

void S21Matrix::ZeroMatrix() {
  this->rows_ = 0;
  this->cols_ = 0;
  this->matrix_ = nullptr;
}
void S21Matrix::CreatedMatrix(int row, int col) {
  if (row < 1 || col < 1) {
    this->rows_ = 0;
    this->cols_ = 0;
    this->matrix_ = nullptr;
    throw std::length_error("column and rows < 1");
  } else {
    this->rows_ = row;
    this->cols_ = col;
    this->matrix_ = new double*[rows_];
    if (this->matrix_ != nullptr) {
      for (int i = 0; i < col; ++i) {
        this->matrix_[i] = new double[cols_];
        if (this->matrix_[i] == nullptr) {
          throw std::length_error("Failed to create matrix column");
          break;
        }
      }
    }
    for(int i = 0; i < row; ++i) {
      for(int j = 0; j < col; ++j) {
        this->matrix_[i][j] = 0;
      }
    }
  }
}

void S21Matrix::CopyMatrix(const S21Matrix& other) {
  CreatedMatrix(other.rows_, other.cols_);
  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < this->cols_; ++j) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

void S21Matrix::RemoveMatrix() {
  if (this->matrix_ == nullptr) {
    this->cols_ = 0;
    this->rows_ = 0;
  } else {
    for (int i = 0; i < this->rows_; ++i) {
      delete[] this->matrix_[i];
    }
    delete[] this->matrix_;
    this->cols_ = 0;
    this->rows_ = 0;
  }
}