#include "Ipv4SettingsPage.h"
#include "ui_Ipv4SettingsPage.h"

#include <iostream>
#include <QStandardItem>
#include <QPushButton>
#include "DnsItemDelegate.h"

Ipv4SettingsPage::Ipv4SettingsPage(QWidget *parent) :
  ConfigPage("Ipv4", parent),
  ui(new Ui::Ipv4SettingsPage)
{
  ui->setupUi(this);
//  dnsDataModel_.setTableView(ui->dnsTableView);
//  connect(&dnsDataModel_, &DnsDataModel::dnsDataChanged, [&](){ redrawTableView(ui->dnsTableView); });

  ui->dnsTableView->setModel(&dnsDataModel_);

  setMinimalTableView(ui->addressesTableView);
  setMinimalTableView(ui->dnsTableView);
  setMinimalTableView(ui->routesTableView);

  dnsDataModel_.setTableView(ui->dnsTableView);
}

Ipv4SettingsPage::~Ipv4SettingsPage()
{
  delete ui;
}

void Ipv4SettingsPage::on_methodAutomatic_clicked()
{
    std::cout << __func__ << std::endl;
}

void Ipv4SettingsPage::on_methodManual_clicked()
{
    std::cout << __func__ << std::endl;
}

void Ipv4SettingsPage::on_methodDisabled_clicked()
{
  std::cout << __func__ << std::endl;
}

void Ipv4SettingsPage::redrawTableView(QTableView* view)
{
  // Shrink to fit new data
  view->resizeColumnsToContents();
  view->resizeRowsToContents();

  // Minimum size should enclose the margin and header row
  int height = view->horizontalHeader()->height();
  height += view->contentsMargins().top();
  height += view->contentsMargins().bottom();

  // Including any row data
  if (view->model() != nullptr)
    for (int row = 0; row < view->model()->rowCount(); ++row)
      height += view->rowHeight(row);

  view->setMinimumHeight(height);
  view->setMaximumHeight(height);
}

void Ipv4SettingsPage::setMinimalTableView(QTableView* view)
{
  // Disable tab navigation within the table. Allows keyboard-only users to
  // tab to other widgets with arrow keys to navigate within the table
  view->setTabKeyNavigation(false);

  // Minimal table views should be small enough to have fixed width without
  // scrollbars
  QSizePolicy policy(QSizePolicy::Expanding, QSizePolicy::Fixed);
  view->setSizePolicy(policy);
  view->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

  // Disable the grid so it can be handled by the assigned item delegate
  // Disable the row numbers
  view->verticalHeader()->setVisible(false);
  view->setShowGrid(false);

  // Ensure the tableview contents resize appropriately
  view->verticalHeader()->setStretchLastSection(false);
  view->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
  view->horizontalHeader()->setStretchLastSection(false);
  view->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

  // Format the header
  view->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
  view->horizontalHeader()->setSectionsClickable(false);

  // Disable grid in header
  QString style = R"( QHeaderView::section {
                          border: 0px solid black;
                          border-bottom: 0px;
                          background-color: white; padding-left: 1em; padding-right: 1em;
                      }
                      QHeaderView {
                          border: 0px; background-color: white;
                      }
                  )";
  view->horizontalHeader()->setStyleSheet(style);

  // Set the fixed size based on content
  //redrawTableView(view);
}
