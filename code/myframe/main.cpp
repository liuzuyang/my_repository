#include "mywidget.h"
#include <QApplication>
#include <QFrame>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  QFrame frame;
  frame.resize(400, 500);
  frame.setFrameShape(QFrame::Shape::Box);
  frame.setFrameShadow(QFrame::Shadow::Plain);
  frame.show();
  MyWidget w;
  w.show();

  return a.exec();
}
