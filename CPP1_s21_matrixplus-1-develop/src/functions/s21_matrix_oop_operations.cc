#include "../s21_matrix_oop.hh"

bool S21Matrix::EqMatrix(const S21Matrix& other) const noexcept {
  int result = true;
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    result = false;
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (fabs(matrix_[i][j] - other.matrix_[i][j]) > EPS) result = false;
      }
    }
  }
  return result;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range("different matrix dimensions");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::out_of_range("different matrix dimensions");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) noexcept {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (rows_ != other.cols_ || cols_ != other.rows_) {
    throw std::invalid_argument("different matrix dimensions");
  }
  S21Matrix result = S21Matrix(rows_, other.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int k = 0; k < cols_; k++) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  *this = result;
}

S21Matrix S21Matrix::Transpose() const {
  S21Matrix new_matrix(cols_, rows_);
  for (int i = 0; i < cols_; i++) {
    for (int j = 0; j < rows_; j++) {
      new_matrix.matrix_[i][j] = matrix_[j][i];
    }
  }
  return new_matrix;
}

S21Matrix S21Matrix::CalcComplements() const {
  if (rows_ != cols_) {
    throw std::invalid_argument("different matrix dimensions");
  }
  int rows = rows_;
  S21Matrix result(rows_, cols_);
  if (rows_ == 1) {
    result.matrix_[0][0] = 1;
  } else {
    rows--;
    S21Matrix temp(rows, rows);
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < rows_; j++) {
        int index_i = 0;
        for (int m = 0; m < rows_; m++) {
          int index_j = 0;
          if (m != i) {
            for (int k = 0; k < rows_; k++) {
              if (k != j) {
                temp.matrix_[index_i][index_j] = matrix_[m][k];
                index_j++;
              }
            }
            index_i++;
          }
        }
        double element = 0;
        element = temp.Determinant();
        result.matrix_[i][j] = element * pow(-1, i + j);
      }
    }
  }
  return result;
}

double S21Matrix::Determinant() const {
  S21Matrix tmp = *this;
  int sign = tmp.Triangulate();
  double result = 1;
  for (int i = 0; i < rows_; i++) {
    result *= tmp.matrix_[i][i];
  }
  return result * sign;
}

S21Matrix S21Matrix::InverseMatrix() const {
  double determinant = this->Determinant();
  if (determinant == 0) {
    throw std::invalid_argument("matrix determinant is 0");
  }
  int rows = rows_;
  S21Matrix result(rows_, cols_);
  S21Matrix temp1 = this->CalcComplements();
  S21Matrix temp2 = temp1.Transpose();
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rows; j++) {
      result.matrix_[i][j] = temp2.matrix_[i][j] / determinant;
    }
  }
  return result;
}