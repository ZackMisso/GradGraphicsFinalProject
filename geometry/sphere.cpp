#include "sphere.h"

Spheref::Spheref() {
  position = Vec3f();
  radius = 1.0f;
}

Spheref::Spheref(Vec3f p,float r) {
  position = p;
  radius = r;
}

BBoxf Spheref::getBBox() {
  // to be implemented
  return BBoxf();
}

bool Spheref::containsPoint(Vec3f point) {
  Vec3f dist = position-point;
  return dist.mag() <= radius;
}

void Spheref::writeToFile(ofstream& file) {
  // to be implemented
}

void Spheref::readFromFile(ifstream& file) {
  // to be implemented
}

void Spheref::render(RenderMode rm) {
  // to be implemented
}

void Spheref::updatePosition(Vec3f pos) {
  position = pos;
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

BBoxd Sphered::getBBox() {
  // to be implemented
  return BBoxd();
}

bool Sphered::containsPoint(Vec3d point) {
  Vec3d dist = position-point;
  return dist.mag() <= radius;
}

void Sphered::writeToFile(ofstream& file) {
  // to be implemented
}

void Sphered::readFromFile(ifstream& file) {
  // to be implemented
}

void Sphered::render(RenderMode rm) {
  // to be implemented
}

void Sphered::updatePosition(Vec3d pos) {
  position = pos;
}

Vec3d Sphered::getPosition() { return position; }
double Sphered::getRadius() { return radius; }

void Sphered::setPosition(Vec3d param) { position = param; }
void Sphered::setRadius(double param) { radius = param; }
