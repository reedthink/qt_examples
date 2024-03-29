#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->lineEdit, SIGNAL(textEdited(QString)), ui->label, SLOT(setText(QString)));
    connect(ui->lineEdit, SIGNAL(textEdited(QString)), ui->textBrowser, SLOT(setText(QString)));
    connect(ui->lineEdit, SIGNAL(textEdited(QString)), this, SLOT(PrintText(QString)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::PrintText(const QString &text)
{
    qDebug()<<text;
}
