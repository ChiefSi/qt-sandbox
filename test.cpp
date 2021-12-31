#include <QApplication>
#include <QtWidgets>

int main(int argc, char* argv[])
{
  Q_INIT_RESOURCE(application);

  QApplication app(argc, argv);

  QWidget widget;

  auto* s = new QStackedWidget(&widget);

  auto* n1 = new QStackedWidget();
  s->addWidget(n1);

  auto* button1 = new QPushButton("H");
  auto* button2 = new QPushButton("Hello there");

  n1->addWidget(button1);
  n1->addWidget(button2);

  widget.show();

  return app.exec();
}
