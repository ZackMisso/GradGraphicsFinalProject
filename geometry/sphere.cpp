#include "sphere.h"

Spheref::Spheref() {
  position = Vec3f();
  radius = 1.0f;
}

Spheref::Spheref(Vec3f p,float r) {
  position = p;
  radius = r;
}

Vec3f Spheref::getPosition() { return position; }
float Spheref::getRadius() { return radius; }

void Spheref::setPosition(Vec3f param) { position = param; }
void Spheref::setRadius(float param) { radius = param; }

//////////////////////// DOUBLE VERSION ////////////////////////

Sphered::Sphered() {
  position = Vec3d();
  radius = 1.0;
}

Sphered::Sphered(Vec3d p,double r) {
  position = p;
  radius = r;
}

Vec3d Sphered::getPosition() { return position; }
double Sphered::getRadius() { return radius; }

void Sphered::setPosition(Vec3d param) { position = param; }
void Sphered::setRadius(double param) { radius = param; }
