#include "AnotherPage.h"

#include "ui_AnotherPage.h"

AnotherPage::AnotherPage(QWidget *parent)
    : ConfigPage("Sides", parent), ui(new Ui::AnotherPage)
{
  ui->setupUi(this);
}

AnotherPage::~AnotherPage() { delete ui; }
