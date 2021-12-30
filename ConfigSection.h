#pragma once

#include "ConfigPage.h"
#include "StackedWidgetManager.h"

class ConfigSection : public ConfigPage
{
public:
	ConfigSection(const QString& name, QWidget* parent = nullptr);
	~ConfigSection() override = default;

	void displayWidget(QWidget* widget) override;

private:
	StackedWidgetManager widgetManager_;	
};
