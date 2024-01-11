#include "../s21_matrix_oop.hh"

S21Matrix S21Matrix::operator+(const S21Matrix& o) {
  S21Matrix result(*this);
  result.SumMatrix(o);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& o) {
  S21Matrix result(*this);
  result.SubMatrix(o);
  return result;
}
S21Matrix S21Matrix::operator*(const S21Matrix& o) {
  S21Matrix result(*this);
  result.MulMatrix(o);
  return result;
}

S21Matrix S21Matrix::operator*(double num) {
  S21Matrix result(*this);
  result.MulNumber(num);
  return result;
}

bool S21Matrix::operator==(const S21Matrix& o) { return EqMatrix(o); }

S21Matrix S21Matrix::operator=(const S21Matrix& o) {
  this->~S21Matrix();
  rows_ = o.rows_;
  cols_ = o.cols_;
  matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      this->matrix_[i][j] = o.matrix_[i][j];
    }
  }
  return *this;
}

S21Matrix S21Matrix::operator=(S21Matrix&& o) {
  this->~S21Matrix();
  if (&o != this) {
    matrix_ = o.matrix_;
    rows_ = o.rows_;
    cols_ = o.cols_;
    o.cols_ = 0;
    o.rows_ = 0;
    o.matrix_ = nullptr;
  }
  return *this;
}

void S21Matrix::operator+=(const S21Matrix& o) { SumMatrix(o); }
void S21Matrix::operator-=(const S21Matrix& o) { SubMatrix(o); }
void S21Matrix::operator*=(const S21Matrix& o) { MulMatrix(o); }
void S21Matrix::operator*=(double number) { MulNumber(number); }

double& S21Matrix::operator()(int row, int col) const {
  if (row >= rows_ || col >= cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row][col];
}