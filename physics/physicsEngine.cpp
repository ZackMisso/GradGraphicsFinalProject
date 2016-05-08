#include "physicsEngine.h"
#include "naiveBroadPhase.h"
#include "naiveNarrowPhase.h"

PhysicsEngine* PhysicsEngine::instance = 0x0;

PhysicsEngine::PhysicsEngine() {
  broadPhase = new NaiveBroadPhase();
  narrowPhase = new NaiveNarrowPhase();
  world = new PhysicsWorld();
}

PhysicsEngine::~PhysicsEngine() {
  // to be implemented
}

PhysicsEngine* PhysicsEngine::getInstance() {
  return instance;
}

void PhysicsEngine::initialize() {
  if(!instance)
    instance = new PhysicsEngine();
}

void PhysicsEngine::destroy() {
  if(instance)
    delete instance;
}
