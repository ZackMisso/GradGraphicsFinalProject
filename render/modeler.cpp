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
    glVertex3f(1.0,-1.0,-1.0);
    glVertex3f(1.0,1.0,-1.0);
    glVertex3f(-1.0,1.0,-1.0);

    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,1.0);
    glVertex3f(1.0,-1.0,-1.0);

    glVertex3f(-1.0,-1.0,-1.0);
    glVertex3f(-1.0,-1.0,1.0);
    glVertex3f(-1.0,1.0,1.0);
    glVertex3f(-1.0,1.0,-1.0);

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
  	glVertex3f(pos[0]-d,pos[1]+d,pos[2]-d);
  	glVertex3f(pos[0]+d,pos[1]+d,pos[2]-d);
    glVertex3f(pos[0]+d,pos[1]-d,pos[2]-d);

  	glVertex3f(pos[0]-d,pos[1]-d,pos[2]-d);
  	glVertex3f(pos[0]+d,pos[1]-d,pos[2]-d);
  	glVertex3f(pos[0]+d,pos[1]-d,pos[2]+d);
    glVertex3f(pos[0]-d,pos[1]-d,pos[2]+d);

  	glVertex3f(pos[0]-d,pos[1]-d,pos[2]-d);
  	glVertex3f(pos[0]-d,pos[1]-d,pos[2]+d);
  	glVertex3f(pos[0]-d,pos[1]+d,pos[2]+d);
    glVertex3f(pos[0]-d,pos[1]+d,pos[2]-d);

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

void Modeler::drawBBox(RenderMode rm,BBoxf box) {
  if(rm == WIREFRAME) {
    Vec3f pos = box.getPosition();
    Vec3f dim = box.getDimension();

    glBegin(GL_LINES);
    glVertex3f(pos[0],pos[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1],pos[2]);

    glVertex3f(pos[0]+dim[0],pos[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]);

    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]);
    glVertex3f(pos[0],pos[1]+dim[1],pos[2]);

    glVertex3f(pos[0],pos[1]+dim[1],pos[2]);
    glVertex3f(pos[0],pos[1],pos[2]);

    glVertex3f(pos[0],pos[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1],pos[2]);

    glVertex3f(pos[0]+dim[0],pos[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1],pos[2]+dim[2]);

    glVertex3f(pos[0]+dim[0],pos[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1],pos[2]+dim[2]);

    glVertex3f(pos[0],pos[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1],pos[2]);

    glVertex3f(pos[0],pos[1],pos[2]);
    glVertex3f(pos[0],pos[1]+dim[1],pos[2]);

    glVertex3f(pos[0],pos[1]+dim[1],pos[2]);
    glVertex3f(pos[0],pos[1]+dim[1],pos[2]+dim[2]);

    glVertex3f(pos[0],pos[1]+dim[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1],pos[2]+dim[2]);

    glVertex3f(pos[0],pos[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1],pos[2]);

    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1]+dim[1],pos[2]+dim[2]);

    glVertex3f(pos[0],pos[1]+dim[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1],pos[2]+dim[2]);

    glVertex3f(pos[0],pos[1],pos[2]+dim[2]);
    glVertex3f(pos[0]+dim[0],pos[1],pos[2]+dim[2]);

    glVertex3f(pos[0]+dim[0],pos[1],pos[2]+dim[2]);
    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]+dim[2]);

    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1]+dim[1],pos[2]+dim[2]);

    glVertex3f(pos[0],pos[1]+dim[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1]+dim[1],pos[2]);

    glVertex3f(pos[0],pos[1]+dim[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]);

    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]+dim[2]);

    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]+dim[2]);
    glVertex3f(pos[0]+dim[0],pos[1],pos[2]+dim[2]);

    glVertex3f(pos[0]+dim[0],pos[1],pos[2]+dim[2]);
    glVertex3f(pos[0]+dim[0],pos[1],pos[2]);

    glVertex3f(pos[0]+dim[0],pos[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]);

    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]+dim[2]);
    glEnd();
  } else if(rm == SOLID) {
    glBegin(GL_QUADS);
    Vec3f pos = box.getPosition();
    Vec3f dim = box.getDimension();

    glVertex3f(pos[0],pos[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]);
    glVertex3f(pos[0],pos[1]+dim[1],pos[2]);

    glVertex3f(pos[0],pos[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1],pos[2]+dim[2]);

    glVertex3f(pos[0],pos[1],pos[2]);
    glVertex3f(pos[0],pos[1]+dim[1],pos[2]);
    glVertex3f(pos[0],pos[1]+dim[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1],pos[2]+dim[2]);

    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1]+dim[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1],pos[2]+dim[2]);
    glVertex3f(pos[0]+dim[0],pos[1],pos[2]+dim[2]);

    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1]+dim[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1]+dim[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]);

    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]+dim[2]);
    glVertex3f(pos[0]+dim[0],pos[1],pos[2]+dim[2]);
    glVertex3f(pos[0]+dim[0],pos[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]);
    glEnd();
  } else if(rm == SHADED) {

  }
}

void Modeler::drawBBox(RenderMode rm,BBoxd box) {
  if(rm == WIREFRAME) {
    Vec3d pos = box.getPosition();
    Vec3d dim = box.getDimension();

    glBegin(GL_LINES);
    glVertex3f(pos[0],pos[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1],pos[2]);

    glVertex3f(pos[0]+dim[0],pos[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]);

    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]);
    glVertex3f(pos[0],pos[1]+dim[1],pos[2]);

    glVertex3f(pos[0],pos[1]+dim[1],pos[2]);
    glVertex3f(pos[0],pos[1],pos[2]);

    glVertex3f(pos[0],pos[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1],pos[2]);

    glVertex3f(pos[0]+dim[0],pos[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1],pos[2]+dim[2]);

    glVertex3f(pos[0]+dim[0],pos[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1],pos[2]+dim[2]);

    glVertex3f(pos[0],pos[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1],pos[2]);

    glVertex3f(pos[0],pos[1],pos[2]);
    glVertex3f(pos[0],pos[1]+dim[1],pos[2]);

    glVertex3f(pos[0],pos[1]+dim[1],pos[2]);
    glVertex3f(pos[0],pos[1]+dim[1],pos[2]+dim[2]);

    glVertex3f(pos[0],pos[1]+dim[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1],pos[2]+dim[2]);

    glVertex3f(pos[0],pos[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1],pos[2]);

    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1]+dim[1],pos[2]+dim[2]);

    glVertex3f(pos[0],pos[1]+dim[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1],pos[2]+dim[2]);

    glVertex3f(pos[0],pos[1],pos[2]+dim[2]);
    glVertex3f(pos[0]+dim[0],pos[1],pos[2]+dim[2]);

    glVertex3f(pos[0]+dim[0],pos[1],pos[2]+dim[2]);
    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]+dim[2]);

    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1]+dim[1],pos[2]+dim[2]);

    glVertex3f(pos[0],pos[1]+dim[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1]+dim[1],pos[2]);

    glVertex3f(pos[0],pos[1]+dim[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]);

    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]+dim[2]);

    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]+dim[2]);
    glVertex3f(pos[0]+dim[0],pos[1],pos[2]+dim[2]);

    glVertex3f(pos[0]+dim[0],pos[1],pos[2]+dim[2]);
    glVertex3f(pos[0]+dim[0],pos[1],pos[2]);

    glVertex3f(pos[0]+dim[0],pos[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]);

    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]+dim[2]);
    glEnd();
  } else if(rm == SOLID) {
    glBegin(GL_QUADS);
    Vec3d pos = box.getPosition();
    Vec3d dim = box.getDimension();

    glVertex3f(pos[0],pos[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]);
    glVertex3f(pos[0],pos[1]+dim[1],pos[2]);

    glVertex3f(pos[0],pos[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1],pos[2]+dim[2]);

    glVertex3f(pos[0],pos[1],pos[2]);
    glVertex3f(pos[0],pos[1]+dim[1],pos[2]);
    glVertex3f(pos[0],pos[1]+dim[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1],pos[2]+dim[2]);

    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1]+dim[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1],pos[2]+dim[2]);
    glVertex3f(pos[0]+dim[0],pos[1],pos[2]+dim[2]);

    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1]+dim[1],pos[2]+dim[2]);
    glVertex3f(pos[0],pos[1]+dim[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]);

    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]+dim[2]);
    glVertex3f(pos[0]+dim[0],pos[1],pos[2]+dim[2]);
    glVertex3f(pos[0]+dim[0],pos[1],pos[2]);
    glVertex3f(pos[0]+dim[0],pos[1]+dim[1],pos[2]);
    glEnd();
  } else if(rm == SHADED) {

  }
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
