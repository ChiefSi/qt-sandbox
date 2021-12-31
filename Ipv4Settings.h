#ifndef IPV4SETTINGS_H
#define IPV4SETTINGS_H

#include <ios>
#include <ostream>
#include <string>
#include <vector>

/**
 * @brief Represents a single Ipv4 address or route
 */
struct Ipv4AddressEntry
{
  std::string address;
  uint32_t prefix;
  std::string gateway;
};

struct Ipv4Settings
{
  bool enabled = false;
  bool useDhcp = true;
  bool neverDefault = true;
  bool useManualDns = false;
  bool useManualRoutes = false;
  std::vector<Ipv4AddressEntry> addresses;
  std::vector<std::string> dnsServers;
  std::vector<Ipv4AddressEntry> routes;
};

inline std::ostream& operator<<(std::ostream& os, const Ipv4Settings& settings)
{
  os << std::boolalpha;

  os << "Enabled: " << settings.enabled << '\n';

  os << "Use DHCP: " << settings.useDhcp << '\n';

  os << "Address(es):\n";
  for (auto& entry : settings.addresses)
  {
    os << entry.address << "/" << entry.prefix << " gw " << entry.gateway
       << '\n';
  }
  os << '\n';

  os << "Never default: " << settings.neverDefault << '\n';

  os << "Use manual DNS: " << settings.useManualDns << '\n';
  os << "DNS: ";
  for (auto& entry : settings.dnsServers) os << entry << " ";
  os << '\n';

  os << "Use manual routes: " << settings.useManualRoutes << '\n';
  os << "Routes: " << '\n';
  for (auto& entry : settings.routes)
  {
    os << entry.address << "/" << entry.prefix << " via " << entry.gateway
       << '\n';
  }
  os << '\n';

  return os;
}

#endif  // IPV4SETTINGS_H
