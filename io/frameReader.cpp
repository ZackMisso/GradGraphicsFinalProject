#include  "frameReader.h"

FrameReader* FrameReader::instance = 0x0;

FrameReader::FrameReader() { }

FrameReader::~FrameReader() { }

void FrameReader::readFramef(PeriSystemf* ps) {
  // to be implemented
}

void FrameReader::readFramed(PeriSystemd* ps) {
  // to be implemented
}

FrameReader* FrameReader::getInstance() {
  return instance;
}

void FrameReader::initialize() {
  if(!instance)
    instance = new FrameReader();
}

void FrameReader::destroy() {
  if(instance)
    delete instance;
}
