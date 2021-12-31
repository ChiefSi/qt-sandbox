#include "ConfigTreeItem.h"

#include <iostream>
ConfigTreeItem::ConfigTreeItem(const QString& name) : name_(name) {}

ConfigTreeItem::~ConfigTreeItem()
{
  // Do not delete the items - they are likely owned by other widgets... damn QT
  // and ownership
  // qDeleteAll(childItems_);
}

void ConfigTreeItem::appendChild(ConfigTreeItem* item)
{
  childItems_.append(item);
  item->setParent(this);
}

ConfigTreeItem* ConfigTreeItem::child(int row)
{
  if (row < 0 || row >= childItems_.size())
  {
    return nullptr;
  }

  return childItems_.at(row);
}

int ConfigTreeItem::childCount() const { return childItems_.count(); }

int ConfigTreeItem::columnCount() const { return 1; }

QVariant ConfigTreeItem::data(int column) const
{
  if (column == 0) return name_;

  return QVariant();
}

int ConfigTreeItem::row() const
{
  if (parent_)
    return parent_->childItems_.indexOf(const_cast<ConfigTreeItem*>(this));

  return 0;
}

ConfigTreeItem* ConfigTreeItem::parent() { return parent_; }

QString ConfigTreeItem::name() const { return name_; }

ConfigTreeItem::Status ConfigTreeItem::status() const
{
  std::cout << name_.toStdString() << " " << StatusToStr(status_).toStdString()
            << std::endl;
  return status_;
}

QVariant ConfigTreeItem::icon() const { return StatusToIcon(status_); }

void ConfigTreeItem::setStatus(const ConfigTreeItem::Status& status)
{
  status_ = status;
}

void ConfigTreeItem::setParent(ConfigTreeItem* parent) { parent_ = parent; }

void ConfigTreeItem::activate() {}

void ConfigTreeItem::displayWidget(QWidget* /*widget*/) {}

QVector<ConfigTreeItem*> ConfigTreeItem::items() { return childItems_; }

void ConfigTreeItem::print()
{
  std::cout << name().toStdString() << std::endl;
  for (auto* item : items())
  {
    item->print();
  }
}
