#ifndef __FRAMEWRITER_H__
#define __FRAMEWRITER_H__

// writes the contents of a scene for a specified frame

#include "../peri/periSystem.h"

class FrameWriter {
private:
  static FrameWriter* instance;
  FrameWriter();
public:
  ~FrameWriter();
  void writeFramef(PeriSystemf* ps);
  void writeFramed(PeriSystemd* ps);
  // singleton methods
  static FrameWriter* getInstance();
  static void initialize();
  static void destroy();
};

#endif
