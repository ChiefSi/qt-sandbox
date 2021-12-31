#include "ExamplePage.h"

#include "ui_ExamplePage.h"

ExamplePage::ExamplePage(QWidget *parent)
    : ConfigPage("ICA", parent), ui(new Ui::ExamplePage)
{
  ui->setupUi(this);
}

ExamplePage::~ExamplePage() { delete ui; }
