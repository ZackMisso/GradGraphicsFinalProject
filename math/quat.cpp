#include "quat.h"
#include "math.h"

Quatf::Quatf() {
  v = Vec3f(0,1.0f,0);
  s = 0.0f;
}

Quatf::Quatf(float sc,Vec3f vec) {
  v = vec;
  s = sc;
}

Quatf::Quatf(float sc,float x,float y,float z) {
  v = Vec3f(x,y,z);
  s = sc;
}

Quatf Quatf::makeQuaternionAngleAxis(float angle,Vec3f axis) {
  float halfAngle = angle/2.0f;
  float sined = sin(halfAngle);
  axis.normalize();
  Vec3f newV = Vec3f(axis[0]*sined,axis[1]*sined,axis[2]*sined);
  return Quatf(cos(halfAngle),newV);
}

void Quatf::multiply(Quatf other) {
  if(isInvalid()) {
    s = other.s;
    v = other.v;
  } else if(other.isInvalid()) {
    // do nothing
  } else {
    float tmpS = s*other.s - v*other.v;
    Vec3f v1 = other.v;
    v1[0] *= s;
    v1[1] *= s;
    v1[2] *= s;
    Vec3f v2 = v;
    v2[0] *= other.s;
    v2[1] *= other.s;
    v2[2] *= other.s;
    v = v^other.v;
    v = v+v1;
    v = v+v2;
    s = tmpS;
  }
}

void Quatf::conjugate() {
  Vec3f newV = Vec3f(-v[0],-v[1],-v[2]);
  v = newV;
}

Mat4f Quatf::toMatrix() {
  Mat4f matrix = Mat4f();
  if(isInvalid()) {
    matrix[0] = 1.0f;
    matrix[5] = 1.0f;
    matrix[10] = 1.0f;
    matrix[15] = 1.0f;
    return matrix;
  }
  matrix[0] = 1 - 2*v[1]*v[1] - 2*v[2]*v[2];
  matrix[1] = 2*v[0]*v[1] - 2*s*v[2];
  matrix[2] = 2*v[0]*v[2] + 2*s*v[1];
  matrix[3] = 0.0f;
  matrix[4] = 2*v[0]*v[1] + 2*s*v[2];
  matrix[5] = 1 - 2*v[0]*v[0] - 2*v[2]*v[2];
  matrix[6] = 2*v[1]*v[2] - 2*s*v[0];
  matrix[7] = 0.0f;
  matrix[8] = 2*v[0]*v[2] - 2*s*v[1];
  matrix[9] = 2*v[1]*v[2] + 2*s*v[0];
  matrix[10] = 1 - 2*v[0]*v[0] - 2*v[1]*v[1];
  matrix[11] = 0.0f;
  matrix[12] = 0.0f;
  matrix[13] = 0.0f;
  matrix[14] = 0.0f;
  matrix[15] = 1.0f;
  return matrix;
}

Quatf Quatf::copy() {
  return Quatf(s,v);
}

Vec3f Quatf::rotateVector(Vec3f vec) {
  if(isInvalid())
    return vec;
  Quatf inv = copy();
  Quatf data = Quatf(0.0f,vec[0],vec[1],vec[2]);
  inv.conjugate();
  inv.multiply(data);
  inv.multiply(*this);
  return inv.v;
}

bool Quatf::isInvalid() {
  return s == 0.0f && v[0] == 0.0f && v[1] == 0.0f && v[2] == 0.0f;
}

void Quatf::apply() {
  if(!isInvalid()) {
    toMatrix().multMatrix();
  }
}

void Quatf::applyToMatrix(Mat4f* matrix) {
  if(!isInvalid()) {
    matrix->multiply(toMatrix());
  }
}

///////////////////////// DOUBLE VERSION ////////////////////////

Quatd::Quatd() {
  v = Vec3d(0,1.0,0);
  s = 0.0;
}

Quatd::Quatd(double sc,Vec3d vec) {
  v = vec;
  s = sc;
}

Quatd::Quatd(double sc,double x,double y,double z) {
  v = Vec3d(x,y,z);
  s = sc;
}

Quatd Quatd::makeQuaternionAngleAxis(double angle,Vec3d axis) {
  double halfAngle = angle/2.0;
  double sined = sin(halfAngle);
  axis.normalize();
  Vec3d newV = Vec3d(axis[0]*sined,axis[1]*sined,axis[2]*sined);
  return Quatd(cos(halfAngle),newV);
}

void Quatd::multiply(Quatd other) {
  if(isInvalid()) {
    s = other.s;
    v = other.v;
  } else if(other.isInvalid()) {
    // do nothing
  } else {
    double tmpS = s*other.s - v*other.v;
    Vec3d v1 = other.v;
    v1[0] *= s;
    v1[1] *= s;
    v1[2] *= s;
    Vec3d v2 = v;
    v2[0] *= other.s;
    v2[1] *= other.s;
    v2[2] *= other.s;
    v = v^other.v;
    v = v+v1;
    v = v+v2;
    s = tmpS;
  }
}

void Quatd::conjugate() {
  Vec3d newV = Vec3d(-v[0],-v[1],-v[2]);
  v = newV;
}

Mat4d Quatd::toMatrix() {
  Mat4d matrix = Mat4d();
  if(isInvalid()) {
    matrix[0] = 1.0;
    matrix[5] = 1.0;
    matrix[10] = 1.0;
    matrix[15] = 1.0;
    return matrix;
  }
  matrix[0] = 1 - 2*v[1]*v[1] - 2*v[2]*v[2];
  matrix[1] = 2*v[0]*v[1] - 2*s*v[2];
  matrix[2] = 2*v[0]*v[2] + 2*s*v[1];
  matrix[3] = 0.0;
  matrix[4] = 2*v[0]*v[1] + 2*s*v[2];
  matrix[5] = 1 - 2*v[0]*v[0] - 2*v[2]*v[2];
  matrix[6] = 2*v[1]*v[2] - 2*s*v[0];
  matrix[7] = 0.0;
  matrix[8] = 2*v[0]*v[2] - 2*s*v[1];
  matrix[9] = 2*v[1]*v[2] + 2*s*v[0];
  matrix[10] = 1 - 2*v[0]*v[0] - 2*v[1]*v[1];
  matrix[11] = 0.0;
  matrix[12] = 0.0;
  matrix[13] = 0.0;
  matrix[14] = 0.0;
  matrix[15] = 1.0;
  return matrix;
}

Quatd Quatd::copy() {
  return Quatd(s,v);
}

Vec3d Quatd::rotateVector(Vec3d vec) {
  if(isInvalid())
    return vec;
  Quatd inv = copy();
  Quatd data = Quatd(0.0,vec[0],vec[1],vec[2]);
  inv.conjugate();
  inv.multiply(data);
  inv.multiply(*this);
  return inv.v;
}

bool Quatd::isInvalid() {
  return s == 0.0 && v[0] == 0.0 && v[1] == 0.0 && v[2] == 0.0;
}

void Quatd::apply() {
  if(!isInvalid()) {
    toMatrix().multMatrix();
  }
}

void Quatd::applyToMatrix(Mat4d* matrix) {
  if(!isInvalid()) {
    matrix->multiply(toMatrix());
  }
}
