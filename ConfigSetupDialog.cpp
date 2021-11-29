#include "ConfigSetupDialog.h"
#include "ui_ConfigSetupDialog.h"

#include <iostream>

ConfigSetupDialog::ConfigSetupDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::ConfigSetupDialog)
{
  ui->setupUi(this);
}

ConfigSetupDialog::~ConfigSetupDialog()
{
  delete ui;
}

ConfigSetupSettings& ConfigSetupDialog::settings()
{
  std::cout << __func__ << std::endl;
  return settings_;
}

void ConfigSetupDialog::on_buttonBox_accepted()
{
  std::cout << __func__ << std::endl;

  settings_.numHighServers = ui->numHighServers->value();
  settings_.numHighInterfaces = ui->numHighInterfaces->value();
  settings_.numLowServers = ui->numLowServers->value();
  settings_.numLowInterfaces = ui->numLowInterfaces->value();
}

void ConfigSetupDialog::on_buttonBox_rejected()
{
  std::cout << __func__ << std::endl;
}
