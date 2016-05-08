#include "geometry.h"

Geometryf::Geometryf() {
  // does nothing for now
}

Geometryf::~Geometryf() {
  // does nothing for now
}

BBoxf Geometryf::getBBox() {
  // to be extended
  return BBoxf();
}

bool Geometryf::containsPoint(Vec3f point) {
  // to be extended
  return false;
}

Geometryd::Geometryd() {
  // does nothing for now
}

Geometryd::~Geometryd() {
  // does nothing for now
}

BBoxd Geometryd::getBBox() {
  // to be extended
  return BBoxd();
}

bool Geometryd::containsPoint(Vec3d point) {
  // to be extended
  return false;
}
