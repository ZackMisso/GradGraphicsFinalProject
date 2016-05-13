#include "replayView.h"
#include "../io/frameReader.h"

void ReplayView::initialize() {
  bakedSystem = new BakedSystem();
  fileName = "frames/frame";
  totalFrames = 300;
  currentFrame = 0;
  fps = 1.0f/60.0f;
  isWireFrame = false;
  setDoublePercision(true);
  if(getDoublePercision()) {
    FrameReader::getInstance()->readFramed(bakedSystem,fileName, totalFrames);
  } else {
    FrameReader::getInstance()->readFramef(bakedSystem,fileName, totalFrames);
  }
}

void ReplayView::deInitialize() {
  delete bakedSystem;
}

void ReplayView::keyboard(int key,int scancode,int action,int mods) {
  if(key == GLFW_KEY_W && action == GLFW_PRESS) {
    isWireFrame = !isWireFrame;
  }
}

void ReplayView::mouseClick(int button,int action,int mods) {

}

void ReplayView::display() {
  glClearColor(0.0f,0.0f,0.0f,1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glColor3f(1.0,0.0,0.0);

  if(getDoublePercision()) {
    cout << "display frame " << currentFrame << endl;
    Array<BakedPhysicsObjectd*>* objects = bakedSystem->getObjectsD();
    for (int i = 0; i < objects->getSize(); ++i) {
      objects->get(i)->render(currentFrame, isWireFrame ? WIREFRAME : SOLID);
    }
    if (currentFrame < totalFrames - 1) ++currentFrame;
  } else {
    cout << "oops" << endl;
  }
}
