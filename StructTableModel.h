#pragma once
#include <QString>
#include <QAbstractTableModel>

struct Entry
{
	QString name;
	int value;
};

using StructTable = QList<Entry>;


class StructTableModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	StructTableModel(StructTable& table, QObject* parent = nullptr);
	~StructTableModel() override = default;
	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	QVariant displayData(const int row, const int column) const;
	bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;

private:
	StructTable& table_;
};


