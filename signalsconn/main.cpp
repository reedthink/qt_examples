#include "widget.h"
#include "showvoid.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    ShowVoid s;
    QObject::connect(&w, SIGNAL(SendVoid()), &s, SLOT(RecvVoid()));
    //为什么不直接把button的信号绑定到RecvVoid上？因为button的信号是私有的
    w.show();
    return a.exec();
}
