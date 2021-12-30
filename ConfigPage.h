#pragma once

#include <QWidget>

#include "ConfigTreeItem.h"

class ConfigPage : public QWidget, public ConfigTreeItem
{
	Q_OBJECT

public:
	ConfigPage(const QString& name, QWidget* parent = nullptr);
	~ConfigPage() override = default;

	void activate() override;
};
