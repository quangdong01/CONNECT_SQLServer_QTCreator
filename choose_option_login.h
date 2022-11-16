#ifndef CHOOSE_OPTION_LOGIN_H
#define CHOOSE_OPTION_LOGIN_H
#include <QTimer>
#include <QMainWindow>
#include "login.h"
#include "databaseconnection.h"
#include <QSqlQueryModel>
// variable to use other files
extern int option;


QT_BEGIN_NAMESPACE
namespace Ui { class choose_option_login; }
QT_END_NAMESPACE


class choose_option_login : public QMainWindow
{
    Q_OBJECT

public:
    choose_option_login(QWidget *parent = nullptr);
    ~choose_option_login();

private:
    Ui::choose_option_login *ui;

    // Create timer pointer to set time for app
    QTimer *timer;
    login *log;
    databaseConnection mDbConnection;
    QSqlQueryModel *mModel;


public slots:
    // slot to set time
    void my_function();
private slots:
    void on_checkBox_Human_stateChanged(int arg1);
    void on_btn_Next_clicked();
};
#endif // CHOOSE_OPTION_LOGIN_H
