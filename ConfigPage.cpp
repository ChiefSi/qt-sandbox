#include "ConfigPage.h"

ConfigPage::ConfigPage(const QString& name, QWidget* parent)
	: QWidget(parent)
	, ConfigTreeItem(name)
{
}

void ConfigPage::onActivate()
{
	auto* parent = ConfigTreeItem::parent();

	if (parent != nullptr)
	{
		parent->displayWidget(this);
	}
}

void ConfigPage::displayWidget(QWidget* widget)
{
	// noop
}
