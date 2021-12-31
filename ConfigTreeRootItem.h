#pragma once

#include "ConfigTreeItem.h"

class MainWindow;

class ConfigTreeRootItem : public ConfigTreeItem
{
public:
  ConfigTreeRootItem(const QString& name, MainWindow* mainWindow);
  ~ConfigTreeRootItem() override = default;

  void displayWidget(QWidget* widget) override;

private:
  MainWindow* mainWindow_;
};
