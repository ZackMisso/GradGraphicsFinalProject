#ifndef __TRIMESH_H__
#define __TRIMESH_H__

#include "geometry.h"
#include "../dataStructures/array.h"
#include "vertex.h"
#include "tri.h"

//class TriMesh {
//public:
//  virtual void normalCalc();
//  virtual void addVertex(float *vals);
//  virtual void addTri(int* vals);
//  virtual void render();
//}; // used for IO

class TriMeshf : public Geometryf {
private:
  Array<Vertexf*>* verts;
  Array<Trif*>* tris;
public:
  TriMeshf();
  ~TriMeshf();
  // geometry methods
  virtual BBoxf getBBox();
  virtual bool containsPoint(Vec3f point);
  virtual void writeToFile(ofstream& file);
  virtual void readFromFile(ifstream& file);
  virtual void render(RenderMode rm);
  // methods
  void normalCalc();
  void addVertex(float *vals);
  void addTri(int *vals);
  // getter methods
  Array<Vertexf*>* getVerts();
  Array<Trif*>* getTris();
  // setter methods
  void setVerts(Array<Vertexf*>* param);
  void setTris(Array<Trif*>* param);
};

class TriMeshd : public Geometryd {
private:
  Array<Vertexd*>* verts;
  Array<Trid*>* tris;
public:
  TriMeshd();
  ~TriMeshd();
  // geometry methods
  virtual BBoxd getBBox();
  virtual bool containsPoint(Vec3d point);
  virtual void writeToFile(ofstream& file);
  virtual void readFromFile(ifstream& file);
  virtual void render(RenderMode rm);
  // methods
  void normalCalc();
  void addVertex(float *vals);
  void addTri(int *vals);
  // getter methods
  Array<Vertexd*>* getVerts();
  Array<Trid*>* getTris();
  // setter methods
  void setVerts(Array<Vertexd*>* param);
  void setTris(Array<Trid*>* param);
};

#endif
