#ifndef SERVERSETTINGS_H
#define SERVERSETTINGS_H

#include <map>

#include "InterfaceSettings.h"

typedef std::map<std::string, InterfaceSettings> InterfaceMap;

struct ServerSettings
{
  InterfaceMap interfaceMap;
};

#endif // SERVERSETTINGS_H
