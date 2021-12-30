#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeView>
#include <QAction>
#include <QStackedLayout>

#include "ConfigSetupSettings.h"
#include "Configuration.h"
#include "ConfigTreeModel.h"
#include "StackedWidgetManager.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

	int registerWidget(QWidget* widget);
	void displayWidget(QWidget* widget);

protected:
  // Intercept close to offer save
  void closeEvent(QCloseEvent *event) override;

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
  void loadFile(const QString &fileName);
  bool saveFile(const QString &fileName);

  QTreeView* tree();

  void createExampleConfigTree();

private:
    QTreeView tree_;
    ConfigSetupSettings configSetupSettings_;
    Configuration configuration_;
    QMenu* viewMenu_;
	ConfigTreeModel configTreeModel_;
	StackedWidgetManager widgetManager_;
};

#endif // MAINWINDOW_H
