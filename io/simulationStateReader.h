#ifndef __SIMULATIONSTATEREADER_H__
#define __SIMULATIONSTATEREADER_H__

// reads the simulation state for a specified frame

#include "../physics/physicsWorld.h"
#include <iostream>
#include <fstream>

using namespace std;

class SimulationStateReader {
private:
  static SimulationStateReader* instance;
  SimulationStateReader();
  PeriSystemf* readPeriSystemf(ifstream& file);
  PeriSystemd* readPeriSystemd(ifstream& file);
  PhysicsObjectf* readPhysicsObjectf(ifstream& file);
  PhysicsObjectf* readPhysicsObjectd(ifstream& file);
  PhysicsBodyf* readPhysicsBodyf(ifstream& file);
  PhysicsBodyd* readPhysicsBodyd(ifstream& file);
public:
  ~SimulationStateReader();
  void readSimulationStatef(PhysicsWorld* ps);
  void readSimulationStated(PhysicsWorld* ps);
  // singleton methods
  static SimulationStateReader* getInstance();
  static void initialize();
  static void destroy();
};

#endif
