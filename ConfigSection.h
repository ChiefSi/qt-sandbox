#pragma once

#include "ConfigTreeItem.h"

#include <QStackedWidget>

class ConfigSection : public ConfigTreeItem
{
public:
	explicit ConfigSection(const QString& name);
	~ConfigSection() override = default;

	void activate() override;
	void displayWidget(QWidget* widget) override;

private:
	QStackedWidget* stack_;
};
