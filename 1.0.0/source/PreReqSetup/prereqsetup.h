#ifndef PREREQSETUP_H
#define PREREQSETUP_H

#include <QDialog>

namespace Ui {
class PreReqSetup;
}

class PreReqSetup : public QDialog
{
    Q_OBJECT
    
public:
    explicit PreReqSetup(QWidget *parent = 0);
    ~PreReqSetup();
    
private:
    Ui::PreReqSetup *ui;
};

#endif // PREREQSETUP_H
