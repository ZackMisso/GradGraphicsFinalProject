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
  delete broadPhase;
  delete narrowPhase;
  delete world;
}

void PhysicsEngine::simulatePhysicsStepf(float step) {
  // to be implemented
}

void PhysicsEngine::simulatePhysicsStepd(double step) {
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

BroadPhase* PhysicsEngine::getBroadPhase() { return broadPhase; }
NarrowPhase* PhysicsEngine::getNarrowPhase() { return narrowPhase; }
PhysicsWorld* PhysicsEngine::getWorld() { return world; }

void PhysicsEngine::setBroadPhase(BroadPhase* param) { broadPhase = param; }
void PhysicsEngine::setNarrowPhase(NarrowPhase* param) { narrowPhase = param; }
void PhysicsEngine::setWorld(PhysicsWorld* param) { world = param; }
