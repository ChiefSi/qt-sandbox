#ifndef EXAMPLEPAGE_H
#define EXAMPLEPAGE_H

#include <QWidget>

#include "ConfigPage.h"
namespace Ui
{
class ExamplePage;
}

class ExamplePage : public ConfigPage
{
  Q_OBJECT

public:
  explicit ExamplePage(QWidget *parent = 0);
  ~ExamplePage();

private:
  Ui::ExamplePage *ui;
};

#endif  // EXAMPLEPAGE_H
