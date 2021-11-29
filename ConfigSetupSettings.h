#ifndef CONFIGSETUPSETTINGS_H
#define CONFIGSETUPSETTINGS_H

#include <ostream>

struct ConfigSetupSettings
{
  int numHighServers = 1;
  int numHighInterfaces = 1;
  int numLowServers = 1;
  int numLowInterfaces = 1;
};

inline std::ostream& operator<<(std::ostream& os, const ConfigSetupSettings& settings)
{
  os << "ConfigSetupSettings:\n";
  os << "  High servers:    " << settings.numHighServers << '\n';
  os << "  High interfaces: " << settings.numHighInterfaces << '\n';
  os << "  Low servers:     " << settings.numLowServers << '\n';
  os << "  Low interfaces:  " << settings.numLowInterfaces;
  return os;
}

#endif // CONFIGSETUPSETTINGS_H
