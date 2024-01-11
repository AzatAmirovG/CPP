#ifndef S21_MATRIX_OOP
#define S21_MATRIX_OOP

#define EPS 10E-9

#include <cmath>
#include <exception>
#include <iostream>

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;

 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  //-------Matrix operations---------------------------------------------//
  bool EqMatrix(const S21Matrix& other) const noexcept;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() const;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  S21Matrix InverseMatrix() const;

  //-------Operators-Overload--------------------------------------------//
  S21Matrix operator+(const S21Matrix& o);
  S21Matrix operator-(const S21Matrix& o);
  S21Matrix operator*(const S21Matrix& o);
  S21Matrix operator*(double num);
  bool operator==(const S21Matrix& o);
  S21Matrix operator=(const S21Matrix& o);
  S21Matrix operator=(S21Matrix&& o);
  void operator+=(const S21Matrix& o);
  void operator-=(const S21Matrix& o);
  void operator*=(const S21Matrix& o);
  void operator*=(double number);
  double& operator()(int row, int col) const;

  //-------Additional-functions------------------------------------------//
  double Triangulate();
  int getRow() const noexcept;
  int getCol() const noexcept;
  void setRow(const int row);
  void setCol(const int col);
  void SwapMaxRows(double** matrix, int maxRow, int j);
  void MatrixFill(double* array);
};

#endif