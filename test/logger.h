#ifndef __LOGGER_H__
#define __LOGGER_H__

// singleton to help keep track of time spent

#include "../dataStructures/array.h"
#include "timeLog.h"
#include <string>

using namespace std;

class Logger {
private:
  static Logger* instance;
  Array<TimeLog*>* logs;
  Logger();
public:
  ~Logger();
  // singleton methods
  static Logger* getInstance();
  static void initialize();
  static void destroy();
  // methods
  TimeLog* getLogById(string id);
  TimeLog* createNewLog(string id);
};

#endif
