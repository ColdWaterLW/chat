#ifndef MY_TIMEOPER_H
#define MY_TIMEOPER_H

#include <QObject>

class My_TimeOper : public QObject
{
    Q_OBJECT
public:
    explicit My_TimeOper(QObject *parent = 0);

    static void mSleep(int ms);

signals:

public slots:
};

#endif // MY_TIMEOPER_H
