#ifndef __VIEWCONTROLLER_H__
#define __VIEWCONTROLLER_H__

// This class contains the list of all views that we make. Makes it easy to choose
// which ones we want to see from the start without doing scene parsing.

#include "../dataStructures/array.h"
#include "view.h"

enum ViewID {
  TEST_VIEW=0,
  PERI_VIEW=1,
  VOXEL_VIEW=2,
  TRIMESH_IO_VIEW=3,
  FRAME_IO_VIEW=4,
  REPLAY_VIEW=5,
  COLLISION_TEST_VIEW=6,
  DEMO_VIEW=7,
  SPRING_TEST_VIEW=8,
  PHYSICS_ENGINE_TEST_VIEW=9,
  PERI_DOUBLE_VIEW=10,
  SPRING_TEST_DOUBLE_VIEW=11,
  COLLISION_TEST_DOUBLE_VIEW=12,
  FRACTURE_VIEW=13,
  FRACTURE_ONE=14,
  FRACTURE_TWO=15,
  FRACTURE_THREE=16,
  FRACTURE_FOUR=17,
  FRACTURE_FIVE=18,
  FRACTURE_FAIL=19,
  AWESOME_FAIL=20
};

class ViewController {
private:
  // singleton instance
  static ViewController* instance;
  // member variables
  Array<View*>* views;
  View* currentView;
  // constructor for singleton
  ViewController(ViewID id);
  // methods
  void createViews();
public:
  ~ViewController();
  // singleton methods
  static ViewController* getInstance();
  static void initialize(ViewID id = FRACTURE_VIEW);
  static void destroy();
  // methods
  void switchToView(ViewID id);
  // getter methods
  View* getCurrentView();
};

#endif
