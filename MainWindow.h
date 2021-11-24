#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

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
  void createDockWindows();

  void readSettings();
  void writeSettings();

  bool maybeSave();
  void loadFile(const QString &fileName);
  bool saveFile(const QString &fileName);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
