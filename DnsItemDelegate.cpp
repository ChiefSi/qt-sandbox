#include "DnsItemDelegate.h"

#include <QPainter>
#include <QPen>
#include <QTableView>
#include <iostream>
DnsItemDelegate::DnsItemDelegate(QAbstractTableModel* model)
  : QStyledItemDelegate(model)
  , model_(model)
{
}

void DnsItemDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{

  // Draw default painter background grid in all columns except last
  if (index.column() != model_->columnCount() - 1)
  {
    // Create a pen set to the background brush and draw the grid
    QPen pen = painter->pen();
    pen.setBrush(option.palette.background());
    painter->setPen(pen);

    painter->drawLine(option.rect.topRight(), option.rect.bottomRight());
    painter->drawLine(option.rect.bottomLeft(), option.rect.bottomRight());
  }

  // Render as normal assuming no visible grid
  QStyledItemDelegate::paint(painter, option, index);

}
