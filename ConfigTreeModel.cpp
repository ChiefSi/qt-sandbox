#include "ConfigTreeModel.h"

#include "ConfigTreeRootItem.h"
#include "MainWindow.h"

ConfigTreeModel::ConfigTreeModel(MainWindow* mainWindow, QObject* parent)
    : QAbstractItemModel(parent)
{
  rootItem_ = new ConfigTreeRootItem("root", mainWindow);
}

ConfigTreeModel::~ConfigTreeModel() { delete rootItem_; }

QVariant ConfigTreeModel::data(const QModelIndex& index, int role) const
{
  if (!index.isValid()) return QVariant();

  ConfigTreeItem* item = static_cast<ConfigTreeItem*>(index.internalPointer());

  int column = index.column();

  if (role == Qt::DisplayRole)
  {
    return item->data(index.column());
  }

  if (role == Qt::DecorationRole)
  {
    auto icon = item->icon();
    return icon;
  }

  return QVariant();
}

Qt::ItemFlags ConfigTreeModel::flags(const QModelIndex& index) const
{
  if (!index.isValid()) return Qt::NoItemFlags;

  return QAbstractItemModel::flags(index);
}

QVariant ConfigTreeModel::headerData(int section, Qt::Orientation orientation,
                                     int role) const
{
  // if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
  //	return rootItem_->data(section);

  return QVariant();
}

QModelIndex ConfigTreeModel::index(int row, int column,
                                   const QModelIndex& parent) const
{
  if (!hasIndex(row, column, parent)) return QModelIndex();

  ConfigTreeItem* parentItem;
  if (!parent.isValid())
    parentItem = rootItem_;
  else
    parentItem = static_cast<ConfigTreeItem*>(parent.internalPointer());

  ConfigTreeItem* childItem = parentItem->child(row);
  if (childItem) return createIndex(row, column, childItem);

  return QModelIndex();
}

QModelIndex ConfigTreeModel::parent(const QModelIndex& index) const
{
  if (!index.isValid()) return QModelIndex();

  ConfigTreeItem* childItem =
      static_cast<ConfigTreeItem*>(index.internalPointer());
  ConfigTreeItem* parentItem = childItem->parent();

  if (parentItem == rootItem_) return QModelIndex();

  return createIndex(parentItem->row(), 0, parentItem);
}

int ConfigTreeModel::rowCount(const QModelIndex& parent) const
{
  if (parent.column() > 0) return 0;

  ConfigTreeItem* parentItem;

  if (!parent.isValid())
    parentItem = rootItem_;
  else
    parentItem = static_cast<ConfigTreeItem*>(parent.internalPointer());

  return parentItem->childCount();
}

int ConfigTreeModel::columnCount(const QModelIndex& parent) const
{
  if (parent.isValid())
    return static_cast<ConfigTreeItem*>(parent.internalPointer())
        ->columnCount();

  return rootItem_->columnCount();
}

ConfigTreeItem* ConfigTreeModel::rootItem() { return rootItem_; }

QVector<ConfigTreeItem*> ConfigTreeModel::items() { return rootItem_->items(); }
