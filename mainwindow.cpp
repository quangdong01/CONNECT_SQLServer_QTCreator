#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QSqlQueryModel>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mDbConnection("(local)",
                    "SQL SERVER",
                    "admin",
                    "",
                    "KTPMUD",
                    true)
{
    ui->setupUi(this);
    mModel = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionConnect_Sql_Server_2019_triggered()
{
    QString error;
    if(!mDbConnection.openDatabase(&error))
    {
        QMessageBox::critical(this, "Error", error);
        return;
    }
    if(mModel == nullptr)
    {
        mModel = new QSqlQueryModel(this);
        mModel->setQuery("SELECT * FROM Customers");
        ui->tableView->setModel(mModel);
    }
    else
    {
        mModel->setQuery("SELECT * FROM Customers");
    }
}

void MainWindow::on_actionInformation_of_Student_triggered()
{
    close();
}


void MainWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this, "About QT");
}

