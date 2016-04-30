#include "periConstants.h"

int PeriConstants::nextID = 0;

int PeriConstants::getNextID() {
  return nextID++;
}
