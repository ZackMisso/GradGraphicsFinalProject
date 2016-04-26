#include "physicsEngine.h"

PhysicsEngine* PhysicsEngine::instance = 0x0;

PhysicsEngine::PhysicsEngine() {
  // to be implemented
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
