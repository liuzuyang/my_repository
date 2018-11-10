#include "mywidget.h"
#include "ui_mywidget.h"

MyWidget::MyWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::MyWidget)
{
  QFont  font;
  font.setFamily(tr("华文楷体"));
  font.setBold(true);
  font.setItalic(true);
  font.setPointSize(20);
  ui->setupUi(this);
}

MyWidget::~MyWidget()
{
  delete ui;
}
