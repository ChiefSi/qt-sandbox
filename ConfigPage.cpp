#include "ConfigPage.h"

ConfigPage::ConfigPage(const QString& name, QWidget* parent)
	: QWidget(parent)
	, ConfigTreeItem(name)
{
}

void ConfigPage::activate()
{
	auto* parent = ConfigTreeItem::parent();

	if (parent != nullptr)
	{
		parent->displayWidget(this);
	}
}
