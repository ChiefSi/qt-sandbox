#ifndef CONFIGSETUPDIALOG_H
#define CONFIGSETUPDIALOG_H

#include <QDialog>

#include "ConfigSetupSettings.h"

namespace Ui
{
class ConfigSetupDialog;
}

class ConfigSetupDialog : public QDialog
{
  Q_OBJECT

public:
  explicit ConfigSetupDialog(QWidget *parent = 0);
  ~ConfigSetupDialog();

  ConfigSetupSettings &settings();
private slots:
  void on_buttonBox_accepted();
  void on_buttonBox_rejected();

private:
  Ui::ConfigSetupDialog *ui;
  ConfigSetupSettings settings_;
};

#endif  // CONFIGSETUPDIALOG_H
