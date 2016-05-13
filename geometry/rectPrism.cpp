#include "rectPrism.h"
#include "../render/modeler.h"

RectPrismf::RectPrismf() {
  prism = BBoxf();
}

RectPrismf::RectPrismf(Vec3f p,Vec3f d) {
  prism = BBoxf(p,d);
}

RectPrismf::RectPrismf(BBoxf box) {
  prism = box;
}

BBoxf RectPrismf::getBBox() {
  return prism;
}

bool RectPrismf::containsPoint(Vec3f point) {
  // to be implemented
  return false;
}

void RectPrismf::writeToFile(ofstream& file) {
  // to be implemented
}

void RectPrismf::readFromFile(ifstream& file) {
  // to be implemented
}

void RectPrismf::render(RenderMode rm) {
  Modeler::getInstance()->drawBBox(rm,prism);
}

void RectPrismf::updatePosition(Vec3f pos) {
  prism.setPosition(pos);
}

BBoxf RectPrismf::getPrism() { return prism; }
Vec3f RectPrismf::getPosition() { return prism.getPosition(); }
Vec3f RectPrismf::getDimension() { return prism.getDimension(); }

void RectPrismf::setPrism(BBoxf param) { prism = param; }
void RectPrismf::setPosition(Vec3f param) { prism.setPosition(param); }
void RectPrismf::setDimension(Vec3f param) { prism.setDimension(param); }

//////////////////// DOUBLE VERSION ///////////////////////

RectPrismd::RectPrismd() {
  prism = BBoxd();
}

RectPrismd::RectPrismd(Vec3d p,Vec3d d) {
  prism = BBoxd(p,d);
}

RectPrismd::RectPrismd(BBoxd box) {
  prism = box;
}

BBoxd RectPrismd::getBBox() {
  return prism;
}

bool RectPrismd::containsPoint(Vec3d point) {
  // to be implemented
  return false;
}

void RectPrismd::writeToFile(ofstream& file) {
  // to be implemented
}

void RectPrismd::readFromFile(ifstream& file) {
  // to be implemented
}

void RectPrismd::render(RenderMode rm) {
  Modeler::getInstance()->drawBBox(rm,prism);
}

void RectPrismd::updatePosition(Vec3d pos) {
  prism.setPosition(pos);
}

BBoxd RectPrismd::getPrism() { return prism; }
Vec3d RectPrismd::getPosition() { return prism.getPosition(); }
Vec3d RectPrismd::getDimension() { return prism.getDimension(); }

void RectPrismd::setPrism(BBoxd param) { prism = param; }
void RectPrismd::setPosition(Vec3d param) { prism.setPosition(param); }
void RectPrismd::setDimension(Vec3d param) { prism.setDimension(param); }
