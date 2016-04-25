#ifndef __TRIMESH_H__
#define __TRIMESH_H__

#include "../dataStructures/array.h"
#include "vertex.h"
#include "tri.h"

class TriMesh {
public:
  virtual void normalCalc();
  virtual void addVertex(float *vals);
  virtual void addTri(int* vals);
  virtual void render();
}; // used for IO

class TriMeshf : public TriMesh {
private:
  Array<Vertexf*>* verts;
  Array<Trif*>* tris;
public:
  TriMeshf();
  ~TriMeshf();
  virtual void normalCalc();
  virtual void addVertex(float *vals);
  virtual void addTri(int *vals);
  virtual void render();
  // getter methods
  Array<Vertexf*>* getVerts();
  Array<Trif*>* getTris();
  // setter methods
  void setVerts(Array<Vertexf*>* param);
  void setTris(Array<Trif*>* param);
};

class TriMeshd : public TriMesh {
private:
  Array<Vertexd*>* verts;
  Array<Trid*>* tris;
public:
  TriMeshd();
  ~TriMeshd();
  virtual void normalCalc();
  virtual void addVertex(float *vals);
  virtual void addTri(int *vals);
  virtual void render();
  // getter methods
  Array<Vertexd*>* getVerts();
  Array<Trid*>* getTris();
  // setter methods
  void setVerts(Array<Vertexd*>* param);
  void setTris(Array<Trid*>* param);
};

#endif
