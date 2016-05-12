#ifndef __VIEWCONTROLLER_H__
#define __VIEWCONTROLLER_H__

// This class contains the list of all views that we make. Makes it easy to choose
// which ones we want to see from the start without doing scene parsing.

#include "../dataStructures/array.h"
#include "view.h"

enum ViewID {
  TEST_VIEW=0,
  PERI_VIEW,
  VOXEL_VIEW,
  TRIMESH_IO_VIEW,
  FRAME_IO_VIEW,
  REPLAY_VIEW,
  COLLISION_TEST_VIEW,
  DEMO_VIEW,
  SPRING_TEST_VIEW
};

class ViewController {
private:
  // singleton instance
  static ViewController* instance;
  // member variables
  Array<View*>* views;
  View* currentView;
  // constructor for singleton
  ViewController();
  // methods
  void createViews();
public:
  ~ViewController();
  // singleton methods
  static ViewController* getInstance();
  static void initialize();
  static void destroy();
  // methods
  void switchToView(ViewID id);
  // getter methods
  View* getCurrentView();
};

#endif
