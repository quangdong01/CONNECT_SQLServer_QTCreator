#ifndef NEW_H
#define NEW_H

#include <QMainWindow>
#include "mainwindow.h"
#include <QSql>
namespace Ui {
class New;
}

class New : public QMainWindow
{
    Q_OBJECT

public:
    explicit New(QWidget *parent = nullptr);
    ~New();

private:
    Ui::New *ui;
};

#endif // NEW_H
