#include "StructTableModel.h"

#include <QDebug>

StructTableModel::StructTableModel(StructTable& table, QObject* parent) : QAbstractTableModel(parent), table_(table) {}

int StructTableModel::rowCount(const QModelIndex &parent) const
	{
		return table_.count();
	}

	int StructTableModel::columnCount(const QModelIndex &parent) const
	{
		return 2;
	}

	QVariant StructTableModel::data(const QModelIndex &index, int role) const
	{
		int row = index.row();
		int column = index.column();

		if (row >= rowCount() || column >= columnCount())
		{
			return {};
		}

		switch (role)
		{
			case Qt::EditRole: 
			case Qt::DisplayRole: return displayData(row, column);
			default: return {};
		}
	}

	QVariant StructTableModel::displayData(const int row, const int column) const
	{
		switch (column)
		{
			case 0: return table_[row].name;
			case 1: return table_[row].value;
			default: return {};
		}
	}

	bool StructTableModel::setData(const QModelIndex& index, const QVariant& value, int role)
	{
		int row = index.row();
		int column = index.column();

		if (row >= rowCount() || column >= columnCount() || role != Qt::EditRole)
		{
			return false;
		}

		switch (column)
		{
			case 0:
			{
				table_[row].name = value.toString();
				return true;
			}
			case 1:
			{
				table_[row].value = value.toInt();
				return true;
			}
			default: return false;
		}
	}
