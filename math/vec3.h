#ifndef __VEC3_H__
#define __VEC3_H__

class Vec3f {
private:
  float v[3];
public:
  Vec3f();
  Vec3f(float x,float y,float z);
  // methods
  void normalize();
  float mag();
  float sqrMag();
  // operator overloads
  Vec3f operator+(Vec3f other); // addition
  Vec3f operator-(Vec3f other); // subtraction
  Vec3f operator^(Vec3f other); // cross-product
  float operator*(Vec3f other); // dot-product
  float& operator[](int val); // array operator
};

class Vec3d {
private:
  double v[3];
public:
  Vec3d();
  Vec3d(double x,double y,double z);
  // methods
  void normalize();
  double mag();
  double sqrMag();
  // operator overloads
  Vec3d operator+(Vec3d other); // addition
  Vec3d operator-(Vec3d other); // subtraction
  Vec3d operator^(Vec3d other); // cross-product
  double operator*(Vec3d other); // dot-product
  double& operator[](int val); // array operator
};

#endif
