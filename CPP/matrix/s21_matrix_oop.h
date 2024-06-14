#ifndef MATRIX_H
#define MATRiX_H

#include <iostream>
#include <math.h>

class S21Matrix
{
private:
    int rows_, cols_;         // Rows and columns
    double **matrix_;         // Pointer to the memory where the matrix is allocated
public:
    // Konstruct
    S21Matrix();
    S21Matrix(int row, int col);
    S21Matrix(const S21Matrix& other); // конструктор копирования
    S21Matrix(S21Matrix&& other) noexcept; // конструктор перемещения
    ~S21Matrix();
    // Accessor
    int getRows() const {
        return rows_;
    }
    int getCols() const {
        return cols_;
    }
    // Mutators
    void setRows(int rows) {
        if(rows_ < rows) {
            CreatedMatrix(rows, cols_);
        } else if(rows_ > rows){
            CopyMatrix(*this);
        }
    }
    void setCols(int cols) {
        if(cols_ < cols) {
            CreatedMatrix(rows_, cols);
        } else if(cols_ > cols) {
            CopyMatrix(*this);
        }
    }
    // Methods
    void ZeroMatrix();
    void CreatedMatrix(int row, int col);
    void CopyMatrix(const S21Matrix& other);
    void RemoveMatrix();
};



#endif