#include "ConfigSection.h"

ConfigSection::ConfigSection(const QString& name, QWidget* parent)
	: ConfigPage(name, parent)
{
	auto* layout = widgetManager_.stackedLayout();
	layout->setParent(this);
}

void ConfigSection::displayWidget(QWidget* widget)
{
	widgetManager_.display(widget);
}
