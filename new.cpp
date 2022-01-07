#include "new.h"
#include "ui_new.h"

New::New(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::New)
{
    ui->setupUi(this);
}

New::~New()
{
    delete ui;
}
