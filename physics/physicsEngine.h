#ifndef __PHYSICSENGINE_H__
#define __PHYSICSENGINE_H__

// A singleton that oversees all physics interactions
// will need this for the final simulation

#include "broadPhase.h"
#include "narrowPhase.h"
#include "physicsWorld.h"

class PhysicsEngine {
private:
  static PhysicsEngine* instance;
  BroadPhase* broadPhase;
  NarrowPhase* narrowPhase;
  PhysicsWorld* world;
  PhysicsEngine();
public:
  ~PhysicsEngine();
  // singleton methods
  static PhysicsEngine* getInstance();
  static void initialize();
  static void destroy();
  // getter methods
  BroadPhase* getBroadPhase();
  NarrowPhase* getNarrowPhase();
  // setter methods
  void setBroadPhase(BroadPhase* param);
  void setNarrowPhase(NarrowPhase* param);
};

#endif
