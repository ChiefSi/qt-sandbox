#ifndef DNSDATAMODEL_H
#define DNSDATAMODEL_H

#include <QAbstractTableModel>
#include <QTableView>
#include <string>

#include "DnsItemDelegate.h"
class DnsDataModel : public QAbstractTableModel
{
  Q_OBJECT
public:
  DnsDataModel(QObject* parent = nullptr);
  void setTableView(QTableView* tableView);

  int columnCount(const QModelIndex& parent = QModelIndex()) const override;
  int rowCount(const QModelIndex& parent = QModelIndex()) const override;

  QVariant data(const QModelIndex& index,
                int role = Qt::DisplayRole) const override;
  QVariant headerData(int section, Qt::Orientation orientation,
                      int role) const override;

  Qt::ItemFlags flags(const QModelIndex& index) const override;
  bool setData(const QModelIndex& index, const QVariant& value,
               int role = Qt::EditRole) override;

signals:
  void dnsDataChanged();

private:
  void appendServer(const QString& server, int row);
  void removeServer(int row);

  void redrawView();

  QVariant getDisplayData(const QModelIndex& index) const;
  bool setServer(const QString& server, int row);

  QTableView* tableView_;
  QList<QString> servers_;
  DnsItemDelegate delegate_;
};

#endif  // DNSDATAMODEL_H
