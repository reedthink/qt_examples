#include "showchanges.h"
#include <QDebug>

ShowChanges::ShowChanges(QObject *parent) : QObject(parent)
{

}

void ShowChanges::RecvValue(double v)
{
    qDebug() << "RecvValue: " << fixed << v;
}

void ShowChanges::RecvNickName(const QString &nickName)
{
    qDebug() << "RecvNickName: " << nickName;
}

void ShowChanges::RecvCount(int v)
{
    qDebug() << "RecvCount: " << v;
}
