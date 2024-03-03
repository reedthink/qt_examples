#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    进行关联，按钮的槽函数可以当作普通函数来调用，实现关联
    on_pushButtonConn_clicked();
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButtonConn_clicked()
{
    connect(ui->lineEdit, SIGNAL(textEdited(QString)), ui->label, SLOT(setText(QString)));

    ui->pushButtonConn->setEnabled(false);
    ui->pushButtonDisConn->setEnabled(true);
}


void Widget::on_pushButtonDisConn_clicked()
{
    disconnect(ui->lineEdit, SIGNAL(textEdited(QString)), ui->label, SLOT(setText(QString)));

    ui->pushButtonConn->setEnabled(true);
    ui->pushButtonDisConn->setEnabled(false);
}

