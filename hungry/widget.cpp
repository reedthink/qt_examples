#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

//    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(FoodIsComing()));
    connect(ui->pushButton, &QPushButton::clicked, this, &Widget::FoodIsComing);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::FoodIsComing()
{
    QMessageBox::information(this, tr("送餐"), tr("叮咚！外卖已送达"));
}
