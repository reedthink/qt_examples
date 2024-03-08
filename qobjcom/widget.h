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

    //声明信号，不需要编写代码
signals:
    void SendMsg(QString str);

public slots:
    void ButtonClicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
