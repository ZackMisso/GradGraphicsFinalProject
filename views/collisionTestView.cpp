#include "collisionTestView.h"
#include "../io/frameWriter.h"
#include "../io/simulationStateWriter.h"
#include <iostream>

using namespace std;

void CollisionTestView::initialize() {
  engine = PhysicsEngine::getInstance();
  worldRef = engine->getWorld();
  worldRef->clearWorld();
  fileName = "testScene";
  setLengthOfSimulation(4.0);
  setTimeStep(1.0/60.0);
  setDoublePercision(true);
  // to be implemented
}

void CollisionTestView::deInitialize() {
  worldRef = 0x0;
  engine = 0x0;
  // to be implemented
}

void CollisionTestView::keyboard(int key,int scancode,int action,int mods) {
  // to be implemented
}

void CollisionTestView::mouseMove(double x,double y) {
  // to be implemented
}

void CollisionTestView::mouseClick(int button,int action,int mods) {
  // to be implemented
}

void CollisionTestView::display() {
  // to be implemented
}

// ToDo :: Somehow incorporate multiple threads to make faster
void CollisionTestView::headless() {
  double currentTime = 0.0;
  int currentFrame = 0;
  int totalFrames = (int)(1.0 / getTimeStep() * getLengthOfSimulation());
  cout << "Writing Frame: " << currentFrame << endl;
  // do first frame write
  if(getDoublePercision()) {
    FrameWriter::getInstance()->writeFramed(worldRef,fileName);
    SimulationStateWriter::getInstance()->writeSimulationStated(worldRef,fileName);
  } else {
    FrameWriter::getInstance()->writeFramef(worldRef,fileName);
    SimulationStateWriter::getInstance()->writeSimulationStatef(worldRef,fileName);
  }
  cout << "Starting Simulation" << endl;
  currentFrame++;
  currentTime += getTimeStep();
  while(currentTime < getLengthOfSimulation()) {
    // simulate the frame
    cout << "Simulating Frame: " << currentFrame << " Out of: " << totalFrames << " frames." << endl;
    if(getDoublePercision()) {
      engine->simulatePhysicsStepd(getTimeStep());
    } else {
      engine->simulatePhysicsStepf((float)getTimeStep());
    }
    cout << "Writing Frame: " << currentFrame << endl;
    // write the frame
    if(getDoublePercision()) {
      FrameWriter::getInstance()->writeFramed(worldRef,fileName);
      SimulationStateWriter::getInstance()->writeSimulationStated(worldRef,fileName);
    } else {
      FrameWriter::getInstance()->writeFramef(worldRef,fileName);
      SimulationStateWriter::getInstance()->writeSimulationStatef(worldRef,fileName);
    }
    currentFrame++;
    currentTime += getTimeStep();
  }
}

void CollisionTestView::headlessFromFrame(int frame) {
  // to be implemented
}
