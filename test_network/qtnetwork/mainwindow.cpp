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
    blockSize = 0;
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
    /*
    QDataStream in(tcpSocket);
    in.setVersion(QDataStream::Qt_5_2);  //设置数据流版本
    if(blockSize==0)  //如果刚开始接收数据
    {
        if(tcpSocket->bytesAvailable()<(int)sizeof(quint16))  //如果没有数据则返回
            return ;
        in>>blockSize;
    }

    if(tcpSocket->bytesAvailable()<blockSize) //如果数据没有接收完全，则继续接收数据
        return;
    in>>message;  //将接收到的所有数据存储在message中

    //ui->messageLabel->setText(message);  //显示接收到的数据
    qDebug() << message;
    */
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
