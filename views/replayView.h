#ifndef __REPLAYVIEW_H__
#define __REPLAYVIEW_H__

#include <GLFW/glfw3.h>
#include "view.h"
#include "../bake/bakedSystem.h"

class ReplayView : public View {
private:
  BakedSystem* bakedSystem;
  string fileName;
  int totalFrames;
  int currentFrame;
  float fps;
  bool isWireFrame;
public:
  virtual void initialize();
  virtual void deInitialize();
  virtual void keyboard(int key,int scancode,int action,int mods);
  virtual void mouseClick(int button,int action,int mods);
  virtual void display();
};

#endif
