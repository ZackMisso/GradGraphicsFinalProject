#ifndef __SIMULATIONSTATEWRITER_H__
#define __SIMULATIONSTATEWRITER_H__

// reads the contents of a scene for a specified frame

#include "../physics/physicsWorld.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class SimulationStateWriter {
private:
  static SimulationStateWriter* instance;
  SimulationStateWriter();
  void writePeriSystem(PeriSystemf* peri,ofstream& file);
  void writePeriSystem(PeriSystemd* peri,ofstream& file);
  void writePhysicsObject(PhysicsObjectf* object,ofstream& file);
  void writePhysicsObject(PhysicsObjectd* object,ofstream& file);
  void writePhysicsBody(PhysicsBodyf* body,ofstream& file);
  void writePhysicsBody(PhysicsBodyd* body,ofstream& file);
public:
  ~SimulationStateWriter();
  void writeSimulationStatef(PhysicsWorld* world,string fileName);
  void writeSimulationStated(PhysicsWorld* world,string fileName);
  // singleton methods
  static SimulationStateWriter* getInstance();
  static void initialize();
  static void destroy();
};

#endif
