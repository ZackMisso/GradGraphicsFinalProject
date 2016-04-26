#include  "frameWriter.h"

FrameWriter* FrameWriter::instance = 0x0;

FrameWriter::FrameWriter() { }

FrameWriter::~FrameWriter() { }

void writeFramef(PeriSystemf* ps) {
  // to be implemented
}

void writeFramed(PeriSystemd* ps) {
  // to be implemented
}

FrameWriter* FrameWriter::getInstance() {
  return instance;
}

void FrameWriter::initialize() {
  if(!instance)
    instance = new FrameWriter();
}

void FrameWriter::destroy() {
  if(instance)
    delete instance;
}
