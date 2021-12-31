#ifndef IPV4SETTINGSPAGE_H
#define IPV4SETTINGSPAGE_H

#include <QPushButton>
#include <QStandardItemModel>
#include <QTableView>
#include <QWidget>

#include "ConfigPage.h"
#include "DnsDataModel.h"

namespace Ui
{
class Ipv4SettingsPage;
}

class Ipv4SettingsPage : public ConfigPage
{
  Q_OBJECT

public:
  explicit Ipv4SettingsPage(QWidget* parent = 0);
  ~Ipv4SettingsPage();

private slots:
  void on_methodAutomatic_clicked();

  void on_methodManual_clicked();

  void on_methodDisabled_clicked();

private:
  void redrawTableView(QTableView* view);
  void setMinimalTableView(QTableView* view);

  Ui::Ipv4SettingsPage* ui;
  DnsDataModel dnsDataModel_;
};

#endif  // IPV4SETTINGSPAGE_H
