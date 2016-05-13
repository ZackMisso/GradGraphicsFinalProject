#include "voxelizer.h"

#include <iostream>
using namespace std;

Voxelizer* Voxelizer::instance = 0x0;

Voxelizer::Voxelizer() {
  // does nothing for now
}

Voxelizer::~Voxelizer() {
  // does nothing for now
}

Voxelizer* Voxelizer::getInstance() {
  return instance;
}

void Voxelizer::initialize() {
  if(!instance)
    instance = new Voxelizer();
}

void Voxelizer::destroy() {
  if(instance)
    delete instance;
}

Array<Voxelf*>* Voxelizer::voxelizeCube(Vec3f pos,float side,float vRad) {
  BBoxf box = BBoxf(Vec3f(pos[0]-side/2.0f,pos[1]-side/2.0f,pos[2]-side/2.0f),Vec3f(side,side,side));
  return voxelizeBBox(box,vRad);
}

Array<Voxelf*>* Voxelizer::voxelizeBBox(BBoxf bbox,float vRad) {
  Array<Voxelf*>* voxelMesh = new Array<Voxelf*>();
  Vec3f pos = bbox.getPosition();
  Vec3f dim = bbox.getDimension();
  float vDia = 2*vRad;
  for(float x=pos[0]+vRad; x < pos[0]+dim[0]; x+=vDia)
    for(float y=pos[1]+vRad; y < pos[1]+dim[1]; y+=vDia)
      for(float z=pos[2]+vRad; z < pos[2]+dim[2]; z+=vDia)
        voxelMesh->add(new Voxelf(Vec3f(x,y,z),vRad));
  return voxelMesh;
}

Array<Voxelf*>* Voxelizer::voxelizeSphere(Spheref sphere,float vRad) {
  // to be implemented
  return 0x0;
}

Array<Voxelf*>* Voxelizer::voxelizeCylinder(Cylinderf cyl,float vRad) {
  // to be implemented
  return 0x0;
}

Array<Voxelf*>* Voxelizer::voxelizeTriMesh(TriMeshf* mesh,float vRad) {
  // to be implemented
  return 0x0;
}

Array<Voxeld*>* Voxelizer::voxelizeCube(Vec3d pos,double side,double vRad) {
  BBoxd box = BBoxd(Vec3d(pos[0]-side/2.0f,pos[1]-side/2.0f,pos[2]-side/2.0f),Vec3d(side,side,side));
  return voxelizeBBox(box,vRad);
}

Array<Voxeld*>* Voxelizer::voxelizeBBox(BBoxd bbox,double vRad) {
  Array<Voxeld*>* voxelMesh = new Array<Voxeld*>();
  Vec3d pos = bbox.getPosition();
  Vec3d dim = bbox.getDimension();
  double vDia = 2*vRad;
  for(double x=pos[0]+vRad; x < pos[0]+dim[0]; x+=vDia)
    for(double y=pos[1]+vRad; y < pos[1]+dim[1]; y+=vDia)
      for(double z=pos[2]+vRad; z < pos[2]+dim[2]; z+=vDia)
        voxelMesh->add(new Voxeld(Vec3d(x,y,z),vRad));
  return voxelMesh;
}

Array<Voxeld*>* Voxelizer::voxelizeSphere(Sphered sphere,double vRad) {
  // to be implemented
  return 0x0;
}

Array<Voxeld*>* Voxelizer::voxelizeCylinder(Cylinderd cyl,double vRad) {
  // to be implemented
  return 0x0;
}

Array<Voxeld*>* Voxelizer::voxelizeTriMesh(TriMeshd* mesh,double vRad) {
  // to be implemented
  return 0x0;
}
