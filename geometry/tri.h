#ifndef __TRI_H__
#define __TRI_H__

#include "../dataStructures/array.h"
#include "vertex.h"
#include "../math/vec3.h"

class Trif {
private:
  int ind[3];
  Vec3f norm;
public:
  Trif(int* vals);
  void calculateNorm(Array<Vertexf*>* verts);
  // getter methods
  Vec3f getNorm();
};

class Trid {
private:
  int ind[3];
  Vec3d norm;
public:
  Trid(int* vals);
  void calculateNorm(Array<Vertexd*>* verts);
  // getter methods
  Vec3d getNorm();
};

#endif
