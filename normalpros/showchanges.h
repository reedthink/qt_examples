#ifndef SHOWCHANGES_H
#define SHOWCHANGES_H

#include <QObject>

class ShowChanges : public QObject
{
    Q_OBJECT
public:
    explicit ShowChanges(QObject *parent = nullptr);

signals:

public slots:
    void RecvValue(double v);
    void RecvNickName(QString nickName);
    void RecvCount(int v);
};

#endif // SHOWCHANGES_H
