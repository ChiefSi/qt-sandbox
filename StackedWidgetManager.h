#pragma once

#include <QMap>
#include <QWidget>
#include <QStackedLayout>

class StackedWidgetManager
{
public:
	StackedWidgetManager();
	virtual ~StackedWidgetManager();

	void display(QWidget* widget);

	QStackedLayout* stackedLayout();

private:
	int registerWidget(QWidget* widget);

	QStackedLayout* stackedLayout_;
	QMap<QWidget*, int> layoutMap_;
};
