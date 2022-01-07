#include <QApplication>
#include <QMainWindow>
#include <QTableView>
#include <QLineEdit>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDataWidgetMapper>
#include <QItemSelectionModel>
#include <QDebug>
#include <QItemDelegate>
#include <QPushButton>

#include "StructTableModel.h"

class EditDelegate : public QItemDelegate
{
public:
	void setEditorData(QWidget * editor, const QModelIndex & index) const override
	{
		int column = index.column();
		if (column == 0)
		{
			QLineEdit* edit = qobject_cast<QLineEdit*>(editor);
			qInfo() << edit->text() << index.data().toString();
			edit->setText(index.data().toString());
		}
		else if (column == 1)
		{
			QSpinBox* box = qobject_cast<QSpinBox*>(editor);
			qInfo() << box->value() << index.data().toInt();
			box->setValue(index.data().toInt());
		}
	}
};

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	QMainWindow w;

	auto* widget = new QWidget(&w);
	auto* layout = new QHBoxLayout(widget);

	auto* tableView = new QTableView();
	layout->addWidget(tableView);

	auto* inputLayout = new QVBoxLayout();
	auto* lineEdit = new QLineEdit();
	inputLayout->addWidget(lineEdit);
	auto* spinBox = new QSpinBox();
	inputLayout->addWidget(spinBox);

	layout->addLayout(inputLayout);

	w.setCentralWidget(widget);
	w.show();

	StructTable table { { "first", 1 }, { "second", 2} };
	StructTableModel model(table);

	tableView->setModel(&model);

	auto* mapper = new QDataWidgetMapper(widget);
	mapper->setModel(&model);
	mapper->addMapping(lineEdit, 0);
	mapper->addMapping(spinBox, 1);

	QObject::connect(tableView->selectionModel(), &QItemSelectionModel::currentRowChanged,
        mapper, &QDataWidgetMapper::setCurrentModelIndex);

	mapper->setItemDelegate(new EditDelegate);

	auto* button = new QPushButton("Submit");
	inputLayout->addWidget(button);

	QObject::connect(button, &QPushButton::clicked,
		[&, m = mapper](const bool checked)
		{
			qInfo() << "Button clicked";
			m->submit();
			for (auto entry : table)
			{
				qInfo() << entry.name << entry.value;
			}
		});

	qInfo() << "Hello there";

	app.exec();
}
