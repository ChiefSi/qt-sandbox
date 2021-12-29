#pragma once

#include <QIcon>
#include <QVariant>
#include <QVector>
#include <QString>

class ConfigTreeItem
{
public:
	enum class Status
	{
		Ok,
		Warning,
		Error,
		Unknown
	};

	static inline QString StatusToStr(const Status& status)
	{
		switch (status)
		{
			case Status::Ok: return "Ok";
			case Status::Warning: return "Warning";
			case Status::Error: return "Error";
			default: return "Unknown";
		}
	}

	static inline QVariant StatusToIcon(const Status& status)
	{
		switch (status)
		{
			case Status::Ok: return QIcon::fromTheme("face-smile");
			case Status::Warning: return QIcon::fromTheme("dialog-warning");
			case Status::Error: return QIcon::fromTheme("dialog-error");
			default: return QVariant();
		}
	}

	explicit ConfigTreeItem(const QString& name, ConfigTreeItem* parent = nullptr);
	~ConfigTreeItem();

	void appendChild(ConfigTreeItem* item);

	ConfigTreeItem* child(int row);
	int childCount() const;
	int columnCount() const;
	QVariant data(int column) const;
	int row() const;
	ConfigTreeItem* parent();

	QString name() const;
	Status status() const;
	QVariant icon() const;

	void setStatus(const Status& status);

private:
	QVector<ConfigTreeItem*> childItems_;
	QString name_;
	Status status_;
	ConfigTreeItem* parent_;	
};
