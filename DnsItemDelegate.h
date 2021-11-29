#ifndef DNSITEMDELEGATE_H
#define DNSITEMDELEGATE_H

#include <QStyledItemDelegate>
#include <QTableView>
#include <QAbstractTableModel>
class DnsItemDelegate : public QStyledItemDelegate
{
public:
  DnsItemDelegate(QAbstractTableModel* model = nullptr);

  void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override;

  QAbstractTableModel* model_;
};

#endif // DNSITEMDELEGATE_H
