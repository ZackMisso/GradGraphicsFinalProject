#include "collisionTestView.h"
#include "../io/frameWriter.h"
#include "../io/simulationStateWriter.h"
#include "../geometry/rectPrism.h"
#include <iostream>

using namespace std;

void CollisionTestView::initialize() {
  one = new PhysicsObjectf();
  two = new PhysicsObjectf();
  Vec3f onePosition = Vec3f();
  Vec3f twoPosition = Vec3f();
  Vec3f oneDimension = Vec3f();
  Vec3f twoDimension = Vec3f();
  one->setGeometry(new RectPrismf(onePosition,oneDimension));
  two->setGeometry(new RectPrismf(twoPosition,twoDimension));
  one->setPosition(onePosition);
  two->setPosition(twoPosition);
  collisionSpring = 0x0;
}

void CollisionTestView::deInitialize() {
  delete one;
  delete two;
  if(collisionSpring)
    delete collisionSpring;
}

void CollisionTestView::keyboard(int key,int scancode,int action,int mods) {
  // to be implemented
}

void CollisionTestView::mouseClick(int button,int action,int mods) {
  // to be implemented
}

void CollisionTestView::display() {
  // to be implemented
}

void CollisionTestView::doPhysicsStep(float dt) {
  // to be implemented
}
