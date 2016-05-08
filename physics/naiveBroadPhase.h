#ifndef __NAIVEBROADPHASE_H__
#define __NAIVEBROADPHASE_H__

#include "broadPhase.h"

class NaiveBroadPhase : public BroadPhase {
public:
  virtual Array<Manifoldf*>* detectCollisionsf(PhysicsWorld* world);
  virtual Array<Manifoldd*>* detectCollisionsd(PhysicsWorld* world);
};

#endif
