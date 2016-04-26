#ifndef __BAKEPOINTMASS_H__
#define __BAKEPOINTMASS_H__

// this class contains the baked point mass data

#include "../math/vec3.h"

class BakePointMassf {
private:
  Vec3f position;
  float radius;
public:
  BakePointMassf();
  BakePointMassf(Vec3f pos,float r);
  void render();
  // getter methods
  Vec3f getPosition();
  float getRadius();
  // setter methods
  void setPosition(Vec3f param);
  void setRadius(float param);
};

class BakePointMassd {
private:
  Vec3d position;
  double radius;
public:
  BakePointMassd();
  BakePointMassd(Vec3d pos,double r);
  void render();
  // getter methods
  Vec3d getPosition();
  double getRadius();
  // setter methods
  void setPosition(Vec3d param);
  void setRadius(double param);
};

#endif
