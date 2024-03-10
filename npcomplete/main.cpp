#include "widget.h"
#include "showchanges.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    ShowChanges s;
    QObject::connect(&w, SIGNAL(valueChanged(double)), &s, SLOT(RecvValue(double)));
    QObject::connect(&w, SIGNAL(nickNameChanged(QString)), &s, SLOT(RecvNickName(QString)));
    QObject::connect(&w, SIGNAL(countChanged(int)), &s, SLOT(RecvCount(int)));
    w.setNickName("jk");
    qDebug() << w.nickName();
    w.setCount(100);
    qDebug() << w.count();

    w.setProperty("value", 3.14);
    qDebug() << fixed << w.property("value").toDouble();

    w.show();
    return a.exec();
}
