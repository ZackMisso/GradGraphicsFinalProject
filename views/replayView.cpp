#include "replayView.h"
#include "../io/frameReader.h"

void ReplayView::initialize() {
  bakedSystem = new BakedSystem();
  fileName = "frames/frame";
  totalFrames = 300;
  currentFrame = 0;
  fps = 1.0f/60.0f;
  if(getDoublePercision()) {
    FrameReader::getInstance()->readFramed(bakedSystem,fileName, totalFrames);
  } else {
    FrameReader::getInstance()->readFramef(bakedSystem,fileName, totalFrames);
  }
}

void ReplayView::deInitialize() {
  delete bakedSystem;
}

void ReplayView::keyboard(int key,int scancode,int action,int mods) {

}

void ReplayView::mouseClick(int button,int action,int mods) {

}

void ReplayView::display() {

}
