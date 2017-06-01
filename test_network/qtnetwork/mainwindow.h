#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qtcpserver.h>
#include <qtcpsocket.h>
#include <QtNetwork>
#include <QHostInfo>
#include <QTcpSocket>
#include <Windows.h>


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
    void on_pushButton_clicked();
    void readMessage();
    void displayError(QAbstractSocket::SocketError);  //显示错误

private:
    Ui::MainWindow *ui;
    QTcpSocket * tcpSocket;
};

#endif // MAINWINDOW_H
