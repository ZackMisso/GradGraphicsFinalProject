#ifndef __PHYSICSBODY_H__
#define __PHYSICSBODY_H__

// represents a collection of physics objects within a local area.
// used to speed up collision detection

#include "../dataStructures/array.h"
#include "../physics/physicsObject.h"
#include "../geometry/bbox.h"

class PhysicsBodyf {
private:
  Array<PhysicsObjectf*>* objects;
  BBoxf bbox;
  float proximity; // extra space added to bbox dimensions
public:
  PhysicsBodyf();
  ~PhysicsBodyf();
  void calculateBBox();
  // getter methods
  Array<PhysicsObjectf*>* getObjects();
  BBoxf getBBox();
  float getProximity();
  // setter methods
  void setObjects(Array<PhysicsObjectf*>* param);
  void setBBox(BBoxf param);
  void setProximity(float param);
};

class PhysicsBodyd {
private:
  Array<PhysicsObjectd*>* objects;
  BBoxd bbox;
  double proximity; // extra space added to bbox dimensions
public:
  PhysicsBodyd();
  ~PhysicsBodyd();
  void calculateBBox();
  // getter methods
  Array<PhysicsObjectd*>* getObjects();
  BBoxd getBBox();
  double getProximity();
  // setter methods
  void setObjects(Array<PhysicsObjectd*>* param);
  void setBBox(BBoxd param);
  void setProximity(double param);
};

#endif
