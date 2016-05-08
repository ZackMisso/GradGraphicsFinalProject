#include "naiveBroadPhase.h"
#include "../peri/periSystem.h"
#include "physicsWorld.h"
#include "physicsBody.h"

// naive approach does not do peri-peri or object-object collisions
// also does not do body collisions

Array<Manifoldf*>* NaiveBroadPhase::detectCollisionsf(PhysicsWorld* world) {
  // create/get the needed arrays
  Array<Manifoldf*>* manifolds = new Array<Manifoldf*>();
  Array<PeriSystemf*>* peris = world->getPeriSystemsF();
  Array<PhysicsObjectf*>* objects = world->getPhysicsObjectsF();
  // for every pari system, create a manifold for every physics object
  for(int i=0;i<peris->getSize();i++) {
    for(int j=0;j<objects->getSize();i++) {
      // create the collision objects
      CollisionObject* one = new CollisionObject();
      CollisionObject* two = new CollisionObject();
      one->setObject(peris->get(i));
      one->setIsPeriSystem(true);
      two->setObject(objects->get(j));
      two->setIsPhysicsObject(true);
      // add the manifold to the list of manifolds
      manifolds->add(new Manifoldf(one,two));
    }
  }
  return manifolds;
}

Array<Manifoldd*>* NaiveBroadPhase::detectCollisionsd(PhysicsWorld* world) {
  // create/get the needed arrays
  Array<Manifoldd*>* manifolds = new Array<Manifoldd*>();
  Array<PeriSystemd*>* peris = world->getPeriSystemsD();
  Array<PhysicsObjectd*>* objects = world->getPhysicsObjectsD();
  // for every pari system, create a manifold for every physics object
  for(int i=0;i<peris->getSize();i++) {
    for(int j=0;j<objects->getSize();i++) {
      // create the collision objects
      CollisionObject* one = new CollisionObject();
      CollisionObject* two = new CollisionObject();
      one->setObject(peris->get(i));
      one->setIsPeriSystem(true);
      two->setObject(objects->get(j));
      two->setIsPhysicsObject(true);
      // add the manifold to the list of manifolds
      manifolds->add(new Manifoldd(one,two));
    }
  }
  return manifolds;
}
