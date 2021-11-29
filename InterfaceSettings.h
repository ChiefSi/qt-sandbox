#ifndef INTERFACESETTINGS_H
#define INTERFACESETTINGS_H

#include "EthernetSettings.h"
#include "Ipv4Settings.h"

struct InterfaceSettings
{
  EthernetSettings connection;
  Ipv4Settings ipv4;
};

#endif // INTERFACESETTINGS_H
