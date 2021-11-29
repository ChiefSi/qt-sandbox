#include "EthernetSettingsPage.h"
#include "ui_EthernetSettingsPage.h"

EthernetSettingsPage::EthernetSettingsPage(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::EthernetSettingsPage)
{
  ui->setupUi(this);
}

EthernetSettingsPage::~EthernetSettingsPage()
{
  delete ui;
}
