
#include "main.h"

int main() {
  // S21Matrix test(12, 10);

  try {
    // S21Matrix test1(2,2) = {1,2};
    // S21Matrix test2(4,4);
    // for(int i = 0; i < test2.rows_; ++i) {
    //   for(int j = 0; j < test2.cols_; ++j) {
    //     std::cout << test2[i][j] << std::endl;
    //   }
    // }
    // рабочие функции
  } catch (const char* error_message) {
    std::cout << error_message << std::endl;
    // обработка исключений
  }
  return 0;
}

// S21Matrix::S21Matrix(int row, int col) { CreatedMatrix(row, col); }
// S21Matrix::~S21Matrix() {}
void S21Matrix::CopyMatrix(const S21Matrix& other) {
  CreatedMatrix(other.rows_, other.cols_);
  for (int i = 0; i < this->rows_; ++i) {
    for (int j = 0; j < this->cols_; ++j) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
}
void S21Matrix::CreatedMatrix(int rows, int column) {
  if (rows < 1 || column < 1) {
    this->rows_ = 0;
    this->cols_ = 0;
    this->matrix_ = nullptr;
    throw std::length_error("column and rows < 1");
  } else {
    this->rows_ = rows;
    this->cols_ = column;
    this->matrix_ = new double*[rows_];
    if (this->matrix_ != nullptr) {
      for (int i = 0; i < column; ++i) {
        this->matrix_[i] = new double[cols_];
        if (this->matrix_[i] == nullptr) {
          throw std::length_error("Failed to create matrix column");
          break;
        }
      }
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
S21Matrix::~S21Matrix() { RemoveMatrix(); }

#pragma region EqMatrix
bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool result = true;
  if ((this->rows_ == other.rows_) && (this->cols_ == other.cols_)) {
    for (int i = 0; i < this->rows_; ++i) {
      for (int j = 0; j < this->cols_; ++j) {
        if ((fabs(this->matrix_[i][j]) - other.matrix_[i][j]) > 1e-7) {
          result = false;
        }
      }
    }
  }
  return result;
}
#pragma endregion

#pragma region SumMatrix
void S21Matrix::SumMatrix(const S21Matrix& other) {
  if ((this->rows_ == other.rows_) && (this->cols_ == other.cols_)) {
    for (int i = 0; i < this->rows_; ++i) {
      for (int k = 0; k < this->cols_; ++i) {
        this->matrix_[i][k] = this->matrix_[i][k] + other.matrix_[i][k];
      }
    }
  } else {
    throw std::out_of_range("matrices of different sizes");
  }
}

#pragma endregion

// S21Matrix operator+(S21Matrix s1, S21Matrix s2) {}
