#include "ConfigSection.h"

#include <QPushButton>
#include <QVBoxLayout>
#include <iostream>
ConfigSection::ConfigSection(const QString& name, QWidget* parent)
    : QWidget(parent), ConfigTreeItem(name)
{
  stack_ = new QStackedWidget();
  QVBoxLayout* layout = new QVBoxLayout(this);
  layout->addWidget(stack_);
}

void ConfigSection::activate()
{
  stack_->setCurrentIndex(0);

  auto* parent = ConfigTreeItem::parent();
  if (parent != nullptr)
  {
    parent->displayWidget(this);
  }
}

void ConfigSection::appendChild(ConfigPage* page)
{
  stack_->addWidget(page);
  ConfigTreeItem::appendChild(page);
}

void ConfigSection::appendChild(ConfigSection* section)
{
  stack_->addWidget(section);
  ConfigTreeItem::appendChild(section);
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
