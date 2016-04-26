#ifndef __BBOX_H__
#define __BBOX_H__

#include "../math/vec3.h"

class BBoxf {
private:
  Vec3f position;
  Vec3f dimension;
public:
  BBoxf();
  BBoxf(Vec3f p,Vec3f d);
  float longestDim();
  float volume();
  // getter methods
  Vec3f getPosition();
  Vec3f getDimension();
  // setter methods
  void setPosition(Vec3f param);
  void setDimension(Vec3f param);
};

class BBoxd {
private:
  Vec3d position;
  Vec3d dimension;
public:
  BBoxd();
  BBoxd(Vec3d p,Vec3d d);
  double longestDim();
  double volume();
  // getter methods
  Vec3d getPosition();
  Vec3d getDimension();
  // setter methods
  void setPosition(Vec3d param);
  void setDimension(Vec3d param);
};

#endif
