#include <QtGui/QApplication>
#include "datasearchconfig.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DataSearchConfig w;
    w.show();

    return a.exec();
}
