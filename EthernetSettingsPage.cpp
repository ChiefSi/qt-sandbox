#include "EthernetSettingsPage.h"

#include "ui_EthernetSettingsPage.h"

EthernetSettingsPage::EthernetSettingsPage(QWidget *parent)
    : ConfigPage("Ethernet Settings", parent), ui(new Ui::EthernetSettingsPage)
{
  ui->setupUi(this);
}

EthernetSettingsPage::~EthernetSettingsPage() { delete ui; }
