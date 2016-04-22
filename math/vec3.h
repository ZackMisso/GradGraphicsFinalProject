#ifndef __VEC3_H__
#define __VEC3_H__

class Vec3f {
private:
  float v[3];
public:
  Vec3f();
  Vec3f(float x,float y,float z);
  // operator overloads
  Vec3f operator+(Vec3f& other) const; // addition
  Vec3f operator-(Vec3f& other) const; // subtraction
  Vec3f operator^(Vec3f& other) const; // cross-product
  float operator*(Vec3f& other) const; // dot-product
  float& operator[](int val); // array operator
};

class Vec3d {
private:
  double v[3];
public:
  Vec3d();
  Vec3d(double x,double y,double z);
  // operator overloads
  Vec3d operator+(Vec3d& other) const; // addition
  Vec3d operator-(Vec3d& other) const; // subtraction
  Vec3d operator^(Vec3d& other) const; // cross-product
  double operator*(Vec3d& other) const; // dot-product
  double& operator[](int val); // array operator
};

#endif
