#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QtWidgets>

#include "ConfigSetupDialog.h"

#include <iostream>

#include "Ipv4SettingsPage.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui_(new Ui::MainWindow)
{
  // Ui should not be needed
    ui_->setupUi(this);

    // Setup page programatically rather than rely on content "hidden" in the UI xml
    createActions();
    createStatusBar();

    // Settings should only need to apply to this top-level representation of the application
    readSettings();

    createCentralWidget();
    createDockWindows();
}

void MainWindow::createDockWindows()
{
  createTreeDock();
}

void MainWindow::createTreeDock()
{
  QDockWidget* treeWindow = new QDockWidget("Configuration");
  treeWindow->setWidget(tree());
  addDockWidget(Qt::LeftDockWidgetArea, treeWindow);
  viewMenu_->addAction(treeWindow->toggleViewAction());
}

void MainWindow::populateConfiguration(const ConfigSetupSettings& settings)
{
  // TODO populate tree
  for (int i = 0; i < settings.numHighServers; ++i)
  {
    std::string serverName("High Server " + std::to_string(i));

    ServerSettings serverSettings;
    for (int j = 0; j < settings.numHighInterfaces; ++j)
    {
      std::string interfaceName("Interface " + std::to_string(j));
      InterfaceSettings interfaceSettings;
      serverSettings.interfaceMap[interfaceName] = interfaceSettings;
    }

    configuration_.highServerMap[serverName] = serverSettings;
  }

  for (int i = 0; i < settings.numLowServers; ++i)
  {
    std::string serverName("Low Server " + std::to_string(i));

    ServerSettings serverSettings;
    for (int j = 0; j < settings.numLowInterfaces; ++j)
    {
      std::string interfaceName("Interface " + std::to_string(j));
      InterfaceSettings interfaceSettings;
      serverSettings.interfaceMap[interfaceName] = interfaceSettings;
    }

    configuration_.lowServerMap[serverName] = serverSettings;
  }
}

void MainWindow::createCentralWidget()
{
  setCentralWidget(new Ipv4SettingsPage);
}


MainWindow::~MainWindow()
{
    delete ui_;
}

void MainWindow::closeEvent(QCloseEvent *event)
{
  if (maybeSave())
  {
    writeSettings();
    event->accept();
  }
  else
  {
    event->ignore();
  }
}

void MainWindow::newConfiguration()
{
  // TODO check if save requried... probably requires iterating and checking
  // internal struct vs current referenced file?
  ConfigSetupDialog dialog;
  if (dialog.exec() == QDialog::Accepted)
  {
    configSetupSettings_ = dialog.settings();

    std::cout << configSetupSettings_ << std::endl;

    populateConfiguration(configSetupSettings_);
  }
}

void MainWindow::openConfiguration()
{
  if (maybeSave())
  {
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty()) loadFile(fileName);
  }
}

bool MainWindow::saveConfiguration()
{
  QFileDialog dialog(this);
  dialog.setWindowModality(Qt::WindowModal);
  dialog.setAcceptMode(QFileDialog::AcceptSave);
  if (dialog.exec() != QDialog::Accepted) return false;
  return saveFile(dialog.selectedFiles().first());
}

void MainWindow::about()
{
  QMessageBox::about(this, tr("About"), tr("Put some stuff in here"));
}

void MainWindow::createActions()
{
  QMenu *fileMenu = menuBar()->addMenu(tr("&File"));
  QToolBar *fileToolBar = addToolBar(tr("File"));
  //const QIcon newIcon = QIcon::fromTheme("document-new", QIcon(":/images/new.png"));
  const QIcon newIcon = QIcon::fromTheme("document-new");
  //const QIcon newIcon = this->style()->standardIcon(QStyle::SP_FileDialogNewFolder);
  QAction *newAct = new QAction(newIcon, tr("&New"), this);
  newAct->setShortcuts(QKeySequence::New);
  newAct->setStatusTip(tr("New Configuration"));
  connect(newAct, &QAction::triggered, this, &MainWindow::newConfiguration);
  fileMenu->addAction(newAct);
  fileToolBar->addAction(newAct);

  //const QIcon openIcon = QIcon::fromTheme("document-open", QIcon(":/images/open.png"));
  const QIcon openIcon = QIcon::fromTheme("document-open");
  //const QIcon openIcon = this->style()->standardIcon(QStyle::SP_DialogOpenButton);
  QAction *openAct = new QAction(openIcon, tr("&Open..."), this);
  openAct->setShortcuts(QKeySequence::Open);
  openAct->setStatusTip(tr("Open Configuration"));
  connect(openAct, &QAction::triggered, this, &MainWindow::openConfiguration);
  fileMenu->addAction(openAct);
  fileToolBar->addAction(openAct);

  //const QIcon saveIcon = QIcon::fromTheme("document-save", QIcon(":/images/save.png"));
  const QIcon saveIcon = QIcon::fromTheme("document-save");
  //const QIcon saveIcon = this->style()->standardIcon(QStyle::SP_DialogSaveButton);
  QAction *saveAct = new QAction(saveIcon, tr("&Save"), this);
  saveAct->setShortcuts(QKeySequence::Save);
  saveAct->setStatusTip(tr("Save the document to disk"));
  connect(saveAct, &QAction::triggered, this, &MainWindow::saveConfiguration);
  fileMenu->addAction(saveAct);
  fileToolBar->addAction(saveAct);

  fileMenu->addSeparator();

  const QIcon exitIcon = QIcon::fromTheme("application-exit");
  QAction *exitAct =
      fileMenu->addAction(exitIcon, tr("E&xit"), this, &QWidget::close);
  exitAct->setShortcuts(QKeySequence::Quit);
  exitAct->setStatusTip(tr("Exit the application"));

  viewMenu_ = menuBar()->addMenu(tr("&View"));

  QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));
  QAction *aboutAct =
      helpMenu->addAction(tr("&About"), this, &MainWindow::about);
  aboutAct->setStatusTip(tr("Show the application's About box"));

  QAction *aboutQtAct =
      helpMenu->addAction(tr("About &Qt"), qApp, &QApplication::aboutQt);
  aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
}

void MainWindow::createStatusBar() { statusBar()->showMessage(tr("Ready")); }

void MainWindow::readSettings()
{
  QSettings settings(QCoreApplication::organizationName(),
                     QCoreApplication::applicationName());
  const QByteArray geometry =
      settings.value("geometry", QByteArray()).toByteArray();
  if (geometry.isEmpty())
  {
    const QRect availableGeometry =
        QApplication::desktop()->availableGeometry(this);
    resize(availableGeometry.width() / 3, availableGeometry.height() / 2);
    move((availableGeometry.width() - width()) / 2,
         (availableGeometry.height() - height()) / 2);
  }
  else
  {
    restoreGeometry(geometry);
  }
}

void MainWindow::writeSettings()
{
  QSettings settings(QCoreApplication::organizationName(),
                     QCoreApplication::applicationName());
  settings.setValue("geometry", saveGeometry());
}

bool MainWindow::maybeSave()
{
    /*
  const QMessageBox::StandardButton ret = QMessageBox::warning(
      this, tr("Application"),
      tr("TODO Check if unsaved modifications...\nDo you want to save your "
         "changes?"),
      QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
  switch (ret)
  {
    case QMessageBox::Save:
      return saveConfiguration();
    case QMessageBox::Cancel:
      return false;
    default:
      break;
  }

  return true;
  */
    return true;
}

void MainWindow::loadFile(const QString &fileName)
{
  QFile file(fileName);
  if (!file.open(QFile::ReadOnly | QFile::Text))
  {
    QMessageBox::warning(
        this, tr("Application"),
        tr("Cannot read file %1:\n%2.")
            .arg(QDir::toNativeSeparators(fileName), file.errorString()));
    return;
  }

#ifndef QT_NO_CURSOR
  QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
  // Load actions
#ifndef QT_NO_CURSOR
  QApplication::restoreOverrideCursor();
#endif

  statusBar()->showMessage(tr("File loaded"), 2000);
}

bool MainWindow::saveFile(const QString &fileName)
{
  QFile file(fileName);
  if (!file.open(QFile::WriteOnly | QFile::Text))
  {
    QMessageBox::warning(
        this, tr("Application"),
        tr("Cannot write file %1:\n%2.")
            .arg(QDir::toNativeSeparators(fileName), file.errorString()));
    return false;
  }

#ifndef QT_NO_CURSOR
  QApplication::setOverrideCursor(Qt::WaitCursor);
#endif
  // Save actions
#ifndef QT_NO_CURSOR
  QApplication::restoreOverrideCursor();
#endif

  statusBar()->showMessage(tr("File saved"), 2000);
  return true;
}

QTreeWidget* MainWindow::tree()
{
  return &tree_;
}
