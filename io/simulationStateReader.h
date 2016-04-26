#ifndef __SIMULATIONSTATEREADER_H__
#define __SIMULATIONSTATEREADER_H__

// reads the simulation state for a specified frame

#include "../peri/periSystem.h"

class SimulationStateReader {
private:
  static SimulationStateReader* instance;
  SimulationStateReader();
public:
  ~SimulationStateReader();
  void readSimulationStatef(PeriSystemf* ps);
  void readSimulationStated(PeriSystemd* ps);
  // singleton methods
  static SimulationStateReader* getInstance();
  static void initialize();
  static void destroy();
};

#endif
