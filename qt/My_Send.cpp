#include "My_Send.h"
#include "My_TimeOper.h"

My_Send::My_Send(const char* data, int len)
{
    if(len > 0)
    {
        sendbuf = data;
        sendlen = len;
        clientSocket = new QTcpSocket;
        //dist_ip = "192.168.0.222";
        clientSocket->abort();
        clientSocket->connectToHost("192.168.1.222",7000);

    }
}

My_Send::~My_Send()
{
    delete clientSocket;

    clientSocket = NULL;

}

void My_Send::SendData()
{
    int i;
    qDebug() << "len = " << sendlen << endl;
    for(i = 0; i < sendlen; i++)
        qDebug("%02x ",sendbuf[i]);
    qDebug("\n");
    clientSocket->write(sendbuf,sendlen);
    My_TimeOper::mSleep(500);
}
