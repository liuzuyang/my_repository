#include "mywidget.h"
#include "mydialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  MyWidget w;
  MyDialog mdia;
  if (mdia.exec() == QDialog::Accepted)
    {
      w.show();
      return a.exec();
    }
  else
    {
      return 0;
    }
}
