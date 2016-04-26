#include "bakePointMass.h"

BakePointMassf::BakePointMassf() {
  position = Vec3f();
  radius = 1.0f;
}

BakePointMassf::BakePointMassf(Vec3f pos,float r) {
  position = pos;
  radius = r;
}

void BakePointMassf::render() {
  // to be implemented
}

Vec3f BakePointMassf::getPosition() { return position; }
float BakePointMassf::getRadius() { return radius; }

void BakePointMassf::setPosition(Vec3f param) { position = param; }
void BakePointMassf::setRadius(float param) { radius = param; }

////////////////////////// DOUBLE VERSION ///////////////////////

BakePointMassd::BakePointMassd() {
  position = Vec3d();
  radius = 1.0;
}

BakePointMassd::BakePointMassd(Vec3d pos,double r) {
  position = pos;
  radius = r;
}

void BakePointMassd::render() {
  // to be implemented
}

Vec3d BakePointMassd::getPosition() { return position; }
double BakePointMassd::getRadius() { return radius; }

void BakePointMassd::setPosition(Vec3d param) { position = param; }
void BakePointMassd::setRadius(double param) { radius = param; }
