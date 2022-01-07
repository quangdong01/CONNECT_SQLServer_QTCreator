#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QString error;


    MainWindow w;
    if(w.mDbConnection.openDatabase(&error))
    {
        qDebug() << "Successfully !!";
    }

    QString query = "CREATE TABLE Students("
                    "ID int,"
                    "first_Name varchar(20),"
                    "last_Name varchar(20),"
                    "day_Of_Birth datetime,"
                    "address varchar(20));";
    // Day la chuan nay 
    // Khong phai nhu the dau 
    // Thoi nay nghi thoi chu met lam roi 
    
    QSqlQuery qry;
    if(!qry.exec(query))
    {
        qDebug() << "Not implement!!";
        qDebug() << qry.lastError();
    }
    w.show();
    return a.exec();
}
