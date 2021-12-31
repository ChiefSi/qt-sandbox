#pragma once

#include <QStackedWidget>

#include "ConfigPage.h"
#include "ConfigTreeItem.h"

class ConfigSection : public QWidget, public ConfigTreeItem
{
  Q_OBJECT

public:
  explicit ConfigSection(const QString& name, QWidget* parent = nullptr);
  ~ConfigSection() override = default;

  void activate() override;
  void displayWidget(QWidget* widget) override;

  void appendChild(ConfigPage* page);
  void appendChild(ConfigSection* section);

private:
  QStackedWidget* stack_;
};
