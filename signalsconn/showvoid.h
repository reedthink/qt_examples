#ifndef SHOWVOID_H
#define SHOWVOID_H

#include <QObject>

class ShowVoid : public QObject
{
    Q_OBJECT
public:
    explicit ShowVoid(QObject *parent = nullptr);

signals:

public slots:
    void RecvVoid();

};

#endif // SHOWVOID_H
