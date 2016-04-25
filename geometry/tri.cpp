#include "tri.h"

Trif::Trif(int* vals) {
  ind[0] = vals[0];
  ind[1] = vals[1];
  ind[2] = vals[2];
  norm = Vec3f();
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
