#include "ConfigTreeItemDelegate.h"

#include <QPainter>
#include <QPen>
#include <QTableView>
#include <iostream>

#include "ConfigTreeModel.h"

ConfigTreeItemDelegate::ConfigTreeItemDelegate(ConfigTreeModel* model)
    : QStyledItemDelegate(model), model_(model)
{
}

QSize ConfigTreeItemDelegate::sizeHint(const QStyleOptionViewItem& option,
                                       const QModelIndex& index) const
{
  if (index.isValid())
  {
    ConfigTreeItem* item =
        static_cast<ConfigTreeItem*>(index.internalPointer());
    QString name = item->name();
    QIcon icon = item->icon();

    // Note use of tightBoundingRect is noted as very slow on windows...
    // QSize textSize = option.fontMetrics.tightBoundingRect(name).size();
    QSize textSize = option.fontMetrics.boundingRect(name).size();
    QSize iconSize = icon.actualSize(option.decorationSize);
    // Possible alternative to tightBoundingRect if too slow
    int textHeightEstimate =
        qMax(option.fontMetrics.ascent(), option.fontMetrics.descent());

    QSize hint(
        textSize.width() + 4 + iconSize.width(),
        //			qMax(textSize.height(), iconSize.height()));
        qMax(textHeightEstimate, iconSize.height()));

    return textSize + iconSize;
  }
  else
  {
    return QStyledItemDelegate::sizeHint(option, index);
  }
}

void ConfigTreeItemDelegate::paint(QPainter* painter,
                                   const QStyleOptionViewItem& option,
                                   const QModelIndex& index) const
{
  // if (index.isValid())
  //{
  painter->save();

  ConfigTreeItem* item = static_cast<ConfigTreeItem*>(index.internalPointer());
  QString name = item->name();
  QIcon icon = item->icon();

  QStyleOptionViewItem styleOption(option);
  initStyleOption(&styleOption, index);

  QStyle* style = styleOption.widget->style();
  style->drawPrimitive(QStyle::PE_PanelItemViewItem, &styleOption, painter,
                       styleOption.widget);

  if (option.state & QStyle::State_Selected)
  {
    painter->setPen(QPen(option.palette.brush(QPalette::HighlightedText), 0));
  }

  /*
  QRect alignedRect = QStyle::alignedRect(styleOption.direction,
  Qt::AlignHCenter | Qt::AlignLeft, option.rect.size(), option.rect);
  styleOption.icon.paint(painter, alignedRect);
  */
  int height = option.fontMetrics.lineSpacing();
  QRect textRect(option.rect.left(), option.rect.bottom() - height,
                 option.rect.width(), height);

  painter->drawText(textRect, Qt::AlignVCenter | Qt::AlignLeft, name);

  // QColor subTextColor = painter->pen().color();
  // subTextColor.setAlphaF(0.5);

  painter->restore();
  /*
  }
  else
  {
// Render as normal regardless of index
QStyledItemDelegate::paint(painter, option, index);
  }
  */
}
