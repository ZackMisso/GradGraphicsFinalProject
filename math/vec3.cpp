#include "vec3.h"

Vec3f::Vec3f() {
  v[0] = 0.0f;
  v[1] = 0.0f;
  v[2] = 0.0f;
}

Vec3f::Vec3f(float x,float y,float z) {
  v[0] = x;
  v[1] = y;
  v[2] = z;
}

Vec3f Vec3f::operator+(Vec3f& other) const {
  return Vec3f(v[0]+other[0], v[1]+other[1], v[2]+other[2]);
}

Vec3f Vec3f::operator-(Vec3f& other) const {
  return Vec3f(v[0]-other[0], v[1]-other[1], v[2]-other[2]);
}

Vec3f Vec3f::operator^(Vec3f& other) const {
  Vec3f vec;
  vec[0] = v[1]*other[2]-other[1]*v[2];
  vec[1] = v[2]*other[0]-other[2]*v[0];
  vec[2] = v[0]*other[1]-other[0]*v[1];
  return vec;
}

float Vec3f::operator*(Vec3f& other) const {
  return v[0]*other[0] + v[1]*other[1] + v[2]*other[2];
}

float& Vec3f::operator[](int val) {
  return v[val];
}

Vec3d::Vec3d() {
  v[0] = 0.0;
  v[1] = 0.0;
  v[2] = 0.0;
}

Vec3d::Vec3d(double x,double y,double z) {
  v[0] = x;
  v[1] = y;
  v[2] = z;
}

Vec3d Vec3d::operator+(Vec3d& other) const {
  return Vec3d(v[0]+other[0], v[1]+other[1], v[2]+other[2]);
}

Vec3d Vec3d::operator-(Vec3d& other) const {
  return Vec3d(v[0]-other[0], v[1]-other[1], v[2]-other[2]);
}

Vec3d Vec3d::operator^(Vec3d& other) const {
  Vec3d vec;
  vec[0] = v[1]*other[2]-other[1]*v[2];
  vec[1] = v[2]*other[0]-other[2]*v[0];
  vec[2] = v[0]*other[1]-other[0]*v[1];
  return vec;
}

double Vec3d::operator*(Vec3d& other) const {
  return v[0]*other[0] + v[1]*other[1] + v[2]*other[2];
}

double& Vec3d::operator[](int val) {
  return v[val];
}