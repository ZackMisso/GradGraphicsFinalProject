#include "voxel.h"
#include "vertex.h"
#include "tri.h"
#include "../render/modeler.h"

Voxelf::Voxelf() {
  pos = Vec3f();
  mesh = new TriMeshf();
  radius = 1.0f;
  createMesh();
}

Voxelf::Voxelf(Vec3f param) {
  pos = param;
  mesh = new TriMeshf();
  radius = 1.0f;
  createMesh();
}

Voxelf::Voxelf(Vec3f param,float r) {
  pos = param;
  mesh = new TriMeshf();
  radius = r;
  createMesh();
}

Voxelf::~Voxelf() {
  delete mesh;
}

void Voxelf::createMesh() {
  Array<Vertexf*>* verts = new Array<Vertexf*>();
  verts->add(new Vertexf(Vec3f(pos[0]+radius,pos[1]+radius,pos[2]+radius))); // 0
  verts->add(new Vertexf(Vec3f(pos[0]+radius,pos[1]-radius,pos[2]+radius))); // 1
  verts->add(new Vertexf(Vec3f(pos[0]-radius,pos[1]+radius,pos[2]+radius))); // 2
  verts->add(new Vertexf(Vec3f(pos[0]+radius,pos[1]+radius,pos[2]-radius))); // 3
  verts->add(new Vertexf(Vec3f(pos[0]-radius,pos[1]-radius,pos[2]+radius))); // 4
  verts->add(new Vertexf(Vec3f(pos[0]-radius,pos[1]+radius,pos[2]-radius))); // 5
  verts->add(new Vertexf(Vec3f(pos[0]+radius,pos[1]-radius,pos[2]-radius))); // 6
  verts->add(new Vertexf(Vec3f(pos[0]-radius,pos[1]-radius,pos[2]-radius))); // 7
  Array<Trif*>* tris = new Array<Trif*>();
  tris->add(new Trif(7,6,3));
  tris->add(new Trif(6,3,5));
  tris->add(new Trif(7,4,1));
  tris->add(new Trif(4,1,6));
  tris->add(new Trif(7,5,2));
  tris->add(new Trif(5,2,4));
  tris->add(new Trif(0,1,6));
  tris->add(new Trif(1,6,3));
  tris->add(new Trif(0,3,5));
  tris->add(new Trif(3,5,2));
  tris->add(new Trif(0,2,4));
  tris->add(new Trif(2,4,1));
  mesh->setTris(tris);
  mesh->setVerts(verts);
}


// inefficient... fix later
void Voxelf::updateMesh() {
  while(mesh->getVerts()->getSize())
    delete mesh->getVerts()->removeLast();
  while(mesh->getTris()->getSize())
    delete mesh->getTris()->removeLast();
  createMesh();
}

void Voxelf::display(RenderMode rm) {
  Modeler::getInstance()->drawCube(rm,pos,radius);
}

Vec3f Voxelf::getPos() { return pos; }
TriMeshf* Voxelf::getMesh() { return mesh; }
float Voxelf::getRadius() { return radius; }

void Voxelf::setPos(Vec3f param) { pos = param; }
void Voxelf::setMesh(TriMeshf* param) { mesh = param; }
void Voxelf::setRadius(float param) { radius = param; }

std::ostream & operator<<(std::ostream& os, const Voxelf& v) {
  Vec3f pos = v.getPos();
  return os << pos[0] << "," << pos[1] << "," << pos[2] << ":" << v.getRadius();
}

///////////////////////////////// DOUBLE VERSION ////////////////////////////////////

Voxeld::Voxeld() {
  pos = Vec3d();
  mesh = new TriMeshd();
  radius = 1.0;
  createMesh();
}

Voxeld::Voxeld(Vec3d param) {
  pos = param;
  mesh = new TriMeshd();
  radius = 1.0;
  createMesh();
}

Voxeld::Voxeld(Vec3d param,double r) {
  pos = param;
  mesh = new TriMeshd();
  radius = r;
  createMesh();
}

Voxeld::~Voxeld() {
  delete mesh;
}

void Voxeld::createMesh() {
  Array<Vertexd*>* verts = new Array<Vertexd*>();
  verts->add(new Vertexd(Vec3d(pos[0]+radius,pos[1]+radius,pos[2]+radius))); // 0
  verts->add(new Vertexd(Vec3d(pos[0]+radius,pos[1]-radius,pos[2]+radius))); // 1
  verts->add(new Vertexd(Vec3d(pos[0]-radius,pos[1]+radius,pos[2]+radius))); // 2
  verts->add(new Vertexd(Vec3d(pos[0]+radius,pos[1]+radius,pos[2]-radius))); // 3
  verts->add(new Vertexd(Vec3d(pos[0]-radius,pos[1]-radius,pos[2]+radius))); // 4
  verts->add(new Vertexd(Vec3d(pos[0]-radius,pos[1]+radius,pos[2]-radius))); // 5
  verts->add(new Vertexd(Vec3d(pos[0]+radius,pos[1]-radius,pos[2]-radius))); // 6
  verts->add(new Vertexd(Vec3d(pos[0]-radius,pos[1]-radius,pos[2]-radius))); // 7
  Array<Trid*>* tris = new Array<Trid*>();
  tris->add(new Trid(7,6,3));
  tris->add(new Trid(6,3,5));
  tris->add(new Trid(7,4,1));
  tris->add(new Trid(4,1,6));
  tris->add(new Trid(7,5,2));
  tris->add(new Trid(5,2,4));
  tris->add(new Trid(0,1,6));
  tris->add(new Trid(1,6,3));
  tris->add(new Trid(0,3,5));
  tris->add(new Trid(3,5,2));
  tris->add(new Trid(0,2,4));
  tris->add(new Trid(2,4,1));
  mesh->setTris(tris);
  mesh->setVerts(verts);
}


// inefficient... fix later
void Voxeld::updateMesh() {
  while(mesh->getVerts()->getSize())
    delete mesh->getVerts()->removeLast();
  while(mesh->getTris()->getSize())
    delete mesh->getTris()->removeLast();
  createMesh();
}

void Voxeld::display(RenderMode rm) {
  Modeler::getInstance()->drawCube(rm,pos,radius);
}

Vec3d Voxeld::getPos() { return pos; }
TriMeshd* Voxeld::getMesh() { return mesh; }
double Voxeld::getRadius() { return radius; }

void Voxeld::setPos(Vec3d param) { pos = param; }
void Voxeld::setMesh(TriMeshd* param) { mesh = param; }
void Voxeld::setRadius(double param) { radius = param; }

std::ostream & operator<<(std::ostream& os, const Voxeld& v) {
  Vec3d pos = v.getPos();
  return os << v[0] << "," << v[1] << "," << v[2]
}