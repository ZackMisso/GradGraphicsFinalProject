#ifndef __PHYSICSWORLD_H__
#define __PHYSICSWORLD_H__

#include "../dataStructures/array.h"
#include "../peri/periSystem.h"
#include "physicsObject.h"
#include "physicsBody.h"

class PhysicsWorld {
private:
  Array<PhysicsObjectf*>* allObjectsF;
  Array<PhysicsObjectd*>* allObjectsD;
  // different lists to increase speed
  Array<PhysicsBodyf*>* physicsBodiesF;
  Array<PhysicsBodyd*>* physicsBodiesD;
  Array<PhysicsObjectf*>* physicsObjectsF;
  Array<PhysicsObjectd*>* physicsObjectsD;
  Array<PeriSystemf*>* periSystemsF;
  Array<PeriSystemd*>* periSystemsD;
  bool doublePercision;
  bool usingSeparateLists;
public:
  PhysicsWorld();
  ~PhysicsWorld();
  // add object methods
  void addPhysicsBodyToWorld(PhysicsBodyf* body);
  void addPhysicsBodyToWorld(PhysicsBodyd* body);
  void addPhysicsObjectToWorld(PhysicsObjectf* object);
  void addPhysicsObjectToWorld(PhysicsObjectd* object);
  void addPeriSystemToWorld(PeriSystemf* peri);
  void addPeriSystemToWorld(PeriSystemd* peri);
  // methods
  void clearWorld();
  // getter methods
  Array<PhysicsObjectf*>* getAllObjectsF();
  Array<PhysicsObjectd*>* getAllObjectsD();
  Array<PhysicsBodyf*>* getPhysicsBodiesF();
  Array<PhysicsBodyd*>* getPhysicsBodiesD();
  Array<PhysicsObjectf*>* getPhysicsObjectsF();
  Array<PhysicsObjectd*>* getPhysicsObjectsD();
  Array<PeriSystemf*>* getPeriSystemsF();
  Array<PeriSystemd*>* getPeriSystemsD();
  bool getDoublePercision();
  bool getUsingSeparateLists();
  // setter methods
  void setAllObjectsF(Array<PhysicsObjectf*>* param);
  void setAllObjectsD(Array<PhysicsObjectd*>* param);
  void setPhysicsBodiesF(Array<PhysicsBodyf*>* param);
  void setPhysicsBodiesD(Array<PhysicsBodyd*>* param);
  void setPhysicsObjectsF(Array<PhysicsObjectf*>* param);
  void setPhysicsObjectsD(Array<PhysicsObjectd*>* param);
  void setPeriSystemsF(Array<PeriSystemf*>* param);
  void setPeriSystensD(Array<PeriSystemd*>* param);
  void setDoublePercision(bool param);
  void setUsingSeparateLists(bool param);
};

#endif
