#ifndef __MAT4_H__
#define __MAT4_H__

// class representing a 4x4 matrix in column order
// It is in column order because that is how OpenGL multMatrix takes
// its inputs.
// Matrix:
// 0 4 8  12
// 1 5 9  13
// 2 6 10 14
// 3 7 11 15

class Mat4f {
public:
  float matrix[16];
  Mat4f();
  void multiply(Mat4f other); // make an operator
  void multMatrix(); // make an operator
  // operator overloads
  float& operator[](int val); // array operator
};

class Mat4d {
public:
  double matrix[16];
  Mat4d();
  void multiply(Mat4d other); // make an operator
  void multMatrix(); // make an operator
  // operator overloads
  double& operator[](int val); // array operator
};

#endif
