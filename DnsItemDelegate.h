#ifndef DNSITEMDELEGATE_H
#define DNSITEMDELEGATE_H

#include <QAbstractTableModel>
#include <QStyledItemDelegate>
#include <QTableView>
class DnsItemDelegate : public QStyledItemDelegate
{
public:
  DnsItemDelegate(QAbstractTableModel* model = nullptr);

  void paint(QPainter* painter, const QStyleOptionViewItem& option,
             const QModelIndex& index) const override;

  QAbstractTableModel* model_;
};

#endif  // DNSITEMDELEGATE_H
