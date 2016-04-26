#include "trimesh.h"

void TriMesh::normalCalc() { }
void TriMesh::addVertex(float *vals) { }
void TriMesh::addTri(int* vals) { }
void TriMesh::render() { }

TriMeshf::TriMeshf() {
  verts = new Array<Vertexf*>();
  tris = new Array<Trif*>();
}

TriMeshf::~TriMeshf() {
  while(verts->getSize())
    delete verts->removeLast();
  while(tris->getSize())
    delete tris->removeLast();
  delete verts;
  delete tris;
}

void TriMeshf::normalCalc() {
  for(int i=0;i<tris->getSize();i++)
		tris->get(i)->calculateNorm(verts);
	for(int i=0;i<verts->getSize();i++)
		verts->get(i)->normalizeNorm();
}

void TriMeshf::addVertex(float *vals) {
  verts->add(new Vertexf(vals));
}

void TriMeshf::addTri(int *vals) {
  tris->add(new Trif(vals));
}

void TriMeshf::render() {
  // to be implemented
}

Array<Vertexf*>* TriMeshf::getVerts() { return verts; }
Array<Trif*>* TriMeshf::getTris() { return tris; }

void TriMeshf::setVerts(Array<Vertexf*>* param) { verts = param; }
void TriMeshf::setTris(Array<Trif*>* param) { tris = param; }

/////////////////////////// DOUBLE VERSION ////////////////////////////////

TriMeshd::TriMeshd() {
  verts = new Array<Vertexd*>();
  tris = new Array<Trid*>();
}

TriMeshd::~TriMeshd() {
  while(verts->getSize())
    delete verts->removeLast();
  while(tris->getSize())
    delete tris->removeLast();
  delete verts;
  delete tris;
}

void TriMeshd::normalCalc() {
  for(int i=0;i<tris->getSize();i++)
		tris->get(i)->calculateNorm(verts);
	for(int i=0;i<verts->getSize();i++)
		verts->get(i)->normalizeNorm();
}

void TriMeshd::addVertex(float *vals) {
  verts->add(new Vertexd(vals));
}

void TriMeshd::addTri(int *vals) {
  tris->add(new Trid(vals));
}

void TriMeshd::render() {
  // to be implemented
}

Array<Vertexd*>* TriMeshd::getVerts() { return verts; }
Array<Trid*>* TriMeshd::getTris() { return tris; }

void TriMeshd::setVerts(Array<Vertexd*>* param) { verts = param; }
void TriMeshd::setTris(Array<Trid*>* param) { tris = param; }