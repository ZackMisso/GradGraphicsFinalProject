#ifndef __POINTMASS_H__
#define __POINTMASS_H__

#include "../math/vec3.h"
#include "../dataStructures/array.h"
#include "../physics/spring.h"
#include "../physics/physicsObject.h"

class PointMassf : PhysicsObjectf {
private:
  Array<Springf*>* neighborhood;
  Vec3f originalPosition;
  float radius;
  float volume; // maybe calculate this later instead
  int id;
  // methods
  //void calculateVolume();
public:
  PointMassf();
  ~PointMassf();
  // methods
  void calculateVolume();
  // physics methods
  virtual void performPhysicsStep(float dt);
  Vec3f accumulateForces();
  void physicsUpdate();
  // getter methods
  Array<Springf*>* getNeighborhood();
  Vec3f getOriginalPosition();
  float getRadius();
  float getVolume();
  int getID();
  // setter methods
  void setNeighborhood(Array<Springf*>* param);
  void setOriginalPosition(Vec3f param);
  void setRadius(float param);
  void setID(int param);
};

class PointMassd : PhysicsObjectd {
private:
  Array<Springd*>* neighborhood;
  Vec3d originalPosition;
  double radius;
  double volume; // maybe calculate this later instead
  int id;
  // methods
  //void calculateVolume();
public:
  PointMassd();
  ~PointMassd();
  // methods
  void calculateVolume();
  // physics methods
  virtual void performPhysicsStep(double dt);
  Vec3d accumulateForces();
  void physicsUpdate();
  // getter methods
  Array<Springd*>* getNeighborhood();
  Vec3d getOriginalPosition();
  double getRadius();
  double getVolume();
  int getID();
  // setter methods
  void setNeighborhood(Array<Springd*>* param);
  void setOriginalPosition(Vec3d param);
  void setRadius(double param);
  void setID(int param);
};

#endif
