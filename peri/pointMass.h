#ifndef __POINTMASS_H__
#define __POINTMASS_H__

#include "../math/vec3.h"
#include "../dataStructures/array.h"
#include "../physics/spring.h"

class PointMassf {
private:
  Array<Springf*>* neighborhood;
  Array<Vec3f*>* externalForces;
  Vec3f originalPosition;
  Vec3f position;
  Vec3f velocity;
  float mass;
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
  Vec3f accumulateForces();
  void physicsUpdate();
  // getter methods
  Array<Springf*>* getNeighborhood();
  Array<Vec3f*>* getExternelForces();
  Vec3f getOriginalPosition();
  Vec3f getPosition();
  Vec3f getVelocity();
  float getMass();
  float getRadius();
  float getVolume();
  int getID();
  // setter methods
  void setNeighborhood(Array<Springf*>* param);
  void setExternelForces(Array<Vec3f*>* param);
  void setOriginalPosition(Vec3f param);
  void setPosition(Vec3f param);
  void setVelocity(Vec3f param);
  void setMass(float param);
  void setRadius(float param);
  void setID(int param);
};

class PointMassd {
private:
  Array<Springd*>* neighborhood;
  Array<Vec3d*>* externalForces;
  Vec3d originalPosition;
  Vec3d position;
  Vec3d velocity;
  double mass;
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
  Vec3d accumulateForces();
  void physicsUpdate();
  // getter methods
  Array<Springd*>* getNeighborhood();
  Array<Vec3d*>* getExternelForces();
  Vec3d getOriginalPosition();
  Vec3d getPosition();
  Vec3d getVelocity();
  double getMass();
  double getRadius();
  double getVolume();
  int getID();
  // setter methods
  void setNeighborhood(Array<Springd*>* param);
  void setExternelForces(Array<Vec3d*>* param);
  void setOriginalPosition(Vec3d param);
  void setPosition(Vec3d param);
  void setVelocity(Vec3d param);
  void setMass(double param);
  void setRadius(double param);
  void setID(int param);
};

#endif
