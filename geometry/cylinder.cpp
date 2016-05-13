#include "cylinder.h"

Cylinderf::Cylinderf() {
  position = Vec3f();
  radius = 1.0f;
  height = 1.0f;
}

Cylinderf::Cylinderf(Vec3f pos,float r,float h) {
  position = pos;
  radius = r;
  height = h;
}


BBoxf Cylinderf::getBBox() {
  // to be implemented
  return BBoxf();
}

bool Cylinderf::containsPoint(Vec3f point) {
  // to be implemented
  return false;
}

void Cylinderf::writeToFile(ofstream& file) {
  file << CYLINDER << " " << getRadius() << " " << getHeight();
}

void Cylinderf::readFromFile(ifstream& file) {
  float r, h;
  file >> r >> h;
  setRadius(r);
  setHeight(h);
}

void Cylinderf::render(RenderMode rm) {
  // to be implemented
}

void Cylinderf::updatePosition(Vec3f pos) {
  position = pos;
}

Vec3f Cylinderf::getPosition() { return position; }
float Cylinderf::getRadius() { return radius; }
float Cylinderf::getHeight() { return height; }
// setter methods
void Cylinderf::setPosition(Vec3f param) { position = param; }
void Cylinderf::setRadius(float param) { radius = param; }
void Cylinderf::setHeight(float param) { height = param; }

/////////////////// DOUBLE VERSION ///////////////////

Cylinderd::Cylinderd() {
  position = Vec3d();
  radius = 1.0;
  height = 1.0;
}

Cylinderd::Cylinderd(Vec3d pos,double r,double h) {
  pos = position;
  radius = r;
  height = h;
}


BBoxd Cylinderd::getBBox() {
  // to be implemented
  return BBoxd();
}

bool Cylinderd::containsPoint(Vec3d point) {
  // to be implemented
  return false;
}

void Cylinderd::writeToFile(ofstream& file) {
  file << CYLINDER << " " << getRadius() << " " << getHeight();
}

void Cylinderd::readFromFile(ifstream& file) {
  double r, h;
  file >> r >> h;
  setRadius(r);
  setHeight(h);
}

void Cylinderd::render(RenderMode rm) {
  // to be implemented
}

void Cylinderd::updatePosition(Vec3d pos) {
  position = pos;
}

Vec3d Cylinderd::getPosition() { return position; }
double Cylinderd::getRadius() { return radius; }
double Cylinderd::getHeight() { return height; }
// setter methods
void Cylinderd::setPosition(Vec3d param) { position = param; }
void Cylinderd::setRadius(double param) { radius = param; }
void Cylinderd::setHeight(double param) { height = param; }
