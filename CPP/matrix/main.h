#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <math.h>

class S21Matrix
{
private:
    int rows_, cols_;
    double **matrix_; 
public:
    S21Matrix();
    // S21Matrix(int row, int col);
    S21Matrix(int row, int col);
    S21Matrix(const S21Matrix& other);
    ~S21Matrix();
    void CreatedMatrix(int rows, int column);
    void RemoveMatrix();
    void SumMatrix(const S21Matrix& other);
    bool EqMatrix(const S21Matrix& other);
    void CopyMatrix(const S21Matrix& other);
    // double& operator()(int row, int col) {
    //     if (row >= 0 && row < rows_ && col >= 0 && col < cols_) {
    //         return matrix_[row][col];
    //     } else {
    //         std::cerr << "Index out of bounds!" << std::endl;   
    //         static double dummy; // Возвращаем временную переменную
    //         return dummy;
    //     }
    // }
    S21Matrix S21Matrix::operator = (const S21Matrix s1) {
        this->RemoveMatrix();
        this->CopyMatrix(s1);
        return *this;
    }
    // S21Matrix S21Matrix::operator +(const S21Matrix s1) {
        
    // }
    
};

S21Matrix::S21Matrix(const S21Matrix& other) { CopyMatrix(other); }
S21Matrix::S21Matrix() {
  this->rows_ = 0;
  this->cols_ = 0;
  this->matrix_ = nullptr;
}
S21Matrix::S21Matrix(int row, int col) {
  // this->rows_ = row;
  // this->cols_ = col;
  CreatedMatrix(row, col);
}

#endif 
