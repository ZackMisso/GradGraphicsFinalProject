#ifndef __BAKEDSYSTEM_H__
#define __BAKEDSYSTEM_H__

#include "../dataStructures/array.h"
#include "bakedPhysicsObject.h"

class BakedSystem {
private:
  Array<BakedPhysicsObjectf*>* objectsf;
  Array<BakedPhysicsObjectd*>* objectsd;
public:
  BakedSystem();
  ~BakedSystem();
  // getter methods
  Array<BakedPhysicsObjectf*>* getObjectsF();
  Array<BakedPhysicsObjectd*>* getObjectsD();
  // setter methods
  void setObjectsF(Array<BakedPhysicsObjectf*>* param);
  void setObjectsD(Array<BakedPhysicsObjectd*>* param);
};

#endif
