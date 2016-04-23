#ifndef __POINTMASS_H__
#define __POINTMASS_H__

#include "../math/vec3.h"
#include "../dataStructures/array.h"

class PointMassf {
private:
  Array<PointMassf*>* neighborhood;
  Array<Vec3f*>* externalForces;
  Vec3f originalPosition;
  Vec3f position;
  Vec3f velocity;
  float mass;
  float radius;
  float volume; // maybe calculate this later instead
  // methods
  //void calculateVolume();
public:
  PointMassf();
  ~PointMassf();
  // methods
  void calculateVolume();
  // physics methods
  Vec3f accumulateForces();
  void physicsUpdate();
  // getter methods
  Array<PointMassf*>* getNeighborhood();
  Array<Vec3f*>* getExternelForces();
  Vec3f getOriginalPosition();
  Vec3f getPosition();
  Vec3f getVelocity();
  float getMass();
  float getRadius();
  float getVolume();
  // setter methods
  void setNeighborhood(Array<PointMassf*>* param);
  void setExternelForces(Array<Vec3f*>* param);
  void setOriginalPosition(Vec3f param);
  void setPosition(Vec3f param);
  void setVelocity(Vec3f param);
  void setMass(float param);
  void setRadius(float param);
};

class PointMassd {
private:
  Array<PointMassd*>* neighborhood;
  Array<Vec3d*>* externalForces;
  Vec3d originalPosition;
  Vec3d position;
  Vec3d velocity;
  double mass;
  double radius;
  double volume; // maybe calculate this later instead
  // methods
  //void calculateVolume();
public:
  PointMassd();
  ~PointMassd();
  // methods
  void calculateVolume();
  // physics methods
  Vec3d accumulateForces();
  void physicsUpdate();
  // getter methods
  Array<PointMassd*>* getNeighborhood();
  Array<Vec3d*>* getExternelForces();
  Vec3d getOriginalPosition();
  Vec3d getPosition();
  Vec3d getVelocity();
  double getMass();
  double getRadius();
  double getVolume();
  // setter methods
  void setNeighborhood(Array<PointMassd*>* param);
  void setExternelForces(Array<Vec3d*>* param);
  void setOriginalPosition(Vec3d param);
  void setPosition(Vec3d param);
  void setVelocity(Vec3d param);
  void setMass(double param);
  void setRadius(double param);
};

#endif
