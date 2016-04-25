#include "modeler.h"
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

Modeler* Modeler::instance = 0x0;

Modeler::Modeler() { }

Modeler::~Modeler() { }

void Modeler::drawCube(RenderMode rm) {
  if(rm == WIREFRAME) {
    glBegin(GL_LINES);
    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,1.0,-1.0);

    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);

    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(1.0,-1.0,-1.0);

    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,-1.0);

    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(1.0,-1.0,-1.0);

    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(1.0,-1.0,1.0);

    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);

    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(-1.0,-1.0,-1.0);

    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,1.0,-1.0);

    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(-1.0,1.0,1.0);

    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);

    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(-1.0,-1.0,-1.0);

    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);

    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);

    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(-1.0,1.0,1.0);

    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(1.0,1.0,1.0);

    glVertex3f(1.0,1.0,1.0);
    glVertex3f(-1.0,1.0,1.0);

    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(-1.0,1.0,-1.0);

    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);

    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(1.0,1.0,1.0);

    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);

    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,-1.0);

    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);

    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(1.0,1.0,1.0);
  } else if(rm == SOLID) {
    glBegin(GL_QUADS);

    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(1.0,-1.0,-1.0);

    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);

    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);

    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(-1.0,1.0,1.0);

    glVertex3f(1.0,1.0,1.0);
    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(-1.0,1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);

    glVertex3f(1.0,1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);
  } else if(rm == SHADED) {
    // to be implemented
  }
	glEnd();
}

void Modeler::drawCube(RenderMode rm,Vec3f pos,float d) {
  if(rm == WIREFRAME) {
    glBegin(GL_LINES);
    glVertex3f(pos[0]-d,pos[1]-d,pos[2]-d);
    glVertex3f(pos[0]-d,pos[1]+d,pos[2]-d);

    glVertex3f(pos[0]-d,pos[1]+d,pos[2]-d);
    glVertex3f(pos[0]+d,pos[1]+d,pos[2]-d);

    glVertex3f(pos[0]+d,pos[1]+d,pos[2]-d);
    glVertex3f(pos[0]+d,pos[1]-d,pos[2]-d);

    glVertex3f(pos[0]+d,pos[1]-d,pos[2]-d);
    glVertex3f(pos[0]-d,pos[1]-d,pos[2]-d);

    glVertex3f(pos[0]-d,pos[1]-d,pos[2]-d);
    glVertex3f(pos[0]+d,pos[1]-d,pos[2]-d);

    glVertex3f(pos[0]+d,pos[1]-d,pos[2]-d);
    glVertex3f(pos[0]+d,pos[1]-d,pos[2]+d);

    glVertex3f(pos[0]+d,pos[1]-d,pos[2]+d);
    glVertex3f(pos[0]-d,pos[1]-d,pos[2]+d);

    glVertex3f(pos[0]-d,pos[1]-d,pos[2]+d);
    glVertex3f(pos[0]-d,pos[1]-d,pos[2]-d);

    glVertex3f(pos[0]-d,pos[1]-d,pos[2]-d);
    glVertex3f(pos[0]-d,pos[1]+d,pos[2]-d);

    glVertex3f(pos[0]-d,pos[1]+d,pos[2]-d);
    glVertex3f(pos[0]-d,pos[1]+d,pos[2]+d);

    glVertex3f(pos[0]-d,pos[1]+d,pos[2]+d);
    glVertex3f(pos[0]-d,pos[1]-d,pos[2]+d);

    glVertex3f(pos[0]-d,pos[1]-d,pos[2]+d);
    glVertex3f(pos[0]-d,pos[1]-d,pos[2]-d);

    glVertex3f(pos[0]+d,pos[1]+d,pos[2]+d);
    glVertex3f(pos[0]+d,pos[1]-d,pos[2]+d);

    glVertex3f(pos[0]+d,pos[1]-d,pos[2]+d);
    glVertex3f(pos[0]-d,pos[1]-d,pos[2]+d);

    glVertex3f(pos[0]-d,pos[1]-d,pos[2]+d);
    glVertex3f(pos[0]-d,pos[1]+d,pos[2]+d);

    glVertex3f(pos[0]-d,pos[1]+d,pos[2]+d);
    glVertex3f(pos[0]+d,pos[1]+d,pos[2]+d);

    glVertex3f(pos[0]+d,pos[1]+d,pos[2]+d);
    glVertex3f(pos[0]-d,pos[1]+d,pos[2]+d);

    glVertex3f(pos[0]-d,pos[1]+d,pos[2]+d);
    glVertex3f(pos[0]-d,pos[1]+d,pos[2]-d);

    glVertex3f(pos[0]-d,pos[1]+d,pos[2]-d);
    glVertex3f(pos[0]+d,pos[1]+d,pos[2]-d);

    glVertex3f(pos[0]+d,pos[1]+d,pos[2]-d);
    glVertex3f(pos[0]+d,pos[1]+d,pos[2]+d);

    glVertex3f(pos[0]+d,pos[1]+d,pos[2]+d);
    glVertex3f(pos[0]+d,pos[1]-d,pos[2]+d);

    glVertex3f(pos[0]+d,pos[1]-d,pos[2]+d);
    glVertex3f(pos[0]+d,pos[1]-d,pos[2]-d);

    glVertex3f(pos[0]+d,pos[1]-d,pos[2]-d);
    glVertex3f(pos[0]+d,pos[1]+d,pos[2]-d);

    glVertex3f(pos[0]+d,pos[1]+d,pos[2]-d);
    glVertex3f(pos[0]+d,pos[1]+d,pos[2]+d);
  } else if(rm == SOLID) {
    glBegin(GL_QUADS);
  	glVertex3f(pos[0]-d,pos[1]-d,pos[2]-d);
  	glVertex3f(pos[0]+d,pos[1]-d,pos[2]-d);
  	glVertex3f(pos[0]+d,pos[1]+d,pos[2]-d);
  	glVertex3f(pos[0]-d,pos[1]+d,pos[2]-d);

  	glVertex3f(pos[0]-d,pos[1]-d,pos[2]-d);
  	glVertex3f(pos[0]-d,pos[1]-d,pos[2]+d);
  	glVertex3f(pos[0]+d,pos[1]-d,pos[2]+d);
  	glVertex3f(pos[0]+d,pos[1]-d,pos[2]-d);

  	glVertex3f(pos[0]-d,pos[1]-d,pos[2]-d);
  	glVertex3f(pos[0]-d,pos[1]+d,pos[2]-d);
  	glVertex3f(pos[0]-d,pos[1]+d,pos[2]+d);
  	glVertex3f(pos[0]-d,pos[1]-d,pos[2]+d);

  	glVertex3f(pos[0]+d,pos[1]+d,pos[2]+d);
  	glVertex3f(pos[0]+d,pos[1]-d,pos[2]+d);
  	glVertex3f(pos[0]+d,pos[1]-d,pos[2]-d);
  	glVertex3f(pos[0]+d,pos[1]+d,pos[2]-d);

  	glVertex3f(pos[0]+d,pos[1]+d,pos[2]+d);
  	glVertex3f(pos[0]+d,pos[1]+d,pos[2]-d);
  	glVertex3f(pos[0]-d,pos[1]+d,pos[2]-d);
  	glVertex3f(pos[0]-d,pos[1]+d,pos[2]+d);

  	glVertex3f(pos[0]+d,pos[1]+d,pos[2]+d);
  	glVertex3f(pos[0]-d,pos[1]+d,pos[2]+d);
  	glVertex3f(pos[0]-d,pos[1]-d,pos[2]+d);
  	glVertex3f(pos[0]+d,pos[1]-d,pos[2]+d);
  } else if(rm == SHADED) {
    // to be implemented
  }
	glEnd();
}

void Modeler::drawCube(RenderMode rm,Vec3d pos,double d) {
  if(rm == WIREFRAME) {
    glBegin(GL_LINES);
    glVertex3f(pos[0]-d,pos[1]-d,pos[2]-d);
    glVertex3f(pos[0]-d,pos[1]+d,pos[2]-d);

    glVertex3f(pos[0]-d,pos[1]+d,pos[2]-d);
    glVertex3f(pos[0]+d,pos[1]+d,pos[2]-d);

    glVertex3f(pos[0]+d,pos[1]+d,pos[2]-d);
    glVertex3f(pos[0]+d,pos[1]-d,pos[2]-d);

    glVertex3f(pos[0]+d,pos[1]-d,pos[2]-d);
    glVertex3f(pos[0]-d,pos[1]-d,pos[2]-d);

    glVertex3f(pos[0]-d,pos[1]-d,pos[2]-d);
    glVertex3f(pos[0]+d,pos[1]-d,pos[2]-d);

    glVertex3f(pos[0]+d,pos[1]-d,pos[2]-d);
    glVertex3f(pos[0]+d,pos[1]-d,pos[2]+d);

    glVertex3f(pos[0]+d,pos[1]-d,pos[2]+d);
    glVertex3f(pos[0]-d,pos[1]-d,pos[2]+d);

    glVertex3f(pos[0]-d,pos[1]-d,pos[2]+d);
    glVertex3f(pos[0]-d,pos[1]-d,pos[2]-d);

    glVertex3f(pos[0]-d,pos[1]-d,pos[2]-d);
    glVertex3f(pos[0]-d,pos[1]+d,pos[2]-d);

    glVertex3f(pos[0]-d,pos[1]+d,pos[2]-d);
    glVertex3f(pos[0]-d,pos[1]+d,pos[2]+d);

    glVertex3f(pos[0]-d,pos[1]+d,pos[2]+d);
    glVertex3f(pos[0]-d,pos[1]-d,pos[2]+d);

    glVertex3f(pos[0]-d,pos[1]-d,pos[2]+d);
    glVertex3f(pos[0]-d,pos[1]-d,pos[2]-d);

    glVertex3f(pos[0]+d,pos[1]+d,pos[2]+d);
    glVertex3f(pos[0]+d,pos[1]-d,pos[2]+d);

    glVertex3f(pos[0]+d,pos[1]-d,pos[2]+d);
    glVertex3f(pos[0]-d,pos[1]-d,pos[2]+d);

    glVertex3f(pos[0]-d,pos[1]-d,pos[2]+d);
    glVertex3f(pos[0]-d,pos[1]+d,pos[2]+d);

    glVertex3f(pos[0]-d,pos[1]+d,pos[2]+d);
    glVertex3f(pos[0]+d,pos[1]+d,pos[2]+d);

    glVertex3f(pos[0]+d,pos[1]+d,pos[2]+d);
    glVertex3f(pos[0]-d,pos[1]+d,pos[2]+d);

    glVertex3f(pos[0]-d,pos[1]+d,pos[2]+d);
    glVertex3f(pos[0]-d,pos[1]+d,pos[2]-d);

    glVertex3f(pos[0]-d,pos[1]+d,pos[2]-d);
    glVertex3f(pos[0]+d,pos[1]+d,pos[2]-d);

    glVertex3f(pos[0]+d,pos[1]+d,pos[2]-d);
    glVertex3f(pos[0]+d,pos[1]+d,pos[2]+d);

    glVertex3f(pos[0]+d,pos[1]+d,pos[2]+d);
    glVertex3f(pos[0]+d,pos[1]-d,pos[2]+d);

    glVertex3f(pos[0]+d,pos[1]-d,pos[2]+d);
    glVertex3f(pos[0]+d,pos[1]-d,pos[2]-d);

    glVertex3f(pos[0]+d,pos[1]-d,pos[2]-d);
    glVertex3f(pos[0]+d,pos[1]+d,pos[2]-d);

    glVertex3f(pos[0]+d,pos[1]+d,pos[2]-d);
    glVertex3f(pos[0]+d,pos[1]+d,pos[2]+d);
  } else if(rm == SOLID) {
    glBegin(GL_QUADS);
  	glVertex3f(pos[0]-d,pos[1]-d,pos[2]-d);
  	glVertex3f(pos[0]+d,pos[1]-d,pos[2]-d);
  	glVertex3f(pos[0]+d,pos[1]+d,pos[2]-d);
  	glVertex3f(pos[0]-d,pos[1]+d,pos[2]-d);

  	glVertex3f(pos[0]-d,pos[1]-d,pos[2]-d);
  	glVertex3f(pos[0]-d,pos[1]-d,pos[2]+d);
  	glVertex3f(pos[0]+d,pos[1]-d,pos[2]+d);
  	glVertex3f(pos[0]+d,pos[1]-d,pos[2]-d);

  	glVertex3f(pos[0]-d,pos[1]-d,pos[2]-d);
  	glVertex3f(pos[0]-d,pos[1]+d,pos[2]-d);
  	glVertex3f(pos[0]-d,pos[1]+d,pos[2]+d);
  	glVertex3f(pos[0]-d,pos[1]-d,pos[2]+d);

  	glVertex3f(pos[0]+d,pos[1]+d,pos[2]+d);
  	glVertex3f(pos[0]+d,pos[1]-d,pos[2]+d);
  	glVertex3f(pos[0]+d,pos[1]-d,pos[2]-d);
  	glVertex3f(pos[0]+d,pos[1]+d,pos[2]-d);

  	glVertex3f(pos[0]+d,pos[1]+d,pos[2]+d);
  	glVertex3f(pos[0]+d,pos[1]+d,pos[2]-d);
  	glVertex3f(pos[0]-d,pos[1]+d,pos[2]-d);
  	glVertex3f(pos[0]-d,pos[1]+d,pos[2]+d);

  	glVertex3f(pos[0]+d,pos[1]+d,pos[2]+d);
  	glVertex3f(pos[0]-d,pos[1]+d,pos[2]+d);
  	glVertex3f(pos[0]-d,pos[1]-d,pos[2]+d);
  	glVertex3f(pos[0]+d,pos[1]-d,pos[2]+d);
  } else if(rm == SHADED) {
    // to be implemented
  }
	glEnd();
}

void Modeler::initialize() {
  if(!instance)
    instance = new Modeler();
}

void Modeler::destroy() {
  if(instance)
    delete instance;
}

Modeler* Modeler::getInstance() { return instance; }
