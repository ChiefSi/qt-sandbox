#ifndef CONFIGTREEITEMDELEGATE_H
#define CONFIGTREEITEMDELEGATE_H

#include <QStyledItemDelegate>

class ConfigTreeModel;

class ConfigTreeItemDelegate : public QStyledItemDelegate
{
public:
  ConfigTreeItemDelegate(ConfigTreeModel* model = nullptr);

  void paint(QPainter* painter, const QStyleOptionViewItem& option,
             const QModelIndex& index) const override;
  QSize sizeHint(const QStyleOptionViewItem& option,
                 const QModelIndex& index) const override;

  ConfigTreeModel* model_;
};

#endif  // CONFIGTREEITEMDELEGATE_H
