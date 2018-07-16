#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    chat_client = new My_Send();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_send_btn_clicked()
{
    QString str = ui->send_textEdit->toPlainText();
    if(str.isEmpty())
        return;
    QByteArray tmp = str.toLatin1();
    char *sendbuf = tmp.data();

    //chat_client = new My_Send(sendbuf,tmp.length());

    chat_client->SendData(sendbuf,tmp.length());

    delete sendbuf;
}
