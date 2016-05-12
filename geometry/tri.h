#ifndef __TRI_H__
#define __TRI_H__

#include "geometry.h"
#include "../dataStructures/array.h"
#include "vertex.h"
#include "../math/vec3.h"

class Trif : public Geometryf {
private:
  int ind[3];
  Vec3f norm;
public:
  Trif(int* vals);
  Trif(int one,int two,int three);
  // geometry methods
  virtual BBoxf getBBox();
  virtual bool containsPoint(Vec3f point);
  virtual void writeToFile(ofstream& file);
  virtual void readFromFile(ifstream& file);
  virtual void render(RenderMode rm);
  // methods
  void calculateNorm(Array<Vertexf*>* verts);
  // getter methods
  Vec3f getNorm();
};

class Trid : public Geometryd {
private:
  int ind[3];
  Vec3d norm;
public:
  Trid(int* vals);
  Trid(int one,int two,int three);
  // geometry methods
  virtual BBoxd getBBox();
  virtual bool containsPoint(Vec3d point);
  virtual void writeToFile(ofstream& file);
  virtual void readFromFile(ifstream& file);
  virtual void render(RenderMode rm);
  // methods
  void calculateNorm(Array<Vertexd*>* verts);
  // getter methods
  Vec3d getNorm();
};

#endif
