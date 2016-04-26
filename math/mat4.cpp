#include "mat4.h"
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

Mat4f::Mat4f() {
  for(int i=0;i<16;i++)
    matrix[i] = 0.0f;
}

void Mat4f::multiply(Mat4f other) {
  float one = matrix[0]*other[0] + matrix[4]*other[1] + matrix[8]*other[2] + matrix[12]*other[3];
  float two = matrix[1]*other[0] + matrix[5]*other[1] + matrix[9]*other[2] + matrix[13]*other[3];
  float three = matrix[2]*other[0] + matrix[6]*other[1] + matrix[10]*other[2] + matrix[14]*other[3];
  float four = matrix[3]*other[0] + matrix[7]*other[1] + matrix[11]*other[2] + matrix[15]*other[3];
  float five = matrix[0]*other[4] + matrix[4]*other[5] + matrix[8]*other[6] + matrix[12]*other[7];
  float six = matrix[1]*other[4] + matrix[5]*other[5] + matrix[9]*other[6] + matrix[13]*other[7];
  float seven = matrix[2]*other[4] + matrix[6]*other[5] + matrix[10]*other[6] + matrix[14]*other[7];
  float eight = matrix[3]*other[4] + matrix[7]*other[5] + matrix[11]*other[6] + matrix[15]*other[7];
  float nine = matrix[0]*other[8] + matrix[4]*other[9] + matrix[8]*other[10] + matrix[12]*other[11];
  float ten = matrix[1]*other[8] + matrix[5]*other[9] + matrix[9]*other[10] + matrix[13]*other[11];
  float eleven = matrix[2]*other[8] + matrix[6]*other[9] + matrix[10]*other[10] + matrix[14]*other[11];
  float twelve = matrix[3]*other[8] + matrix[7]*other[9] + matrix[11]*other[10] + matrix[15]*other[11];
  float thirteen = matrix[0]*other[12] + matrix[4]*other[13] + matrix[8]*other[14] + matrix[12]*other[15];
  float fourteen = matrix[1]*other[12] + matrix[5]*other[13] + matrix[9]*other[14] + matrix[13]*other[15];
  float fifteen = matrix[2]*other[12] + matrix[6]*other[13] + matrix[10]*other[14] + matrix[14]*other[15];
  float sixteen = matrix[3]*other[12] + matrix[7]*other[13] + matrix[11]*other[14] + matrix[15]*other[15];
  matrix[0] = one;
  matrix[1] = two;
  matrix[2] = three;
  matrix[3] = four;
  matrix[4] = five;
  matrix[5] = six;
  matrix[6] = seven;
  matrix[7] = eight;
  matrix[8] = nine;
  matrix[9] = ten;
  matrix[10] = eleven;
  matrix[11] = twelve;
  matrix[12] = thirteen;
  matrix[13] = fourteen;
  matrix[14] = fifteen;
  matrix[15] = sixteen;
}

void Mat4f::multMatrix() {
  glMultMatrixf(matrix);
}

float& Mat4f::operator[](int val) {
  return matrix[val];
}

/////////////////////////// DOUBLE VERSION ////////////////////////

Mat4d::Mat4d() {
  for(int i=0;i<16;i++)
    matrix[i] = 0.0;
}

void Mat4d::multiply(Mat4d other) {
  double one = matrix[0]*other[0] + matrix[4]*other[1] + matrix[8]*other[2] + matrix[12]*other[3];
  double two = matrix[1]*other[0] + matrix[5]*other[1] + matrix[9]*other[2] + matrix[13]*other[3];
  double three = matrix[2]*other[0] + matrix[6]*other[1] + matrix[10]*other[2] + matrix[14]*other[3];
  double four = matrix[3]*other[0] + matrix[7]*other[1] + matrix[11]*other[2] + matrix[15]*other[3];
  double five = matrix[0]*other[4] + matrix[4]*other[5] + matrix[8]*other[6] + matrix[12]*other[7];
  double six = matrix[1]*other[4] + matrix[5]*other[5] + matrix[9]*other[6] + matrix[13]*other[7];
  double seven = matrix[2]*other[4] + matrix[6]*other[5] + matrix[10]*other[6] + matrix[14]*other[7];
  double eight = matrix[3]*other[4] + matrix[7]*other[5] + matrix[11]*other[6] + matrix[15]*other[7];
  double nine = matrix[0]*other[8] + matrix[4]*other[9] + matrix[8]*other[10] + matrix[12]*other[11];
  double ten = matrix[1]*other[8] + matrix[5]*other[9] + matrix[9]*other[10] + matrix[13]*other[11];
  double eleven = matrix[2]*other[8] + matrix[6]*other[9] + matrix[10]*other[10] + matrix[14]*other[11];
  double twelve = matrix[3]*other[8] + matrix[7]*other[9] + matrix[11]*other[10] + matrix[15]*other[11];
  double thirteen = matrix[0]*other[12] + matrix[4]*other[13] + matrix[8]*other[14] + matrix[12]*other[15];
  double fourteen = matrix[1]*other[12] + matrix[5]*other[13] + matrix[9]*other[14] + matrix[13]*other[15];
  double fifteen = matrix[2]*other[12] + matrix[6]*other[13] + matrix[10]*other[14] + matrix[14]*other[15];
  double sixteen = matrix[3]*other[12] + matrix[7]*other[13] + matrix[11]*other[14] + matrix[15]*other[15];
  matrix[0] = one;
  matrix[1] = two;
  matrix[2] = three;
  matrix[3] = four;
  matrix[4] = five;
  matrix[5] = six;
  matrix[6] = seven;
  matrix[7] = eight;
  matrix[8] = nine;
  matrix[9] = ten;
  matrix[10] = eleven;
  matrix[11] = twelve;
  matrix[12] = thirteen;
  matrix[13] = fourteen;
  matrix[14] = fifteen;
  matrix[15] = sixteen;
}

void Mat4d::multMatrix() {
  glMultMatrixd(matrix);
}

double& Mat4d::operator[](int val) {
  return matrix[val];
}
