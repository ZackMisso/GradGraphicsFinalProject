#ifndef __VOXEL_H__
#define __VOXEL_H__

#include "trimesh.h"
#include "../math/vec3.h"
#include "../render/renderInclude.h"

class Voxelf : public Geometryf {
private:
  Vec3f pos;
  TriMeshf* mesh;
  float radius;
public:
  Voxelf();
  Voxelf(Vec3f param);
  Voxelf(Vec3f param,float r);
  ~Voxelf();
  // geometry methods
  virtual BBoxf getBBox();
  virtual bool containsPoint(Vec3f point);
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

class Voxeld : public Geometryd {
private:
  Vec3d pos;
  TriMeshd* mesh;
  double radius;
public:
  Voxeld();
  Voxeld(Vec3d param);
  Voxeld(Vec3d param,double r);
  ~Voxeld();
  // geometry methods
  virtual BBoxd getBBox();
  virtual bool containsPoint(Vec3d point);
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
