#include "showmsg.h"
#include <QMessageBox>
#include <QDebug>

ShowMsg::ShowMsg(QObject *parent) : QObject(parent)
{

}

void ShowMsg::RecvMsg(QString str)
{
    qDebug()<<str;
    QMessageBox::information(NULL, tr("Show"), str);
}
