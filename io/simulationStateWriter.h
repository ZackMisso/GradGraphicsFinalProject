#ifndef __SIMULATIONSTATEWRITER_H__
#define __SIMULATIONSTATEWRITER_H__

// reads the contents of a scene for a specified frame

#include "../peri/periSystem.h"

class SimulationStateWriter {
private:
  static SimulationStateWriter* instance;
  SimulationStateWriter();
public:
  ~SimulationStateWriter();
  void writeSimulationStatef(PeriSystemf* ps);
  void writeSimulationStated(PeriSystemd* ps);
  // singleton methods
  static SimulationStateWriter* getInstance();
  static void initialize();
  static void destroy();
};

#endif
