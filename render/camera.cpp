#include "camera.h"
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

Cameraf::Cameraf() {
  orientation = Quatf();
  position = Vec3f();
  fieldOfView = 35.0f;
  aspectRatio = 1.0f;
  near = 0.1f;
  far = 50.0f;
}

Cameraf::Cameraf(float one,float two,float three,float four) {
  orientation = Quatf();
  position = Vec3f();
  fieldOfView = one;
  aspectRatio = two;
  near = three;
  far = four;
}

void Cameraf::setUpProjection() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(fieldOfView,aspectRatio,near,far);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  // to do... enter in the matrix for orientation and position
}

Quatf Cameraf::getOrientation() { return orientation; }
Vec3f Cameraf::getPosition() { return position; }
float Cameraf::getFieldOfView() { return fieldOfView; }
float Cameraf::getAspectRatio() { return aspectRatio; }
float Cameraf::getNear() { return near; }
float Cameraf::getFar() { return far; }

void Cameraf::setOrientation(Quatf param) { orientation = param; }
void Cameraf::setPosition(Vec3f param) { position = param; }
void Cameraf::setFieldOfView(float param) { fieldOfView = param; }
void Cameraf::setAspectRatio(float param) { aspectRatio = param; }
void Cameraf::setNear(float param) { near = param; }
void Cameraf::setFar(float param) { far = param; }

///////////////////////// DOUBLE VERSION /////////////////////////////

Camerad::Camerad() {
  orientation = Quatd();
  position = Vec3d();
  fieldOfView = 35.0f;
  aspectRatio = 1.0f;
  near = 0.1f;
  far = 50.0f;
}

Camerad::Camerad(double one,double two,double three,double four) {
  orientation = Quatd();
  position = Vec3d();
  fieldOfView = one;
  aspectRatio = two;
  near = three;
  far = four;
}

void Camerad::setUpProjection() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(fieldOfView,aspectRatio,near,far);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  // to do... enter in the matrix for orientation and position
}

Quatd Camerad::getOrientation() { return orientation; }
Vec3d Camerad::getPosition() { return position; }
double Camerad::getFieldOfView() { return fieldOfView; }
double Camerad::getAspectRatio() { return aspectRatio; }
double Camerad::getNear() { return near; }
double Camerad::getFar() { return far; }

void Camerad::setOrientation(Quatd param) { orientation = param; }
void Camerad::setPosition(Vec3d param) { position = param; }
void Camerad::setFieldOfView(double param) { fieldOfView = param; }
void Camerad::setAspectRatio(double param) { aspectRatio = param; }
void Camerad::setNear(double param) { near = param; }
void Camerad::setFar(double param) { far = param; }
