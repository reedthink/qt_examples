#include "widget.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    qDebug() << w.property("myValue").isValid();
    w.setProperty("myValue", 2.3456);
    qDebug() << w.property("myValue").toDouble();

    w.setProperty("myName", "Wid"); // 设置之后怎么保存的? 用QVariant
    qDebug() << w.property("myName").toString();

    qDebug() << w.dynamicPropertyNames();
    w.show();
    return a.exec();
}
