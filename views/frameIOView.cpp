#include "frameIOView.h"

void FrameIOView::initialize() {
  // to be implemented
}

void FrameIOView::deInitialize() {
  // to be implemented
}

void FrameIOView::keyboard(int key,int scancode,int action,int mods) {
  if(key == GLFW_KEY_S && action == GLFW_PRESS) {
  	// taken from http://stackoverflow.com/questions/19173412
  	// we get the width/height of the screen into this array
    int screenStats[4];
    // get the width/height of the window
    glGetIntegerv(GL_VIEWPORT, screenStats);
    int width = screenStats[2];
    int height = screenStats[3];
    // generate an array large enough to hold the pixel data
    // (width*height*bytesPerPixel)
    unsigned char* pixels = new unsigned char[width * height * 3];
    // read in the pixel data, TGA's pixels are BGR aligned
    glReadPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels);

    for (int y = 0; y < height; ++y) {
    	for (int x = 0; x < width; ++x) {
    		unsigned char* rgb = pixels + 3 * (y * width + x);
        // TODO: write the pixels to PNG somehow...
    	}
    }
  }
}

void FrameIOView::display() {
  // to be implemented
}
