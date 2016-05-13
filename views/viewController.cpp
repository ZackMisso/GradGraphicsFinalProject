#include "viewController.h"
#include "testView.h"
#include "periTestView.h"
#include "voxelizeView.h"
#include "trimeshIOView.h"
#include "frameIOView.h"
#include "replayView.h"
#include "collisionTestView.h"
#include "finalDemoView.h"
#include "springTestView.h"
#include "physicsEngineTestView.h"
#include "periTestViewDouble.h"
#include "springTestViewDouble.h"
#include "collisionTestDoubleView.h"
#include "fractureView.h"

ViewController* ViewController::instance = 0x0;

ViewController::ViewController() {
  views = new Array<View*>();
  currentView = 0x0;
  createViews();
  //switchToView(VOXEL_VIEW);
  //switchToView(SPRING_TEST_VIEW);
  //switchToView(COLLISION_TEST_VIEW);
  // switchToView(COLLISION_TEST_DOUBLE_VIEW);
  //switchToView(PERI_VIEW);
  //switchToView(SPRING_TEST_DOUBLE_VIEW);
  // switchToView(REPLAY_VIEW);
  //switchToView(PERI_DOUBLE_VIEW);
  switchToView(FRACTURE_VIEW);
}

ViewController::~ViewController() {
  currentView = 0x0;
  while(views->getSize())
    delete views->removeLast();
  delete views;
}

void ViewController::createViews() {
  views->add(new TestView());
  views->add(new PeriTestView());
  views->add(new VoxelizeView());
  views->add(new TrimeshIOView());
  views->add(new FrameIOView());
  views->add(new ReplayView());
  views->add(new CollisionTestView());
  views->add(new FinalDemoView());
  views->add(new SpringTestView());
  views->add(new PhysicsEngineTestView());
  views->add(new PeriTestViewDouble());
  views->add(new SpringTestViewDouble());
  views->add(new CollisionTestDoubleView());
  views->add(new FractureView());
  // create more in the order they appear in the enum
}

void ViewController::switchToView(ViewID id) {
  if(currentView)
    currentView->deInitialize();
  currentView = views->get(id);
  currentView->initialize();
}

ViewController* ViewController::getInstance() {
  return instance;
}

void ViewController::initialize() {
  if(!instance)
    instance = new ViewController();
}

void ViewController::destroy() {
  if(instance) {
    delete instance;
    instance = 0x0;
  }
}

View* ViewController::getCurrentView() { return currentView; }
