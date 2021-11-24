#include <QApplication>
#include <QCommandLineOption>
#include <QCommandLineParser>

#include "MainWindow.h"

int main(int argc, char *argv[])
{
  Q_INIT_RESOURCE(application);

  QApplication app(argc, argv);

  QCoreApplication::setOrganizationName("Simon");
  QCoreApplication::setApplicationName("Sandbox");
  QCoreApplication::setApplicationVersion("0.1.0");

  QCommandLineParser parser;
  parser.setApplicationDescription(QCoreApplication::applicationName());
  parser.addHelpOption();
  parser.addVersionOption();
  parser.process(app);

  MainWindow mainWindow;
  mainWindow.show();

  return app.exec();
}
