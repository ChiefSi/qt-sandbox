#ifndef ANOTHERPAGE_H
#define ANOTHERPAGE_H

#include <QWidget>

#include "ConfigPage.h"
namespace Ui
{
class AnotherPage;
}

class AnotherPage : public ConfigPage
{
  Q_OBJECT

public:
  explicit AnotherPage(QWidget *parent = 0);
  ~AnotherPage();

private:
  Ui::AnotherPage *ui;
};

#endif  // ANOTHERPAGE_H
