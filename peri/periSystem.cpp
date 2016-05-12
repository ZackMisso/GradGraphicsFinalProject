#include "periSystem.h"
#include "../geometry/voxelizer.h"

PeriSystemf::PeriSystemf() {
  pointMasses = new Array<PointMassf*>();
  springs = new Array<Springf*>();
  pointMassR = 0.5f; // to be set outside of class
  pointMassM = 1.0f; // to be set outside of class
  pointMassH = 1.5f; // to be set outside of class
}

PeriSystemf::PeriSystemf(TriMeshf* mesh) {
  pointMasses = new Array<PointMassf*>();
  springs = new Array<Springf*>();
  pointMassR = 0.5f; // to be set outside of class
  pointMassM = 1.0f; // to be set outside of class
  pointMassH = 1.5f; // to be set outside of class
  Array<Voxelf*>* voxelMesh = Voxelizer::getInstance()->voxelizeTriMesh(mesh,pointMassR);
  convertVoxelsToPoints(voxelMesh);
}

PeriSystemf::PeriSystemf(Array<Voxelf*>* voxelMesh) {
  pointMasses = new Array<PointMassf*>();
  springs = new Array<Springf*>();
  pointMassR = 0.5f; // to be set outside of class
  pointMassM = 1.0f; // to be set outside of class
  pointMassH = 1.5f; // to be set outside of class
  convertVoxelsToPoints(voxelMesh);
}

PeriSystemf::~PeriSystemf() {
  while(pointMasses->getSize())
    delete pointMasses->removeLast();
  while(springs->getSize())
    delete springs->removeLast();
  delete pointMasses;
  delete springs;
}

void PeriSystemf::preprocess() {
  // to be implemented
}

void PeriSystemf::convertVoxelsToPoints(Array<Voxelf*>* voxels) {
  // create point masses
  for(int i=0;i<voxels->getSize();i++) {
    PointMassf* pm = new PointMassf();
    pm->setPosition(voxels->get(i)->getPos());
    pm->setRadius(pointMassR);
    pm->setOriginalPosition(pm->getPosition());
    pm->setVolume(8.0f*pointMassR*pointMassR*pointMassR);
    pm->setMass(pointMassM);
    pm->setGeometry(voxels->get(i));
    pointMasses->add(pm);
  }
  // create springs - Very Expensive but only done at the beginning
  float sqrH = pointMassH*pointMassH;
  for(int i=0;i<pointMasses->getSize();i++) {
    PointMassf* pm = pointMasses->get(i);
    for(int j=0;j<pointMasses->getSize();j++) {
      if(i!=j) {
        PointMassf* two = pointMasses->get(j);
        // check if the two pointmasses are in the same neighborhood
        if(pm->getSqrDistTo(two) <= sqrH) {
          bool exists = false;
          // make sure their connection doesnt already exist
          for(int k=0;k<springs->getSize();k++) {
            if(springs->get(k)->isEqual(pm->getID(),two->getID()))
              exists = true;
          }
          if(!exists) {
            // add the connection
            Springf* connection = new Springf(pm->getID(),two->getID());
            connection->setOneRef((void*)pm);
            connection->setTwoRef((void*)two);
            connection->setRestLength(pm->getDistTo(two));
            connection->setFirstRestPosition(pm->getPosition());
            connection->setSecondRestPosition(two->getPosition());
            connection->setIsPeriSpring(true);
            pm->getNeighborhood()->add(connection);
            two->getNeighborhood()->add(connection);
            springs->add(connection);
          }
        }
      }
    }
  }
}

void PeriSystemf::update() {
  // to be implemented
}

Array<PointMassf*>* PeriSystemf::getPointMasses() { return pointMasses; }
Array<Springf*>* PeriSystemf::getSprings() { return springs; }
float PeriSystemf::getPointMassR() { return pointMassR; }
float PeriSystemf::getPointMassM() { return pointMassM; }
float PeriSystemf::getPointMassH() { return pointMassH; }

void PeriSystemf::setPointMasses(Array<PointMassf*>* param) { pointMasses = param; }
void PeriSystemf::setSprings(Array<Springf*>* param) { springs = param; }
void PeriSystemf::setPointMassR(float param) { pointMassR = param; }
void PeriSystemf::setPointMassM(float param) { pointMassM = param; }
void PeriSystemf::setPointMassH(float param) { pointMassH = param; }

/////////////////////////// DOUBLE VERSION //////////////////////////////

PeriSystemd::PeriSystemd() {
  pointMasses = new Array<PointMassd*>();
  springs = new Array<Springd*>();
  pointMassR = 0.5; // to be set outside of class
  pointMassM = 1.0; // to be set outside of class
  pointMassH = 1.5; // to be set outside of class
}

PeriSystemd::PeriSystemd(TriMeshd* mesh) {
  pointMasses = new Array<PointMassd*>();
  springs = new Array<Springd*>();
  pointMassR = 0.5; // to be set outside of class
  pointMassM = 1.0; // to be set outside of class
  pointMassH = 1.5; // to be set outside of class
  Array<Voxeld*>* voxelMesh = Voxelizer::getInstance()->voxelizeTriMesh(mesh,pointMassR);
  convertVoxelsToPoints(voxelMesh);
}

PeriSystemd::PeriSystemd(Array<Voxeld*>* voxelMesh) {
  pointMasses = new Array<PointMassd*>();
  springs = new Array<Springd*>();
  pointMassR = 0.5; // to be set outside of class
  pointMassM = 1.0; // to be set outside of class
  pointMassH = 1.5; // to be set outside of class
  convertVoxelsToPoints(voxelMesh);
}

PeriSystemd::~PeriSystemd() {
  while(pointMasses->getSize())
    delete pointMasses->removeLast();
  while(springs->getSize())
    delete springs->removeLast();
  delete pointMasses;
  delete springs;
}

void PeriSystemd::preprocess() {
  // to be implemented
}

void PeriSystemd::convertVoxelsToPoints(Array<Voxeld*>* voxels) {
  // create point masses
  for(int i=0;i<voxels->getSize();i++) {
    PointMassd* pm = new PointMassd();
    pm->setPosition(voxels->get(i)->getPos());
    pm->setRadius(pointMassR);
    pm->setOriginalPosition(pm->getPosition());
    pm->setVolume(8.0*pointMassR*pointMassR*pointMassR);
    pm->setMass(pointMassM);
    pm->setGeometry(voxels->get(i));
    pointMasses->add(pm);
  }
  // create springs - Very Expensive but only done at the beginning
  double sqrH = pointMassH*pointMassH;
  for(int i=0;i<pointMasses->getSize();i++) {
    PointMassd* pm = pointMasses->get(i);
    for(int j=0;j<pointMasses->getSize();j++) {
      if(i!=j) {
        PointMassd* two = pointMasses->get(j);
        // check if the two pointmasses are in the same neighborhood
        if(pm->getSqrDistTo(two) <= sqrH) {
          bool exists = false;
          // make sure their connection doesnt already exist
          for(int k=0;k<springs->getSize();k++) {
            if(springs->get(k)->isEqual(pm->getID(),two->getID()))
              exists = true;
          }
          if(!exists) {
            // add the connection
            Springd* connection = new Springd(pm->getID(),two->getID());
            connection->setOneRef((void*)pm);
            connection->setTwoRef((void*)two);
            connection->setRestLength(pm->getDistTo(two));
            connection->setFirstRestPosition(pm->getPosition());
            connection->setSecondRestPosition(two->getPosition());
            connection->setIsPeriSpring(true);
            pm->getNeighborhood()->add(connection);
            two->getNeighborhood()->add(connection);
            springs->add(connection);
          }
        }
      }
    }
  }
}

void PeriSystemd::update() {
  // to be implemented
}

Array<PointMassd*>* PeriSystemd::getPointMasses() { return pointMasses; }
Array<Springd*>* PeriSystemd::getSprings() { return springs; }
double PeriSystemd::getPointMassR() { return pointMassR; }
double PeriSystemd::getPointMassM() { return pointMassM; }
double PeriSystemd::getPointMassH() { return pointMassH; }

void PeriSystemd::setPointMasses(Array<PointMassd*>* param) { pointMasses = param; }
void PeriSystemd::setSprings(Array<Springd*>* param) { springs = param; }
void PeriSystemd::setPointMassR(double param) { pointMassR = param; }
void PeriSystemd::setPointMassM(double param) { pointMassM = param; }
void PeriSystemd::setPointMassH(double param) { pointMassH = param; }
