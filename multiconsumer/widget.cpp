#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButtonAnderson, SIGNAL(clicked()), this, SLOT(FoodIsComing()));
    connect(ui->pushButtonBruce, SIGNAL(clicked()), this, SLOT(FoodIsComing()));
    connect(ui->pushButtonCastiel, SIGNAL(clicked()), this, SLOT(FoodIsComing()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::FoodIsComing()
{
    QString strObject = this->sender()->objectName(); //获取信号源
    qDebug()<<strObject;

    QString strMsg;
    if(strObject == "pushButtonAnderson")
    {
        strMsg = tr("Hello Anderson! Your food is coming!");
    }
    else if(strObject == "pushButtonBruce")
    {
        strMsg = tr("Hello Bruce! Your food is coming!");
    }
    else if(strObject == "pushButtonCastiel")
    {
        QString generalMsg = tr("Your food is coming!");
        strMsg = tr("Hello Castiel! ") + generalMsg;
    }
    else {
        return ;
    }
    QMessageBox::information(this, tr("Food"), strMsg);
}
