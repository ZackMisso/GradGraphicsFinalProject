#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "geometry.h"
#include "../math/vec3.h"

class Spheref : Geometryf {
private:
  Vec3f position;
  float radius;
public:
  Spheref();
  Spheref(Vec3f p,float r);
  // geometry methods
  virtual BBoxf getBBox();
  virtual bool containsPoint(Vec3f point);
  // getter methods
  Vec3f getPosition();
  float getRadius();
  // setter methods
  void setPosition(Vec3f param);
  void setRadius(float param);
};

class Sphered : public Geometryd {
private:
  Vec3d position;
  double radius;
public:
  Sphered();
  Sphered(Vec3d p,double r);
  // geometry methods
  virtual BBoxd getBBox();
  virtual bool containsPoint(Vec3d point);
  // getter methods
  Vec3d getPosition();
  double getRadius();
  // setter methods
  void setPosition(Vec3d param);
  void setRadius(double param);
};

#endif
