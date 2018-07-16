#ifndef MY_SEND_H
#define MY_SEND_H

#include <QTcpSocket>

class My_Send
{
public:
    My_Send();
    ~My_Send();

    QTcpSocket *clientSocket;
    const char* sendbuf;
    int sendlen;

    void SendData(const char* data, int sendlen);

};

#endif // MY_SEND_H
