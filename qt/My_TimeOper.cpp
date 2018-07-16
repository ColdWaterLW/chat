#include "My_TimeOper.h"
#include <QTime>
#include <QApplication>

My_TimeOper::My_TimeOper(QObject *parent) : QObject(parent)
{

}

void My_TimeOper::mSleep(int ms)
{
    QTime distTime = QTime::currentTime().addMSecs(ms);
    while (QTime::currentTime() < distTime) {
        QCoreApplication::processEvents(QEventLoop::AllEvents,100); //事件循环，可以继续处理事件和消息
    }
}
