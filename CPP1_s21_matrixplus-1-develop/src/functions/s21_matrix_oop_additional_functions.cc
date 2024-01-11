#include "../s21_matrix_oop.hh"

double S21Matrix::Triangulate() {
  if (rows_ != cols_) {
    throw std::invalid_argument("the matrix is not square");
  }
  int n = rows_;
  double res = 1.0;
  for (int i = 0; i < n; i++) {
    int maxRow = i;
    for (int j = i + 1; j < n; j++) {
      if (fabs(matrix_[j][i]) > fabs(matrix_[maxRow][i])) {
        maxRow = j;
      }
    }
    if (i != maxRow) {
      SwapMaxRows(matrix_, maxRow, i);
      res *= -1.0;
    }
    for (int i = 0; i < cols_ - 1; i++) {
      for (int j = i + 1; j < rows_; j++) {
        double row_multiplier = matrix_[j][i] / matrix_[i][i];
        for (int l = 0; l < cols_; l++) {
          matrix_[j][l] -= (row_multiplier * matrix_[i][l]);
        }
      }
    }
  }
  return res;
}

void S21Matrix::SwapMaxRows(double** matrix, int maxRow, int j) {
  for (int c = 0; c < cols_; c++) {
    double temp = matrix[j][c];
    matrix[j][c] = matrix[maxRow][c];
    matrix[maxRow][c] = temp;
  }
}

int S21Matrix::getRow() const noexcept { return rows_; }
int S21Matrix::getCol() const noexcept { return cols_; }

void S21Matrix::setRow(const int row) {
  S21Matrix temp(row, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      temp.matrix_[i][j] = matrix_[i][j];
    }
  }
  *this = temp;
}

void S21Matrix::setCol(const int col) {
  S21Matrix temp(rows_, col);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      temp.matrix_[i][j] = matrix_[i][j];
    }
  }
  *this = temp;
}

void S21Matrix::MatrixFill(double* array) {
  int k = 0;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = array[k];
      k++;
    }
  }
}

// int main() {
//     double tmp[16] = {9, 2, 2, 9, 1, 9, 3, 4, 2, 9, 2, 2, 9, 5, 5, 9};
//  S21Matrix a = S21Matrix(4, 4);
// //  S21Matrix b = S21Matrix(2,2);
// // int k = 2;
// // a(0, 0) = -1;
// // a(0, 1) = -2;
// // a(0, 2) = 2;
// // a(1, 0) = 2;
// // a(1, 1) = 0;
// // a(1, 2) = 1;
// // a(2, 0) = 3;
// // a(2, 1) = 4;
// // a(2, 2) = 5;
// // for (int i = 0; i < 3; i++){
// //         for (int j = 0; j < 3; j++){
// //             a(i,j) = k;
// //             k++;
// //             a(2, 2) = 11;
// //             std::cout<< a(i,j)<<" ";
// //             // b(i,j) = 1;
// //         }
//         // std::cout<<"\n";
// // }

// // int result = a.Determinant();
// // S21Matrix b = a.InverseMatrix();
// a.MatrixFill(tmp);
// for (int i = 0; i < 4; i++){
//         for (int j = 0; j < 4; j++){
//             std::cout<< a(i,j)<<" ";
//             // b(i,j) = 1;
//         }
//         std::cout<<"\n";
// }
// // std::cout<< result;
//  return 0;
// }