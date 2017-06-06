#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    connect(tcpSocket,&QTcpSocket::readyRead,this,&MainWindow::readMessage);
    connect(tcpSocket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    //blockSize = 0;
    tcpSocket->abort(); //取消已有的连接
    QString request = ui->lineEdit->text();
    QString info = ui->lineEdit_2->text();
    tcpSocket->connectToHost(QHostAddress("192.168.19.128"),8955);
    tcpSocket->write(request.toLocal8Bit());
    //Sleep(500);
    tcpSocket->write(info.toLocal8Bit());

}
void MainWindow::displayError(QAbstractSocket::SocketError)
{
    qDebug()<<tcpSocket->errorString(); //输出错误信息
}
void MainWindow::readMessage()
{

    QByteArray buffer;
    //读取缓冲区数据
    buffer = tcpSocket->readAll();
    QString buf = QString::fromLocal8Bit(buffer);
    QStringList list;
    list = buf.split("\n");
    for(int it = 0;it <list.size();it++){
        qDebug() << list.at(it);
    }

    //qDebug() << buffer;
}
