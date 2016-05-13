#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include "bbox.h"
#include "../render/renderInclude.h"
#include <iostream>
#include <fstream>

using namespace std;

enum GeometryType {
  SPHERE = 0,
  CYLINDER = 1,
  RECT_PRISM = 2,
  VOXEL = 3
};

class Geometryf {
private:
public:
  Geometryf();
  ~Geometryf();
  virtual BBoxf getBBox();
  virtual bool containsPoint(Vec3f point);
  virtual void writeToFile(ofstream& file);
  virtual void readFromFile(ifstream& file);
  virtual void render(RenderMode rm);
  virtual void updatePosition(Vec3f pos);
};

class Geometryd {
private:
public:
  Geometryd();
  ~Geometryd();
  virtual BBoxd getBBox();
  virtual bool containsPoint(Vec3d point);
  virtual void writeToFile(ofstream& file);
  virtual void readFromFile(ifstream& file);
  virtual void render(RenderMode rm);
  virtual void updatePosition(Vec3d pos);
};

#endif
