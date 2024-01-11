#include "../s21_matrix_oop.hh"

S21Matrix::S21Matrix() {
  rows_ = 1;
  cols_ = 1;
  matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows <= 0 || cols <= 0) {
    throw std::invalid_argument("Invalid dimensions");
  }
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : S21Matrix(other.rows_, other.cols_) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  if (&other != this) {
    matrix_ = other.matrix_;
    rows_ = other.rows_;
    cols_ = other.cols_;
    other.cols_ = 0;
    other.rows_ = 0;
    other.matrix_ = nullptr;
  }
}

S21Matrix::~S21Matrix() {
  if (matrix_) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
    // delete [] Matrix;
  }
}