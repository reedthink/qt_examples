#include "analogclock.h"
#include <QtWidgets>
#include <QPalette>

AnalogClock::AnalogClock(QWidget *parent)
    : QWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&AnalogClock::update));
    timer->start(1000);

    setWindowTitle(tr("Analog Clock by diy"));
    resize(200, 200);
}

AnalogClock::~AnalogClock()
{
}

void AnalogClock::paintEvent(QPaintEvent *event)
{
    static const QPoint hourHand[4] = {
        QPoint(5, 14),
        QPoint(-5, 14),
        QPoint(-4, -71),
        QPoint(4, -71),
    };
    static const QPoint minuteHand[4] = {
        QPoint(4, 14),
        QPoint(-4, 14),
        QPoint(-3, -89),
        QPoint(3, -89),
    };
    static const QPoint secondHand[4] = {
        QPoint(1, 14),
        QPoint(-1, 14),
        QPoint(-1, -89),
        QPoint(1, 89),
    };

    const QColor hourColor(palette().color(QPalette::Text));
    const QColor minuteColor(palette().color(QPalette::Text));
    const QColor secondColor(palette().color(QPalette::Text));

    int side = qMin(width(), height());

    QPainter painter(this);
    QTime time = QTime::currentTime();

    painter.setRenderHint(QPainter::Antialiasing);

    painter.translate(width() / 2, height() / 2);
    painter.scale(side/200.0, side/200.0);

    painter.setPen(Qt::NoPen);
    painter.setBrush(hourColor);
    painter.save();
    painter.rotate(30.0*((time.hour()+time.minute()/60.0)));
    painter.drawConvexPolygon(hourHand, 4);
    painter.restore();

    for(int i=0; i<12; i++)
    {
        painter.drawRect(73, -3, 16, 6);
        painter.rotate(30.0);
    }
    painter.setBrush(minuteColor);
    painter.save();
    painter.rotate(6.0*time.minute());
    painter.drawConvexPolygon(minuteHand, 4);
    painter.restore();

    painter.setBrush(secondColor);

    painter.save();
    painter.rotate(6.0 * time.second());
    painter.drawConvexPolygon(secondHand, 4);
    painter.drawEllipse(-3, -3, 6,6);
    painter.drawEllipse(-5, -68, 10, 10);
    painter.restore();

    painter.setPen(minuteColor);
    for (int i = 0; i < 60; i++)
    {
        painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }


}
