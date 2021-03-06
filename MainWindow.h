#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAction>
#include <QMainWindow>
#include <QStackedWidget>
#include <QTreeView>

#include "ConfigSetupSettings.h"
#include "ConfigTreeModel.h"
#include "Configuration.h"

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget* parent = 0);
  ~MainWindow();

  int registerWidget(QWidget* widget);
  void displayWidget(QWidget* widget);

protected:
  // Intercept close to offer save
  void closeEvent(QCloseEvent* event) override;

  // Buttons/Menu items
private slots:
  void newConfiguration();
  void openConfiguration();
  bool saveConfiguration();
  void about();

private:
  void createActions();
  void createStatusBar();
  void createCentralWidget();
  void createDockWindows();
  void createTreeDock();

  void populateConfiguration(const ConfigSetupSettings& settings);

  void readSettings();
  void writeSettings();

  bool maybeSave();
  void loadFile(const QString& fileName);
  bool saveFile(const QString& fileName);

  QTreeView* tree();

  void createExampleConfigTree();

private:
  QTreeView tree_;
  ConfigSetupSettings configSetupSettings_;
  Configuration configuration_;
  QMenu* viewMenu_;
  ConfigTreeModel configTreeModel_;
  QStackedWidget* stack_;
};

#endif  // MAINWINDOW_H
