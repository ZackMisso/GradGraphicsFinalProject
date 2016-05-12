#ifndef __RECTPRISM_H__
#define __RECTPRISM_H__

#include "geometry.h"

class RectPrismf : public Geometryf {
private:
  BBoxf prism;
public:
  RectPrismf();
  RectPrismf(Vec3f p,Vec3f d);
  RectPrismf(BBoxf box);
  // geometry methods
  virtual BBoxf getBBox();
  virtual bool containsPoint(Vec3f point);
  virtual void writeToFile(ofstream& file);
  virtual void readFromFile(ifstream& file);
  virtual void render(RenderMode rm);
  // getter methods
  BBoxf getPrism();
  Vec3f getPosition();
  Vec3f getDimension();
  // setter methods
  void setPrism(BBoxf param);
  void setPosition(Vec3f param);
  void setDimension(Vec3f param);
};

class RectPrismd : public Geometryd {
private:
  BBoxd prism;
public:
  RectPrismd();
  RectPrismd(Vec3d p,Vec3d d);
  RectPrismd(BBoxd box);
  // geometry methods
  virtual BBoxd getBBox();
  virtual bool containsPoint(Vec3d point);
  virtual void writeToFile(ofstream& file);
  virtual void readFromFile(ifstream& file);
  virtual void render(RenderMode rm);
  // getter methods
  BBoxd getPrism();
  Vec3d getPosition();
  Vec3d getDimension();
  // setter methods
  void setPrism(BBoxd param);
  void setPosition(Vec3d param);
  void setDimension(Vec3d param);
};

#endif
