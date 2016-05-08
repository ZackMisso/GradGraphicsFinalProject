#include "naiveNarrowPhase.h"
#include "../peri/periSystem.h"
#include "physicsObject.h"
#include "collisionMethods.h"

// naive narrow phase assumes collisions are only between peri-systems
// and physics objects

Array<Manifoldf*>* NaiveNarrowPhase::collisionChecksf(Array<Manifoldf*>* collisions) {
  // create the needed array
  Array<Manifoldf*>* manifolds = new Array<Manifoldf*>();
  for(int i=0;i<collisions->getSize();i++) {
    Manifoldf* collision = collisions->get(i);
    PeriSystemf* peri = (PeriSystemf*)collision->getOne()->getObject();
    PhysicsObjectf* object = (PhysicsObjectf*)collision->getTwo()->getObject();
    // check for a collision between a peri system and an object
    // naive approach offers no assumption that the objects are
    // close to each other, but for later iterations, we make that
    // assumption here (less efficient).
    // for now assumes the object is represented by only its bounding box
    // check all the point masses in the peri system against
    for(int j=0;j<peri->getPointMasses()->getSize();j++) {
      // get the point mass
      PointMassf* periPoint = peri->getPointMasses()->get(j);
      // get the bounding boxes
      BBoxf oneB = periPoint->getGeometry()->getBBox();
      BBoxf twoB = object->getGeometry()->getBBox();
      // create the return variables
      float pen = 0.0f;
      Vec3f norm = Vec3f(0.0f,0.0f,0.0f);
      // check if there was a collision
      if(CollisionMethods::getInstance()->bboxOnbbox(oneB,twoB,&pen,&norm)) {
        // create a new collision object for the point mass
        CollisionObject* newCol = new CollisionObject();
        newCol->setObject((void*)periPoint);
        newCol->setIsPhysicsObject(true);
        // create the manifold for the collision
        Manifoldf* manifold = new Manifoldf(newCol,collision->getTwo());
        manifold->setPenetrationDepth(pen);
        manifold->setCollisionNormal(norm);
        // ignore contact point for now
        manifold->setHasCollided(true);
        // add manifold to list of manifolds
        manifolds->add(manifold);
      }
    }
  }
  // clean up allocations
  while(collisions->getSize())
    delete collisions->removeLast();
  delete collisions;
  return collisionResolutionf(manifolds);
}

Array<Manifoldd*>* NaiveNarrowPhase::collisionChecksd(Array<Manifoldd*>* collisions) {
  // create the needed array
  Array<Manifoldd*>* manifolds = new Array<Manifoldd*>();
  for(int i=0;i<collisions->getSize();i++) {
    Manifoldd* collision = collisions->get(i);
    PeriSystemd* peri = (PeriSystemd*)collision->getOne()->getObject();
    PhysicsObjectd* object = (PhysicsObjectd*)collision->getTwo()->getObject();
    // check for a collision between a peri system and an object
    // naive approach offers no assumption that the objects are
    // close to each other, but for later iterations, we make that
    // assumption here (less efficient).
    // for now assumes the object is represented by only its bounding box
    // check all the point masses in the peri system against
    for(int j=0;j<peri->getPointMasses()->getSize();j++) {
      // get the point mass
      PointMassd* periPoint = peri->getPointMasses()->get(j);
      // get the bounding boxes
      BBoxd oneB = periPoint->getGeometry()->getBBox();
      BBoxd twoB = object->getGeometry()->getBBox();
      // create the return variables
      double pen = 0.0;
      Vec3d norm = Vec3d(0.0,0.0,0.0);
      // check if there was a collision
      if(CollisionMethods::getInstance()->bboxOnbbox(oneB,twoB,&pen,&norm)) {
        // create a new collision object for the point mass
        CollisionObject* newCol = new CollisionObject();
        newCol->setObject((void*)periPoint);
        newCol->setIsPhysicsObject(true);
        // create the manifold for the collision
        Manifoldd* manifold = new Manifoldd(newCol,collision->getTwo());
        manifold->setPenetrationDepth(pen);
        manifold->setCollisionNormal(norm);
        // ignore contact point for now
        manifold->setHasCollided(true);
        // add manifold to list of manifolds
        manifolds->add(manifold);
      }
    }
  }
  // clean up allocations
  while(collisions->getSize())
    delete collisions->removeLast();
  delete collisions;
  return collisionResolutiond(manifolds);
}

Array<Manifoldf*>* NaiveNarrowPhase::collisionResolutionf(Array<Manifoldf*>* collisions) {
  // to be implemented
  return collisions;
}

Array<Manifoldd*>* NaiveNarrowPhase::collisionResolutiond(Array<Manifoldd*>* collisions) {
  // to be implemented
  return collisions;
}
