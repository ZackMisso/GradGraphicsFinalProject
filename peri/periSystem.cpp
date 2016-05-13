#include "periSystem.h"
#include "../geometry/voxelizer.h"
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include <iostream>

using namespace std;

PeriSystemf::PeriSystemf() {
  pointMasses = new Array<PointMassf*>();
  springs = new Array<Springf*>();
  pointMassR = 0.5f; // to be set outside of class
  pointMassM = 1.0f; // to be set outside of class
  pointMassH = 1.5f; // to be set outside of class
  springConstant = 0.0f;
  springDamp = 0.0f;
  springBreak = 0.0f;
}

PeriSystemf::PeriSystemf(TriMeshf* mesh) {
  pointMasses = new Array<PointMassf*>();
  springs = new Array<Springf*>();
  pointMassR = 0.5f; // to be set outside of class
  pointMassM = 1.0f; // to be set outside of class
  pointMassH = 1.5f; // to be set outside of class
  springConstant = 0.0f;
  springDamp = 0.0f;
  springBreak = 0.0f;
  Array<Voxelf*>* voxelMesh = Voxelizer::getInstance()->voxelizeTriMesh(mesh,pointMassR);
  convertVoxelsToPoints(voxelMesh);
}

PeriSystemf::PeriSystemf(Array<Voxelf*>* voxelMesh) {
  pointMasses = new Array<PointMassf*>();
  springs = new Array<Springf*>();
  pointMassR = 0.5f; // to be set outside of class
  pointMassM = 1.0f; // to be set outside of class
  pointMassH = 1.5f; // to be set outside of class
  springConstant = 0.0f;
  springDamp = 0.0f;
  springBreak = 0.0f;
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
            if(springs->get(k)->isEqual((void*)pm,(void*)two)) {
              //cout << "IT EXISTS" << endl;
              exists = true;
            }
          }
          if(!exists) {
            // add the connection
            Springf* connection = new Springf(pm->getID(),two->getID());
            connection->setOneRef((void*)pm);
            connection->setTwoRef((void*)two);
            connection->setRestLength(pm->getDistTo(two));
            connection->setSpringConstant(springConstant);
            connection->setBreakForce(springBreak);
            connection->setDampConstant(springDamp);
            connection->setPeriRadius(pointMassR);
            connection->setFirstRestPosition(pm->getPosition());
            connection->setSecondRestPosition(two->getPosition());
            connection->setIsPeriSpring(true);
            pm->getNeighborhood()->add(connection);
            two->getNeighborhood()->add(connection);
            springs->add(connection);
          }// else {
            //cout << "It Already Exists" << endl;
          //}
        }
      }
    }
  }
}

void PeriSystemf::performPhysicsStep(float dt) {
  for(int i=0;i<springs->getSize();i++) {
    springs->get(i)->setCurrentPositions();
    springs->get(i)->calculateCurrentRestPosition();
    springs->get(i)->calculateForce();
    springs->get(i)->calculatePotential();
    springs->get(i)->shouldDestroySpring();
  }
  for(int i=0;i<pointMasses->getSize();i++) {
    pointMasses->get(i)->performPhysicsStep(dt);
  }
  // to be implemented
}

void PeriSystemf::render(RenderMode rm,bool displaySprings) {
  glColor3f(1.0f,0.0f,0.0f);
  for(int i=0;i<pointMasses->getSize();i++) {
    pointMasses->get(i)->render(rm);
  }
  if(displaySprings) {
    for(int i=0;i<springs->getSize();i++) {
      glColor3f(0.0f,0.0f,1.0f);
      springs->get(i)->render(rm);
    }
  }
}

Array<PointMassf*>* PeriSystemf::getPointMasses() { return pointMasses; }
Array<Springf*>* PeriSystemf::getSprings() { return springs; }
float PeriSystemf::getPointMassR() { return pointMassR; }
float PeriSystemf::getPointMassM() { return pointMassM; }
float PeriSystemf::getPointMassH() { return pointMassH; }
float PeriSystemf::getSpringConstant() { return springConstant; }
float PeriSystemf::getSpringDamp() { return springDamp; }
float PeriSystemf::getSpringBreak() { return springBreak; }

void PeriSystemf::setPointMasses(Array<PointMassf*>* param) { pointMasses = param; }
void PeriSystemf::setSprings(Array<Springf*>* param) { springs = param; }
void PeriSystemf::setPointMassR(float param) { pointMassR = param; }
void PeriSystemf::setPointMassM(float param) { pointMassM = param; }
void PeriSystemf::setPointMassH(float param) { pointMassH = param; }
void PeriSystemf::setSpringConstant(float param) { springConstant = param; }
void PeriSystemf::setSpringDamp(float param) { springDamp = param; }
void PeriSystemf::setSpringBreak(float param) { springBreak = param; }

/////////////////////////// DOUBLE VERSION //////////////////////////////

PeriSystemd::PeriSystemd() {
  pointMasses = new Array<PointMassd*>();
  springs = new Array<Springd*>();
  pointMassR = 0.5; // to be set outside of class
  pointMassM = 1.0; // to be set outside of class
  pointMassH = 1.5; // to be set outside of class
  springConstant = 0.0;
  springDamp = 0.0;
  springBreak = 0.0;
}

PeriSystemd::PeriSystemd(TriMeshd* mesh) {
  pointMasses = new Array<PointMassd*>();
  springs = new Array<Springd*>();
  pointMassR = 0.5; // to be set outside of class
  pointMassM = 1.0; // to be set outside of class
  pointMassH = 1.5; // to be set outside of class
  springConstant = 0.0;
  springDamp = 0.0;
  springBreak = 0.0;
  Array<Voxeld*>* voxelMesh = Voxelizer::getInstance()->voxelizeTriMesh(mesh,pointMassR);
  convertVoxelsToPoints(voxelMesh);
}

PeriSystemd::PeriSystemd(Array<Voxeld*>* voxelMesh) {
  pointMasses = new Array<PointMassd*>();
  springs = new Array<Springd*>();
  pointMassR = 0.5; // to be set outside of class
  pointMassM = 1.0; // to be set outside of class
  pointMassH = 1.5; // to be set outside of class
  springConstant = 0.0;
  springDamp = 0.0;
  springBreak = 0.0;
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
            connection->setSpringConstant(springConstant);
            connection->setDampConstant(springDamp);
            connection->setBreakForce(springBreak);
            connection->setPeriRadius(pointMassR);
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

void PeriSystemd::performPhysicsStep(double dt) {
  // to be implemented
}

void PeriSystemd::render(RenderMode rm,bool displaySprings) {
  for(int i=0;i<pointMasses->getSize();i++) {
    pointMasses->get(i)->render(rm);
  }
  if(displaySprings) {
    for(int i=0;i<springs->getSize();i++) {
      springs->get(i)->render(rm);
    }
  }
}

Array<PointMassd*>* PeriSystemd::getPointMasses() { return pointMasses; }
Array<Springd*>* PeriSystemd::getSprings() { return springs; }
double PeriSystemd::getPointMassR() { return pointMassR; }
double PeriSystemd::getPointMassM() { return pointMassM; }
double PeriSystemd::getPointMassH() { return pointMassH; }
double PeriSystemd::getSpringConstant() { return springConstant; }
double PeriSystemd::getSpringDamp() { return springDamp; }
double PeriSystemd::getSpringBreak() { return springBreak; }

void PeriSystemd::setPointMasses(Array<PointMassd*>* param) { pointMasses = param; }
void PeriSystemd::setSprings(Array<Springd*>* param) { springs = param; }
void PeriSystemd::setPointMassR(double param) { pointMassR = param; }
void PeriSystemd::setPointMassM(double param) { pointMassM = param; }
void PeriSystemd::setPointMassH(double param) { pointMassH = param; }
void PeriSystemd::setSpringConstant(double param) { springConstant = param; }
void PeriSystemd::setSpringDamp(double param) { springDamp = param; }
void PeriSystemd::setSpringBreak(double param) { springBreak = param; }
