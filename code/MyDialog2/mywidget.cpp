#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDebug>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QProgressDialog>
#include <QFrame>

MyWidget::MyWidget(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::MyWidget),
  errordlg(new QErrorMessage(this))
{
  ui->setupUi(this);
}

MyWidget::~MyWidget()
{
  delete ui;
}

void MyWidget::on_pushButton_clicked()
{
  QColorDialog dialog(Qt::red, this);
  dialog.setOption(QColorDialog::ShowAlphaChannel);
  dialog.exec();
  QColor color(dialog.currentColor());
  qDebug() << "color: " << color;
}

void MyWidget::on_pushButton_2_clicked()
{
  QString filename{QFileDialog::getOpenFileName(this, tr("文件对话框"), QString("/Users/apple"), tr("图片文件(*png)"))};
  qDebug() << "filename: " << filename;
}

void MyWidget::on_pushButton_3_clicked()
{
  bool ok;
  QFont font{QFontDialog::getFont(&ok, this)};
  if(ok)
    {
      ui->pushButton_3->setFont(font);
    }
  else
    {
      qDebug() << tr("没有选择任字体") << endl;
    }
}

void MyWidget::on_pushButton_4_clicked()
{
  bool ok{false};
  QString string{QInputDialog::getText(this, tr("输入对话框")
         , tr("用户名:"), QLineEdit::Normal, tr("admin"), &ok)};
  if (ok)
    {
      qDebug() << "string: " << string << endl;
    }
  int value{QInputDialog::getInt(this, tr("数值对话框"),
          tr("请输入10 - 20之间的数: "), 10, 10, 20, 1, &ok)};
  if (ok)
    {
      qDebug() << "value: " << value << endl;
    }
  double dbvalue{QInputDialog::getDouble(this, tr("双精度浮点数输入框"),
         tr("请输入任意实数: "), 0.0, 0.0, 100000, 2, &ok)};
  if(ok)
    {
      qDebug() << "dbvalue: " << dbvalue << endl;
    }
  QStringList items;
  items << tr("条目1") << tr("条目2");

  QString item{QInputDialog::getItem(this, tr("输入条目对话框"), tr("请输入一条条目: "), items, 0, true, &ok)};
  if (ok)
    {
      qDebug() << "item: " << item << endl;
    }
}

void MyWidget::on_pushButton_5_clicked()
{
  int ret1{QMessageBox::question(this, tr("问题对话框"),
          tr("你了解Qtme?"), QMessageBox::Yes, QMessageBox::No)};
  if (ret1 == QMessageBox::Yes)
    {
      qDebug() << tr("问题") << endl;
    }
  int ret2{QMessageBox::information(this, tr("提示消息对话框"), tr("这是一本书"), QMessageBox::Ok)};
  if (ret2 == QMessageBox::Ok)
    {
      qDebug() << tr("提示!") << endl;
    }
  int ret3{QMessageBox::warning(this, tr("警告框"), tr("一些警告内容"), QMessageBox::Abort)};
  if (ret3 == QMessageBox::Abort)
    {
      qDebug() << tr("警告!") << endl;
    }
}

void MyWidget::on_pushButton_6_clicked()
{
  QProgressDialog dialog(tr("复制对话框"), tr("取消"), 0, 50000, this);
  dialog.setWindowTitle(tr("进度对话框"));
  dialog.setWindowModality(Qt::WindowModal);
  dialog.show();
  for (int i{0}; i < 50000; ++i)
    {
      dialog.setValue(i);
      QCoreApplication::processEvents();
      if(dialog.wasCanceled())
        {
          break;
        }
    }
  dialog.setValue(50000);
  qDebug() << "复制结束" << endl;
}

void MyWidget::on_pushButton_7_clicked()
{
   errordlg->setWindowTitle(tr("错误消息对话框"));
   errordlg->showMessage(tr("这里是错误消息"));
}

QWizardPage *MyWidget::createPage1()
{
  QWizardPage *page{new QWizardPage};
  page->setTitle(tr("介绍"));
  return page;
}

QWizardPage *MyWidget::createPage2()
{
  QWizardPage *page{new QWizardPage};
  page->setTitle(tr("用户选择信息"));
  return page;
}

QWizardPage *MyWidget::createPage3()
{
  QWizardPage *page{new QWizardPage};
  page->setTitle(tr("结束"));
  return page;
}
void MyWidget::on_pushButton_8_clicked()
{
  QWizard wizard(this);
  wizard.setWindowTitle(tr("向导对话框"));
  wizard.addPage(createPage1());
  wizard.addPage(createPage2());
  wizard.addPage(createPage3());
  wizard.exec();
}
