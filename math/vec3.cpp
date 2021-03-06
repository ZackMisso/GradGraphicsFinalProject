#include "vec3.h"
#include <tgmath.h>
#include <iostream>

using namespace std;

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

void Vec3f::normalize() {
  float mag = sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
  if(mag!=0.0f) {
    v[0]/=mag;
    v[1]/=mag;
    v[2]/=mag;
  }
}

float Vec3f::mag() {
  return sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
}

float Vec3f::sqrMag() {
  return v[0]*v[0]+v[1]*v[1]+v[2]*v[2];
}

void Vec3f::debug() {
  cout<<"("<<v[0]<<","<<v[1]<<","<<v[2]<<")"<<endl;
}

Vec3f Vec3f::operator+(Vec3f other) {
  return Vec3f(v[0]+other[0], v[1]+other[1], v[2]+other[2]);
}

Vec3f Vec3f::operator-(Vec3f other) {
  return Vec3f(v[0]-other[0], v[1]-other[1], v[2]-other[2]);
}

//Vec3f operator-(Vec3f& one,Vec3f& two) const {
//  return Vec3f(one[0]-two[0], one[1]-two[1], one[2]-two[2]);
//}

Vec3f Vec3f::operator^(Vec3f other) {
  Vec3f vec;
  vec[0] = v[1]*other[2]-other[1]*v[2];
  vec[1] = v[2]*other[0]-other[2]*v[0];
  vec[2] = v[0]*other[1]-other[0]*v[1];
  return vec;
}

float Vec3f::operator*(Vec3f other) {
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

void Vec3d::normalize() {
  double mag = sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
  if(mag!=0.0) {
    v[0]/=mag;
    v[1]/=mag;
    v[2]/=mag;
  }
}

double Vec3d::mag() {
  return sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
}

double Vec3d::sqrMag() {
  return v[0]*v[0]+v[1]*v[1]+v[2]*v[2];
}

void Vec3d::debug() {
  cout<<"("<<v[0]<<","<<v[1]<<","<<v[2]<<")"<<endl;
}

Vec3d Vec3d::operator+(Vec3d other) {
  return Vec3d(v[0]+other[0], v[1]+other[1], v[2]+other[2]);
}

Vec3d Vec3d::operator-(Vec3d other) {
  return Vec3d(v[0]-other[0], v[1]-other[1], v[2]-other[2]);
}

//Vec3d operator-(Vec3d& one,Vec3d& two) const {
//  return Vec3d(one[0]-two[0], one[1]-two[1], one[2]-two[2]);
//}

Vec3d Vec3d::operator^(Vec3d other) {
  Vec3d vec;
  vec[0] = v[1]*other[2]-other[1]*v[2];
  vec[1] = v[2]*other[0]-other[2]*v[0];
  vec[2] = v[0]*other[1]-other[0]*v[1];
  return vec;
}

double Vec3d::operator*(Vec3d other) {
  return v[0]*other[0] + v[1]*other[1] + v[2]*other[2];
}

double& Vec3d::operator[](int val) {
  return v[val];
}
