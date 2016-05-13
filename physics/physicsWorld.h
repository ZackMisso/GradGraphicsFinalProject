#ifndef __PHYSICSWORLD_H__
#define __PHYSICSWORLD_H__

#include "../dataStructures/array.h"
#include "../peri/periSystem.h"
#include "physicsObject.h"
#include "physicsBody.h"
#include "dummyObject.h"

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
  Array<DummyObjectf*>* dummyObjectsF;
  Array<DummyObjectd*>* dummyObjectsD;
  Array<Springf*>* collisionSpringsF;
  Array<Springd*>* collisionSpringsD;
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
  void addDummyObjectToWorld(DummyObjectf* dummy);
  void addDummyObjectToWorld(DummyObjectd* dummy);
  void addCollisionSpringToWorld(Springf* spring);
  void addCollisionSpringToWorld(Springd* spring);
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
  Array<DummyObjectf*>* getDummyObjectsF();
  Array<DummyObjectd*>* getDummyObjectsD();
  Array<Springf*>* getCollisionSpringsF();
  Array<Springd*>* getCollisionSpringsD();
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
  void setDummyObjectsF(Array<DummyObjectf*>* param);
  void setDummyObjectsD(Array<DummyObjectd*>* param);
  void setCollisionSpringsF(Array<Springf*>* param);
  void setCollisionSpringsD(Array<Springd*>* param);
  void setDoublePercision(bool param);
  void setUsingSeparateLists(bool param);
};

#endif
