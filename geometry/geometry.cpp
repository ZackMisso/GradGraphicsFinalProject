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

void Geometryf::writeToFile(ofstream& file) {
  // to be extended
}

void Geometryf::readFromFile(ifstream& file) {
  // to be extended
}

void Geometryf::render(RenderMode rm) {
  // to be extended
}

///////////////////// DOUBLE VERSION ///////////////////

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

void Geometryd::writeToFile(ofstream& file) {
  // to be extended
}

void Geometryd::readFromFile(ifstream& file) {
  // to be extended
}

void Geometryd::render(RenderMode rm) {
  // to be extended
}
