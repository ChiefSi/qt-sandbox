#include "ConfigSection.h"

#include <iostream>
#include <QPushButton>

ConfigSection::ConfigSection(const QString& name, QWidget* parent)
	: QWidget(parent)
	, ConfigTreeItem(name)
{
	// Why is stack widget not displayed unless addWidget is called on it?
	stack_ = new QStackedWidget(this);
	QPushButton* a = new QPushButton(name, this);
}

void ConfigSection::activate()
{
	auto* parent = ConfigTreeItem::parent();
	if (parent != nullptr)
	{
		parent->displayWidget(this);
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
		parent->displayWidget(this);
	}
}
