#include "widget.h"

#include <QApplication>
#include <QDebug>
#include <QMetaClassInfo>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    const QMetaObject *pMo = w.metaObject();
    int nInfoCount = pMo->classInfoCount();
    for(int i=0 ; i<nInfoCount; i++)
    {
        QMetaClassInfo info = pMo->classInfo(i);
        qDebug() << info.name() << "\t" << info.value();
    }

    qDebug() << "Class Name:" << pMo->className();
    qDebug() << "Object Name: " << w.objectName();
    qDebug() << w.inherits("QWidget");
    qDebug() << w.inherits("nothing");
    w.show();
    return a.exec();
}
