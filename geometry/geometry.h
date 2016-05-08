#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include "bbox.h"

class Geometryf {
private:
public:
  Geometryf();
  ~Geometryf();
  virtual BBoxf getBBox();
  virtual bool containsPoint(Vec3f point);
};

class Geometryd {
private:
public:
  Geometryd();
  ~Geometryd();
  virtual BBoxd getBBox();
  virtual bool containsPoint(Vec3d point);
};

#endif
