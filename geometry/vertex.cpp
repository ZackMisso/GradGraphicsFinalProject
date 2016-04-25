#include "vertex.h"

Vertexf::Vertexf(float *vals) {
  pos = Vec3f(vals[0],vals[1],vals[2]);
  norm = Vec3f();
}

Vertexf::Vertexf(Vec3f position) {
  pos = position;
  norm = Vec3f();
}

void Vertexf::addToNorm(Vec3f pos) {
  norm = norm + pos;
}

void Vertexf::normalizeNorm() {
  norm.normalize();
}

Vec3f Vertexf::getPos() { return pos; }
Vec3f Vertexf::getNorm() { return norm; }

void Vertexf::setPos(Vec3f param) { pos = param; }
void Vertexf::setNorm(Vec3f param) { norm = param; }

///////////////////////////// DOUBLE VERSION /////////////////////////////////

Vertexd::Vertexd(float *vals) {
  pos = Vec3d(vals[0],vals[1],vals[2]);
  norm = Vec3d();
}

Vertexd::Vertexd(Vec3d position) {
  pos = position;
  norm = Vec3d();
}

void Vertexd::addToNorm(Vec3d pos) {
  norm = norm + pos;
}

void Vertexd::normalizeNorm() {
  norm.normalize();
}

Vec3d Vertexd::getPos() { return pos; }
Vec3d Vertexd::getNorm() { return norm; }

void Vertexd::setPos(Vec3d param) { pos = param; }
void Vertexd::setNorm(Vec3d param) { norm = param; }
