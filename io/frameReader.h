#ifndef __FRAMEREADER_H__
#define __FRAMEREADER_H__

// reads the contents of a scene for a specified frame

#include "../peri/periSystem.h"

class FrameReader {
private:
  static FrameReader* instance;
  FrameReader();
public:
  ~FrameReader();
  void readFramef(PeriSystemf* ps);
  void readFramed(PeriSystemd* ps);
  // singleton methods
  static FrameReader* getInstance();
  static void initialize();
  static void destroy();
};

#endif
