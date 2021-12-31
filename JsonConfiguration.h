#ifndef JSONCONFIGURATION_H
#define JSONCONFIGURATION_H

#include <QJsonObject>

class JsonConfiguration
{
public:
  virtual bool save(QJsonObject& object) const = 0;
  virtual bool load(const QJsonObject& object) = 0;
};

#endif  // JSONCONFIGURATION_H
