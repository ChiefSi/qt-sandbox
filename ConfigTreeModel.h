#pragma once

#include <QAbstractItemModel>

#include "ConfigTreeItem.h"

class ConfigTreeModel : public QAbstractItemModel
{
	Q_OBJECT
public:
	explicit ConfigTreeModel(QObject* parent = nullptr);
	~ConfigTreeModel();

	QVariant data(const QModelIndex& index, int role) const override;
	Qt::ItemFlags flags(const QModelIndex& index) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
	QModelIndex index(int row, int column, const QModelIndex& parent = QModelIndex()) const override;
	QModelIndex parent(const QModelIndex& index) const override;
	int rowCount(const QModelIndex& parent = QModelIndex()) const override;
	int columnCount(const QModelIndex& parent = QModelIndex()) const override;

private:
	void setupModelData(ConfigTreeItem* parent);

	ConfigTreeItem* rootItem_;
};
