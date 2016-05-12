#include "tri.h"

Trif::Trif(int* vals) {
  ind[0] = vals[0];
  ind[1] = vals[1];
  ind[2] = vals[2];
  norm = Vec3f();
}

Trif::Trif(int one,int two,int three) {
  ind[0] = one;
  ind[1] = two;
  ind[2] = three;
  norm = Vec3f();
}

BBoxf Trif::getBBox() {
  // to be implemented
  return BBoxf();
}

bool Trif::containsPoint(Vec3f point) {
  // to be implemented
  return false;
}

void Trif::writeToFile(ofstream& file) {
  // to be implemented
}

void Trif::readFromFile(ifstream& file) {
  // to be implemented
}

void Trif::render(RenderMode rm) {
  // to be implemented
}

void Trif::updatePosition(Vec3f pos) {
  // does nothing
}

void Trif::calculateNorm(Array<Vertexf*>* verts) {
  Vec3f a = verts->get(ind[0])->getPos();
  Vec3f b = verts->get(ind[1])->getPos();
  Vec3f c = verts->get(ind[2])->getPos();
  Vec3f one = b-a;
  Vec3f two = c-a;
  norm = one^two;
  norm.normalize();
  verts->get(ind[0])->addToNorm(norm);
  verts->get(ind[1])->addToNorm(norm);
  verts->get(ind[2])->addToNorm(norm);
}

Vec3f Trif::getNorm() { return norm; }

/////////////////////////// DOUBLE VERSION /////////////////////////////

Trid::Trid(int* vals) {
  ind[0] = vals[0];
  ind[1] = vals[1];
  ind[2] = vals[2];
  norm = Vec3d();
}

Trid::Trid(int one,int two,int three) {
  ind[0] = one;
  ind[1] = two;
  ind[2] = three;
  norm = Vec3d();
}

BBoxd Trid::getBBox() {
  // to be implemented
  return BBoxd();
}

bool Trid::containsPoint(Vec3d point) {
  // to be implemented
  return false;
}

void Trid::writeToFile(ofstream& file) {
  // to be implemented
}

void Trid::readFromFile(ifstream& file) {
  // to be implemented
}

void Trid::render(RenderMode rm) {
  // to be implemented
}

void Trid::updatePosition(Vec3d pos) {
  // does nothing
}

void Trid::calculateNorm(Array<Vertexd*>* verts) {
  Vec3d a = verts->get(ind[0])->getPos();
  Vec3d b = verts->get(ind[1])->getPos();
  Vec3d c = verts->get(ind[2])->getPos();
  Vec3d one = b-a;
  Vec3d two = c-a;
  norm = one^two;
  norm.normalize();
  verts->get(ind[0])->addToNorm(norm);
  verts->get(ind[1])->addToNorm(norm);
  verts->get(ind[2])->addToNorm(norm);
}

Vec3d Trid::getNorm() { return norm; }
