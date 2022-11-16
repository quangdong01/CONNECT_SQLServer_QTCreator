#include "choose_option_login.h"
#include "ui_choose_option_login.h"
#include <QDateTime>
#include <QPixmap>
#include <QMessageBox>
#include <QSqlError>
#include <QDebug>

int option;


// Create Function
choose_option_login::choose_option_login(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::choose_option_login)
    , mDbConnection("(local)",
                    "SQL SERVER",
                    "qd",
                    "",
                    "BTL_KTPMUD",
                    true)
{
    ui->setupUi(this);
    mModel = nullptr;

    QString error;
    if(this->mDbConnection.openDatabase(&error))
    {
        qDebug() << "Connect to database successfully";
    }

    // Set up logo of Background
    QPixmap pix(":/other/other_image/s2.jpg");
    int w = ui->label_Background->width();
    int h = ui->label_Background->height();
    ui->label_Background->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));

    // Set up logo of Login
    QPixmap pix1(":/resource/resource/Person-Male-Light-icon-16.png");
    int w1 = ui->label_CheckLogin->width();
    int h1 = ui->label_CheckLogin->height();
    ui->label_CheckLogin->setPixmap(pix1.scaled(w1, h1, Qt::KeepAspectRatio));


    // Set statusbar with follow text
    ui->statusbar->showMessage("Copyright@ Embedded Networking Laboratory");


    // Set time for Window
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(my_function()));
    timer->start(1);


}

// Cancel Function
choose_option_login::~choose_option_login()
{
    delete ui;
}



// Slot Function
void choose_option_login::my_function()
{

    QTime time = QTime::currentTime();
    QString date_text = time.toString("hh:mm:ss");
    date_text += "  ";

    QDate Date = QDate::currentDate();
    int day = Date.day();
    date_text += QString::number(day);

    date_text += " Thg ";
    int month = Date.month();
    date_text += QString::number(month);

    ui->label_Time->setText(date_text);
}


// Function xác định danh tính có phải là con người hay không
void choose_option_login::on_checkBox_Human_stateChanged(int )
{
    if(ui->checkBox_Human->isChecked())
    {
        QMessageBox::information(this, "Danh tính", "Bạn là con người");
    }
    else
    {
        QMessageBox::warning(this, "Cảnh báo", "Bạn không phải là con người");
    }
}


// Hàm xử lí khi click vào button ở cửa sổ lựa chọn phương thức đăng nhập
void choose_option_login::on_btn_Next_clicked()
{
    bool check_Human = ui->checkBox_Human->isChecked();
    bool family = ui->rButton_Family->isChecked();
    bool staff = ui->rButton_Staff->isChecked();
    bool management = ui->rButton_Management->isChecked();
    if((check_Human) && (family == false && staff == false && management == false))
    {
        QMessageBox::warning(this, "Cảnh báo", "Bạn cần chọn vai trò đăng nhập");
    }
    else if((check_Human == false) && (family == true || staff ==  true || management == true))
    {
        QMessageBox::warning(this, "Cảnh báo", "Bạn không phải là con người");
    }
    else if(check_Human == false && family == false && staff == false && management == false)
    {
        QString text = "Bạn cần chọn vai trò đăng nhập\n";
        text += "và xác nhận danh tính";
        QMessageBox::warning(this, "Cảnh Báo", text);
    }
    else if(check_Human == true && family == true)
    {
        option = 1;
        close();
        log = new::login;
        log->setWindowTitle("ĐĂNG NHẬP");
        log->show();
    }
    else if(check_Human == true && staff == true)
    {
        option = 2;
        close();
        log = new::login;
        log->setWindowTitle("ĐĂNG NHẬP");
        log->show();
    }
    else if(check_Human == true && management == true)
    {
        option = 3;
        close();
        log = new::login;
        log->setWindowTitle("ĐĂNG NHẬP");
        log->show();
    }
}

