#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QStringList>
#include <QHash>

namespace Ui {
class MainWindow;
}

class QLabel;
class QSqlTableModel;
class QModelIndex;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_btnLoginLogout_clicked();
    void on_btnSearch_clicked();
    void on_btnAllRecords_clicked();
    void on_searchTableView_doubleClicked(const QModelIndex &index);
    void on_actionAbout_triggered();
private:
    bool Init();
    bool Login(QString username,QString password);
    bool Logout();
    void UpdateTableUI();
    QString FindFilterStr();
    bool SetSearchVisible(bool visible);
    double ConvToDouble(QString str,QString errName="",bool* ok=0);
    QString GetType();
    QString GetPhaseType();

    Ui::MainWindow *ui;
    bool bLoginStatus;
    QLabel* mStatusLabel;
    QSqlDatabase mDataBase;
    QSqlTableModel *mTableModel;
    QStringList mVisibleCols;
    QHash<QString,QString> mConditionFields;

    QString mSQLdriverName;
    QString mHostName;
    QString mUserName;
    QString mDataBaseName;
    QString mTableName;
    QString mFilterStr;
};

#endif // MAINWINDOW_H
