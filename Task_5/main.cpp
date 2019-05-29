#include "graphic.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Graphic w;
    w.resize(720, 480);
    w.show();

    return a.exec();
}
