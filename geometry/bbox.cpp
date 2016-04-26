#include "bbox.h"

BBoxf::BBoxf() {
  position = Vec3f();
  dimension = Vec3f();
}

BBoxf::BBoxf(Vec3f p,Vec3f d) {
  position = p;
  dimension = d;
}

float BBoxf::longestDim() {
  float ld = dimension[0];
  if(dimension[1] > ld)
    ld = dimension[1];
  if(dimension[2] > ld)
    ld = dimension[2];
  return ld;
}

float BBoxf::volume() {
  return dimension[0]*dimension[1]*dimension[2];
}

Vec3f BBoxf::getPosition() { return position; }
Vec3f BBoxf::getDimension() { return dimension; }

void BBoxf::setPosition(Vec3f param) { position = param; }
void BBoxf::setDimension(Vec3f param) { dimension = param; }

///////////////////// DOUBLE VERSION //////////////////////////

BBoxd::BBoxd() {
  position = Vec3d();
  dimension = Vec3d();
}

BBoxd::BBoxd(Vec3d p,Vec3d d) {
  position = p;
  dimension = d;
}

double BBoxd::longestDim() {
  double ld = dimension[0];
  if(dimension[1] > ld)
    ld = dimension[1];
  if(dimension[2] > ld)
    ld = dimension[2];
  return ld;
}

double BBoxd::volume() {
  return dimension[0]*dimension[1]*dimension[2];
}

Vec3d BBoxd::getPosition() { return position; }
Vec3d BBoxd::getDimension() { return dimension; }

void BBoxd::setPosition(Vec3d param) { position = param; }
void BBoxd::setDimension(Vec3d param) { dimension = param; }
