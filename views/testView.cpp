#include "testView.h"
#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>

void TestView::display() {
  glClearColor(0.0f,0.0f,0.0f,1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glColor4f(1.0f,0.0f,0.0f,1.0f);
  glBegin(GL_TRIANGLES);
  glVertex2f(-0.5f,0.5f);
  glVertex2f(0.5f,0.5f);
  glVertex2f(0.0f,-0.5f);
  glEnd();
}
