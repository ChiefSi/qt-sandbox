#include "ConfigTreeRootItem.h"

#include "MainWindow.h"

ConfigTreeRootItem::ConfigTreeRootItem(const QString& name, MainWindow* mainWindow)
	: ConfigTreeItem(name)
	, mainWindow_(mainWindow)
{
}

void ConfigTreeRootItem::onActivate()
{
	// noop
}

void ConfigTreeRootItem::displayWidget(QWidget* widget)
{
	mainWindow_->displayWidget(widget);
}
