#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "My_Send.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

    My_Send chat_client(sendbuf,tmp.length());

    chat_client.SendData();

    delete sendbuf;
}
