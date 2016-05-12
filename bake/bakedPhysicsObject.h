#ifndef __BAKEDPHYSICSOBJECT_H__
#define __BAKEDPHYSICSOBJECT_H__

#include "../physics/physicsObject.h"

class BakedPhysicsObjectf : public PhysicsObjectf {
private:
  Array<Vec3f*>* positions;
public:
  BakedPhysicsObjectf();
  ~BakedPhysicsObjectf();
  // getter methods
  Array<Vec3f*>* getPositions();
  // setter methods
  void setPositions(Array<Vec3f*>* param);
};

class BakedPhysicsObjectd : public PhysicsObjectd {
private:
  Array<Vec3d*>* positions;
public:
  BakedPhysicsObjectd();
  ~BakedPhysicsObjectd();
  // getter methods
  Array<Vec3d*>* getPositions();
  // setter methods
  void setPositions(Array<Vec3d*>* param);
};

#endif
