#include <QApplication>
#include <QDialog>
#include <QLabel>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  QDialog dia;
  QLabel lab(&dia);
  dia.resize(400, 400);
  dia.setWindowTitle(QObject::tr("dialog Title"));
  lab.resize(100, 20);
  lab.setText("liuzuyanog");
  dia.show();
  lab.show();

  return a.exec();
}
