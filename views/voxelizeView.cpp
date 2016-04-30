#include "voxelizeView.h"
#include "../render/renderInclude.h"
#include "../render/modeler.h"
#include "../math/vec3.h"
#include "../geometry/voxelizer.h"

#include <iostream>
using namespace std;

void VoxelizeView::initialize() {
  //voxelMesh = new Array<Voxelf*>();
  voxelRad = 0.5f;
  displayOriginalShape = true;
  displayVoxels = false;
  animateDisplay = false;
  originalShape = BBoxf(Vec3f(0.0f,0.0f,0.0f),Vec3f(2.0f,2.0f,2.0f));
  dt = 0.0f;
  // do voxelizing
  voxelMesh = Voxelizer::getInstance()->voxelizeCube(Vec3f(0.0f,0.0f,0.0f),2.0f,voxelRad);
  cout << "VoxelMesh Size: " << voxelMesh->getSize() << endl;
}

void VoxelizeView::deInitialize() {
  while(voxelMesh->getSize())
    delete voxelMesh->removeLast();
  delete voxelMesh;
}

void VoxelizeView::keyboard(int key,int scancode,int action,int mods) {
  if(key == GLFW_KEY_A && action == GLFW_PRESS) {
    animateDisplay = !animateDisplay;
    if(!animateDisplay) {
      dt = 0.0f;
    }
  }
  if(key == GLFW_KEY_O && action == GLFW_PRESS) {
    displayOriginalShape = !displayOriginalShape;
  }
  if(key == GLFW_KEY_V && action == GLFW_PRESS) {
    displayVoxels = !displayVoxels;
  }
}

void VoxelizeView::mouseMove(double x,double y) {
  // to be implemented
}

void VoxelizeView::mouseClick(int button,int action,int mods) {
  // to be implemented
}

void VoxelizeView::display() {
  glClearColor(0.0f,0.0f,0.0f,1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glCullFace(GL_BACK);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(35.0,1.0,.1,10);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(0.0,0.0,-6.0,0.0,0.0,0.0,0.0,1.0,0.0);
  // draw original shape
  if(animateDisplay) {
    dt+=.1;
    glRotatef(dt,0.0,1.0,0.0);
    // to be implemented
  }
  if(displayOriginalShape) {
    //cout << "Displaying" << endl;
    //cout <<
    RenderMode rm = WIREFRAME;
    glColor4f(0.0f,0.0f,1.0f,1.0f);
    Modeler::getInstance()->drawCube(rm,originalShape.getPosition(),originalShape.getDimension()[0]/2.0f);
  }
  if(displayVoxels) {
    int numVox = voxelMesh->getSize();
    RenderMode rm = SOLID;
    for(int i=0;i<numVox;i++) {
      glColor4f(1.0f/((float)numVox)*((float)i),0.0f,0.0f,1.0f);
      voxelMesh->get(i)->display(rm);
    }
  }


  // do draw stuffs
}
