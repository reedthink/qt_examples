#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    Q_CLASSINFO("Version", "1.0.0");
    Q_CLASSINFO("Author", "TTT");
    Q_CLASSINFO("Site", "https://www.google.com");

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
