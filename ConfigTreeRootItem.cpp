#include "ConfigTreeRootItem.h"

#include "MainWindow.h"

ConfigTreeRootItem::ConfigTreeRootItem(const QString& name,
                                       MainWindow* mainWindow)
    : ConfigTreeItem(name), mainWindow_(mainWindow)
{
}

void ConfigTreeRootItem::displayWidget(QWidget* widget)
{
  mainWindow_->displayWidget(widget);
}
