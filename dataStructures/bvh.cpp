#include "bvh.h"

BVHf::BVHf() {
  root = 0x0;
}

BVHf::~BVHf() {
  delete root;
}

BVHfNode* BVHf::getRoot() { return root; }

void BVHf::setRoot(BVHfNode* param) { root = param; }

///////////////////////////// BVHd //////////////////////////////////

BVHd::BVHd() {
  root = 0x0;
}

BVHd::~BVHd() {
  delete root;
}

BVHdNode* BVHd::getRoot() { return root; }

void BVHd::setRoot(BVHdNode* param) { root = param; }

///////////////////////////// BVHfNode //////////////////////////////

BVHfNode::BVHfNode() {
  right = 0x0;
  left = 0x0;
  contents = new Array<Geometryf*>();
}

BVHfNode::~BVHfNode() {
  if(right) delete right;
  if(left) delete left;
  if(contents) {
    while(contents->getSize())
      delete contents->removeLast();
    delete contents;
  }
}

BVHfNode* BVHfNode::getRight() { return right; }
BVHfNode* BVHfNode::getLeft() { return left; }
Array<Geometryf*>* BVHfNode::getContents() { return contents; }

void BVHfNode::setRight(BVHfNode* param) { right = param; }
void BVHfNode::setLeft(BVHfNode* param) { left = param; }
void BVHfNode::setGeometry(Array<Geometryf*>* param) { contents = param; }

///////////////////////////// BVHdNode //////////////////////////////

BVHdNode::BVHdNode() {
  right = 0x0;
  left = 0x0;
  contents = new Array<Geometryd*>();
}

BVHdNode::~BVHdNode() {
  if(right) delete right;
  if(left) delete left;
  if(contents) {
    while(contents->getSize())
      delete contents->removeLast();
    delete contents;
  }
}

BVHdNode* BVHdNode::getRight() { return right; }
BVHdNode* BVHdNode::getLeft() { return left; }
Array<Geometryd*>* BVHdNode::getContents() { return contents; }

void BVHdNode::setRight(BVHdNode* param) { right = param; }
void BVHdNode::setLeft(BVHdNode* param) { left = param; }
void BVHdNode::setGeometry(Array<Geometryd*>* param) { contents = param; }
