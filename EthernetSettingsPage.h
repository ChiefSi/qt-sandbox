#ifndef ETHERNETSETTINGSPAGE_H
#define ETHERNETSETTINGSPAGE_H

#include <QWidget>

#include "ConfigPage.h"
namespace Ui
{
class EthernetSettingsPage;
}

class EthernetSettingsPage : public ConfigPage
{
  Q_OBJECT

public:
  explicit EthernetSettingsPage(QWidget *parent = 0);
  ~EthernetSettingsPage();

private:
  Ui::EthernetSettingsPage *ui;
};

#endif  // ETHERNETSETTINGSPAGE_H
