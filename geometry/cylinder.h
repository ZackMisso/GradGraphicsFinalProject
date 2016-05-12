#ifndef __CYLINDER_H__
#define __CYLINDER_H__

#include "geometry.h"
#include "../math/vec3.h"

class Cylinderf : public Geometryf {
private:
  Vec3f position; // position of base
  float radius;
  float height;
public:
  Cylinderf();
  Cylinderf(Vec3f pos,float r,float h);
  // geometry methods
  virtual BBoxf getBBox();
  virtual bool containsPoint(Vec3f point);
  virtual void writeToFile(ofstream& file);
  virtual void readFromFile(ifstream& file);
  virtual void render(RenderMode rm);
  virtual void updatePosition(Vec3f pos);
  // getter methods
  Vec3f getPosition();
  float getRadius();
  float getHeight();
  // setter methods
  void setPosition(Vec3f param);
  void setRadius(float param);
  void setHeight(float param);
};

class Cylinderd : public Geometryd {
private:
  Vec3d position; // position of base
  double radius;
  double height;
public:
  Cylinderd();
  Cylinderd(Vec3d pos,double r,double h);
  // geometry methods
  virtual BBoxd getBBox();
  virtual bool containsPoint(Vec3d point);
  virtual void writeToFile(ofstream& file);
  virtual void readFromFile(ifstream& file);
  virtual void render(RenderMode rm);
  virtual void updatePosition(Vec3d pos);
  // getter methods
  Vec3d getPosition();
  double getRadius();
  double getHeight();
  // setter methods
  void setPosition(Vec3d param);
  void setRadius(double param);
  void setHeight(double param);
};

#endif
