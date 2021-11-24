#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <QString>

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow();

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

  void readSettings();
  void writeSettings();

  bool maybeSave();
  void loadFile(const QString &fileName);
  bool saveFile(const QString &fileName);
};

#endif
