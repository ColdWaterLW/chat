#include "My_Send.h"
#include "My_TimeOper.h"

My_Send::My_Send()
{
    //if(len > 0)
    {
        clientSocket = new QTcpSocket;
        //dist_ip = "192.168.0.222";
        clientSocket->abort();
        clientSocket->connectToHost("192.168.1.222",7000);

    }
}

My_Send::~My_Send()
{
    clientSocket->close();

    delete clientSocket;

    clientSocket = NULL;

}

void My_Send::SendData(const char* sendbuf, int sendlen)
{
    int i;
   // sendbuf = data;
   // sendlen = len;
    if(sendlen <= 0)
        return;

    qDebug() << "len = " << sendlen << endl;
    for(i = 0; i < sendlen; i++)
        qDebug("%02x ",sendbuf[i]);
    qDebug("\n");
    clientSocket->write(sendbuf,sendlen);
   // My_TimeOper::mSleep(500);
}
