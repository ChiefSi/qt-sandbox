#include "DnsDataModel.h"

#include <QHeaderView>
#include <QIcon>
#include <QPushButton>
#include <iostream>

DnsDataModel::DnsDataModel(QObject* parent)
    : QAbstractTableModel(parent), tableView_(nullptr), delegate_(this)
{
  connect(this, &DnsDataModel::dnsDataChanged, this, &DnsDataModel::redrawView);
}

void DnsDataModel::setTableView(QTableView* tableView)
{
  tableView_ = tableView;
  tableView_->setItemDelegate(&delegate_);

  redrawView();
}

int DnsDataModel::columnCount(const QModelIndex& parent) const
{
  // Single data column and button to remove
  return 2;
}

int DnsDataModel::rowCount(const QModelIndex& parent) const
{
  // Always include the empty row for addition of new items
  return servers_.size() + 1;
}

QVariant DnsDataModel::data(const QModelIndex& index, int role) const
{
  switch (role)
  {
    case Qt::DisplayRole:
      return getDisplayData(index);
    default:
      return QVariant();
  }
}

QVariant DnsDataModel::headerData(int section, Qt::Orientation orientation,
                                  int role) const
{
  if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
  {
    if (section == 0)
    {
      return QString("Address");
    }
  }

  return QVariant();
}

Qt::ItemFlags DnsDataModel::flags(const QModelIndex& index) const
{
  // Only first column can be editable
  if (index.column() == 0)
  {
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
  }

  // Disable selection of button column
  if (index.column() == columnCount() - 1)
  {
    // Disable the last row item
    if (index.row() != rowCount() - 1)
    {
      return Qt::NoItemFlags | Qt::ItemIsEnabled;
    }
    else
    {
      return Qt::NoItemFlags;
    }
  }

  return QAbstractItemModel::flags(index);
}

bool DnsDataModel::setData(const QModelIndex& index, const QVariant& value,
                           int role)
{
  // Can only set data for first column
  if (role == Qt::EditRole && index.column() == 0)
  {
    return setServer(value.toString(), index.row());
  }

  return false;
}

void DnsDataModel::appendServer(const QString& server, int row)
{
  // Appending a server should insert the final, empty, row
  beginInsertRows(QModelIndex(), row + 1, row + 1);
  servers_.append(server);
  endInsertRows();

  emit dnsDataChanged();
}

void DnsDataModel::removeServer(int row)
{
  servers_.removeAt(row);

  beginRemoveRows(QModelIndex(), row, row);
  removeRow(row);
  endRemoveRows();

  // Reset focus into the table (presumably the now-removed button was
  // previously in focus)
  tableView_->setFocus();

  emit dnsDataChanged();
}

void DnsDataModel::redrawView()
{
  // For each row except the last1
  for (int row = 0; row < rowCount(); ++row)
  {
    // Remove the button if last row
    if (row == rowCount() - 1)
    {
      tableView_->setIndexWidget(index(row, columnCount() - 1), nullptr);
      continue;
    }

    // Create button with "close" icon
    QPushButton* removeButton = new QPushButton;
    removeButton->setIcon(QIcon::fromTheme("window-close"));

    connect(removeButton, &QPushButton::clicked,
            [&, r = row](const bool /*state*/) { removeServer(r); });
    // Assign button to cell
    tableView_->setIndexWidget(index(row, columnCount() - 1), removeButton);
  }

  // Shrink to fit new data
  tableView_->resizeColumnsToContents();
  tableView_->resizeRowsToContents();

  // Minimum size should enclose the margin and header row
  int height = tableView_->horizontalHeader()->height();
  height += tableView_->contentsMargins().top();
  height += tableView_->contentsMargins().bottom();

  // Including any row data
  if (tableView_->model() != nullptr)
    for (int row = 0; row < rowCount(); ++row)
    {
      if (row > 6) break;
      height += tableView_->rowHeight(row);
    }

  tableView_->setMinimumHeight(height);
  tableView_->setMaximumHeight(height);
}

QVariant DnsDataModel::getDisplayData(const QModelIndex& index) const
{
  if ((index.column() == 0) && (index.row() < servers_.size()))
  {
    return servers_.at(index.row());
  }

  return QVariant();
}

bool DnsDataModel::setServer(const QString& server, int row)
{
  // If first (and only) or final entry then append
  if (((row == 0) && (servers_.isEmpty())) || (row == servers_.size()))
  {
    if (!server.isEmpty())
    {
      appendServer(server, row);
    }

    return true;
  }

  // Otherwise update/remove existing entry
  if ((!servers_.isEmpty()) && (row < servers_.size()))
  {
    if (server.isEmpty())
    {
      removeServer(row);
    }
    else
    {
      servers_[row] = server;
    }
    emit dnsDataChanged();
    return true;
  }

  // Should not occur
  return false;
}
