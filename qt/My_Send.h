#ifndef MY_SEND_H
#define MY_SEND_H

#include <QTcpSocket>

class My_Send
{
public:
    My_Send(const char* data, int len);
    ~My_Send();

    QTcpSocket *clientSocket;
    const char* sendbuf;
    int sendlen;

    void SendData();

};

#endif // MY_SEND_H
