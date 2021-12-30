#pragma once

#include "ConfigTreeItem.h"

#include <QStackedWidget>

class ConfigSection : public QWidget, public ConfigTreeItem
{
	Q_OBJECT

public:
	explicit ConfigSection(const QString& name, QWidget* parent = nullptr);
	~ConfigSection() override = default;

	void activate() override;
	void displayWidget(QWidget* widget) override;

private:
	QStackedWidget* stack_;
};
