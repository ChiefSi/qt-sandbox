#include "ConfigSection.h"

#include <iostream>

ConfigSection::ConfigSection(const QString& name)
	: ConfigTreeItem(name)
{
	stack_ = new QStackedWidget();
}

void ConfigSection::activate()
{
	auto* parent = ConfigTreeItem::parent();
	if (parent != nullptr)
	{
		parent->displayWidget(stack_);
	}
}

void ConfigSection::displayWidget(QWidget* widget)
{
	int index = stack_->indexOf(widget);
	if (index == -1)
	{
		stack_->addWidget(widget);
	}

	stack_->setCurrentWidget(widget);

	// Propogate display intention up to root
	auto* parent = ConfigTreeItem::parent();
	if (parent != nullptr)
	{
		parent->displayWidget(stack_);
	}
}
