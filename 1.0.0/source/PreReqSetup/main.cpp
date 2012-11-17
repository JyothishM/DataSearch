#include <QtGui/QApplication>
#include "prereqsetup.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PreReqSetup w;
    w.show();
    
    return a.exec();
}
