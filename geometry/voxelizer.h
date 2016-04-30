#ifndef __VOXELIZER_H__
#define __VOXELIZER_H__

// a singleton that voxelizes meshes

#include "../dataStructures/array.h"
#include "voxel.h"
#include "bbox.h"
#include "trimesh.h"

class Voxelizer {
private:
  static Voxelizer* instance;
  Voxelizer();
public:
  ~Voxelizer();
  // singleton methods
  static Voxelizer* getInstance();
  static void initialize();
  static void destroy();
  // voxelizing methods
  Array<Voxelf*>* voxelizeCube(Vec3f pos,float side,float vRad);
  Array<Voxelf*>* voxelizeBBox(BBoxf bbox,float vRad);
  Array<Voxelf*>* voxelizeTriMesh(TriMeshf* mesh,float vRad);
  Array<Voxeld*>* voxelizeCube(Vec3d pos,double side,double vRad);
  Array<Voxeld*>* voxelizeBBox(BBoxd bbox,double vRad);
  Array<Voxeld*>* voxelizeTriMesh(TriMeshd* mesh,double vRad);
};

#endif
