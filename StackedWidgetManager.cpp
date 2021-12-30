#include "StackedWidgetManager.h"

StackedWidgetManager::StackedWidgetManager()
	: stackedLayout_(new QStackedLayout())
{
}

void StackedWidgetManager::display(QWidget* widget)
{
	auto it = layoutMap_.find(widget);
	if (it == layoutMap_.end())
	{
		int index = registerWidget(widget);
		stackedLayout_->setCurrentIndex(index);
	}
	else
	{
		stackedLayout_->setCurrentIndex(*it);
	}
}

QStackedLayout* StackedWidgetManager::stackedLayout()
{
	return stackedLayout_;
}

int StackedWidgetManager::registerWidget(QWidget* widget)
{
	int index = stackedLayout_->addWidget(widget);
	layoutMap_.insert(widget, index);
	return index;
}
