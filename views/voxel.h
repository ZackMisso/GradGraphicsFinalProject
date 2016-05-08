#ifndef __VOXEL_H__
#define __VOXEL_H__

#include "trimesh.h"
#include "../math/vec3.h"
#include "../render/renderInclude.h"
#include <iostream>

class Voxelf {
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
  // methods
  void display(RenderMode rm);
  void createMesh();
  void updateMesh();
  // getter methods
  Vec3f getPos();
  TriMeshf* getMesh();
  float getRadius();
  // setter methods
  void setPos(Vec3f param);
  void setMesh(TriMeshf* param);
  void setRadius(float param);
};

class Voxeld {
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
  // methods
  void display(RenderMode rm);
  void createMesh();
  void updateMesh();
  // getter methods
  Vec3d getPos();
  TriMeshd* getMesh();
  double getRadius();
  // setter methods
  void setPos(Vec3d param);
  void setMesh(TriMeshd* param);
  void setRadius(double param);
};

#endif
