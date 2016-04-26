#ifndef __QUAT_H__
#define __QUAT_H__

// implementation of quaternions

#include "vec3.h"
#include "mat4.h"

class Quatf {
protected:
  Vec3f v;
  float s;
public:
  Quatf();
  Quatf(float sc,Vec3f vec);
  Quatf(float sc,float x,float y,float z);
  static Quatf makeQuaternionAngleAxis(float angle,Vec3f axis);
  void multiply(Quatf other); // ToDo :: make an operator
  void conjugate(); // ToDo :: make an operator
  Quatf copy();
  Mat4f toMatrix();
  Vec3f rotateVector(Vec3f vec);
  void apply();
  void applyToMatrix(Mat4f* matrix);
  bool isInvalid();
};

class Quatd {
private:
  Vec3d v;
  double s;
public:
  Quatd();
  Quatd(double sc,Vec3d vec);
  Quatd(double sc,double x,double y,double z);
  static Quatd makeQuaternionAngleAxis(double angle,Vec3d axis);
  void multiply(Quatd other); // ToDo :: make an operator
  void conjugate(); // ToDo :: make an operator
  Quatd copy();
  Mat4d toMatrix();
  Vec3d rotateVector(Vec3d vec);
  void apply();
  void applyToMatrix(Mat4d* matrix);
  bool isInvalid();
};

#endif
