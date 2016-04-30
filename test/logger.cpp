#include "logger.h"

Logger* Logger::instance = 0x0;

Logger::Logger() {
  logs = new Array<TimeLog*>();
}

Logger::~Logger() {
  while(logs->getSize())
    logs->removeLast();
  delete logs;
}

Logger* Logger::getInstance() {
  return instance;
}

void Logger::initialize() {
  if(!instance)
    instance = new Logger();
}

void Logger::destroy() {
  if(instance)
    delete instance;
}

TimeLog* Logger::getLogById(string id) {
  // to be implemented
  return 0x0;
}

TimeLog* Logger::createNewLog(string id) {
  // to be implemented
  return 0x0;
}
