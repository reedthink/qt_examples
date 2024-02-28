#include "codeeditor.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CodeEditor w;
    w.resize(640, 512);
    w.show();
    return a.exec();
}
