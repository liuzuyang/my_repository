#include "mainwindow.h"
#include <QtWidgets>
#include <memory>
#include <QDebug>

int main(int argc, char *argv[])
{
  QApplication a{argc, argv};
  QWidget w;
  w.resize(400, 300);
  w.move(200, 100);
  w.show();
  auto x = w.x();
  auto y = w.y();
  QRect rec = w.geometry();
  QRect frame = w.frameGeometry();
  qDebug() << "pos: " << w.pos() << endl
           << "rec: " << w.rect() << endl
           << "size: " << w.size() << endl
           << "width: " << w.width() << endl
           << "height: " << w.height() << endl;

  return a.exec();
}
