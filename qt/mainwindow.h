#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "My_Send.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_send_btn_clicked();

private:
    Ui::MainWindow *ui;
    My_Send* chat_client;
};

#endif // MAINWINDOW_H
