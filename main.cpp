#define GLFW_INCLUDE_GLU
#include <iostream>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include "views/viewController.h"
#include "render/modeler.h"
#include "physics/collisionMethods.h"
#include "io/frameReader.h"
#include "io/frameWriter.h"
#include "io/simulationStateReader.h"
#include "io/simulationStateWriter.h"
#include "io/trimeshReader.h"
#include "geometry/voxelizer.h"

// OpenGL callbacks
void display();
void keyboard(GLFWwindow* window,int key,int scancode,int action,int mods);
void mouseMove(GLFWwindow* window,double x,double y);
void mouseClick(GLFWwindow* window,int button,int action,int mods);
void error(int error, const char* description);

int main(int argc,char** argv) {
  // initialize our own subsystems
  ViewController::initialize();
  Modeler::initialize();
  Voxelizer::initialize();
  CollisionMethods::initialize();
  // initialize io
  FrameReader::initialize();
  FrameWriter::initialize();
  SimulationStateReader::initialize();
  SimulationStateWriter::initialize();
  TriMeshReader::initialize();
  // initialize glfw
  if(!glfwInit())
    exit(EXIT_FAILURE);
  // create the window
  GLFWwindow* window = glfwCreateWindow(1000,1000,"zBaEcNk",NULL,NULL);
  if (!window) {
    // there is an error if the window is not created
    glfwTerminate();
    exit(EXIT_FAILURE);
  }
  int width;
  int height;
  // set the error callback
  glfwSetErrorCallback(error);
  // set the main context for OpenGL to draw to
  glfwMakeContextCurrent(window);
  // set the callback method for keyboard input
  glfwSetKeyCallback(window,keyboard);
  // set the callback method for mouse movement input
  glfwSetCursorPosCallback(window,mouseMove);
  // set the callback method for mouse click input
  glfwSetMouseButtonCallback(window,mouseClick);
  // get the size of the window
  glfwGetFramebufferSize(window, &width, &height);
  // set the viewport (what part of the window is drawn on by OpenGL)
  glViewport(0,0,width,height);
  // set the speed for swapping buffers (once per frame)
  glfwSwapInterval(1);
  // main loop
  while (!glfwWindowShouldClose(window))
  {
    display();
    glfwSwapBuffers(window);
    glfwPollEvents();
  }
  // clean up
  // destroy our own subsystems
  ViewController::destroy();
  Modeler::destroy();
  Voxelizer::destroy();
  CollisionMethods::destroy();
  // destroy io
  FrameReader::destroy();
  FrameWriter::destroy();
  SimulationStateReader::destroy();
  SimulationStateWriter::destroy();
  TriMeshReader::destroy();
  // clean up glfw
  glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}

void display() {
  ViewController::getInstance()->getCurrentView()->display();
}

void keyboard(GLFWwindow* window,int key,int scancode,int action,int mods) {
  if(key==GLFW_KEY_ESCAPE && action==GLFW_PRESS)
    glfwSetWindowShouldClose(window,GL_TRUE);
  if(key == GLFW_KEY_W && action == GLFW_PRESS) {
    // example of handling key presses
  }
  ViewController::getInstance()->getCurrentView()->keyboard(key,scancode,action,mods);
}

void error(int error, const char* description) {
  // to be implemented
  std::cout << "error code " << error << ": " << description << std::endl;
}

void mouseMove(GLFWwindow* window,double x,double y) {
  ViewController::getInstance()->getCurrentView()->mouseMove(x,y);
}

void mouseClick(GLFWwindow* window,int button,int action,int mods) {
  if(button == GLFW_MOUSE_BUTTON_LEFT && GLFW_PRESS) {
    // example input
  }
  ViewController::getInstance()->getCurrentView()->mouseClick(button,action,mods);
}
