#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "databaseconnection.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QSqlQueryModel;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionConnect_Sql_Server_2019_triggered();

    void on_actionInformation_of_Student_triggered();

    void on_actionAbout_Qt_triggered();

public:
    Ui::MainWindow *ui;
    DatabaseConnection mDbConnection;
    QSqlQueryModel *mModel;
};
#endif // MAINWINDOW_H
