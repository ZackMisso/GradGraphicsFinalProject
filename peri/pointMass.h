#ifndef __POINTMASS_H__
#define __POINTMASS_H__

#include "../math/vec3.h"
#include "../dataStructures/array.h"
#include "../physics/spring.h"
#include "../physics/physicsObject.h"
#include "../geometry/voxel.h"

class PointMassf : public PhysicsObjectf {
private:
  Array<Springf*>* neighborhood;
  Voxelf* mesh; // needed for collision detection
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
  float getDistTo(PointMassf* other);
  void physicsUpdate();
  // getter methods
  Array<Springf*>* getNeighborhood();
  Voxelf* getMesh();
  Vec3f getOriginalPosition();
  float getRadius();
  float getVolume();
  int getID();
  // setter methods
  void setNeighborhood(Array<Springf*>* param);
  void setMesh(Voxelf* param);
  void setOriginalPosition(Vec3f param);
  void setRadius(float param);
  void setVolume(float param);
  void setID(int param);
};

class PointMassd : public PhysicsObjectd {
private:
  Array<Springd*>* neighborhood;
  Voxeld* mesh; // needed for collision detection
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
  double getDistTo(PointMassd* other);
  Vec3d accumulateForces();
  void physicsUpdate();
  // getter methods
  Array<Springd*>* getNeighborhood();
  Voxeld* getMesh();
  Vec3d getOriginalPosition();
  double getRadius();
  double getVolume();
  int getID();
  // setter methods
  void setNeighborhood(Array<Springd*>* param);
  void setMesh(Voxeld* param);
  void setOriginalPosition(Vec3d param);
  void setRadius(double param);
  void setVolume(double param);
  void setID(int param);
};

#endif
