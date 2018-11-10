#include <QApplication>
#include <QDialog>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QDialog w;
    w.resize(250, 250);
    QLabel lab(&w);
    lab.move(75, 125);
    lab.setText("dudongming chishi");
    w.show();
    return a.exec();
}
