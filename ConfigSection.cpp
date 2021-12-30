#include "ConfigSection.h"

ConfigSection::ConfigSection(const QString& name, QWidget* parent)
	: ConfigPage(name, parent)
{
	auto* layout = widgetManager_.stackedLayout();
	layout->setParent(this);
}

void ConfigSection::displayWidget(QWidget* widget)
{
	// Update sections stack to display widget
	widgetManager_.display(widget);

	// Propogate display intention up to root
	auto* parent = ConfigTreeItem::parent();
	if (parent != nullptr)
	{
		parent->displayWidget(this);
	}
}
