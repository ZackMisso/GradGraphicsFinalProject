#ifndef __VOXEL_H__
#define __VOXEL_H__

#include "trimesh.h"
#include "../math/vec3.h"
#include "../render/renderInclude.h"
#include <iostream>

class Voxelf : public Geometryf {
private:
  Vec3f pos;
  TriMeshf* mesh;
  float radius;
  friend std::ostream& operator<<(std::ostream& os, const Voxelf& v);
public:
  Voxelf();
  Voxelf(Vec3f param);
  Voxelf(Vec3f param,float r);
  ~Voxelf();
  // geometry methods
  virtual BBoxf getBBox();
  virtual bool containsPoint(Vec3f point);
  virtual void writeToFile(ofstream& file);
  virtual void readFromFile(istream& file);
  virtual void render(RenderMode rm);
  // methods
  void createMesh();
  void updateMesh();
  // getter methods
  Vec3f getPos() const;
  TriMeshf* getMesh() const;
  float getRadius() const;
  // setter methods
  void setPos(Vec3f param);
  void setMesh(TriMeshf* param);
  void setRadius(float param);
};

class Voxeld : public Geometryd {
private:
  Vec3d pos;
  TriMeshd* mesh;
  double radius;
  friend std::ostream& operator<<(std::ostream& os, const Voxeld& v);
public:
  Voxeld();
  Voxeld(Vec3d param);
  Voxeld(Vec3d param,double r);
  ~Voxeld();
  // geometry methods
  virtual BBoxd getBBox();
  virtual bool containsPoint(Vec3d point);
  virtual void writeToFile(ofstream& file);
  virtual void readFromFile(istream& file);
  virtual void render(RenderMode rm);
  // methods
  void createMesh();
  void updateMesh();
  // getter methods
  Vec3d getPos() const;
  TriMeshd* getMesh() const;
  double getRadius() const;
  // setter methods
  void setPos(Vec3d param);
  void setMesh(TriMeshd* param);
  void setRadius(double param);
};

#endif
