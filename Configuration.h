#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <map>

#include "ServerSettings.h"

typedef std::map<std::string, ServerSettings> ServerMap;

/**
 * @brief Internal representation of configuration
 */
struct Configuration
{
  ServerMap highServerMap;
  ServerMap lowServerMap;
};

#endif // CONFIGURATION_H
