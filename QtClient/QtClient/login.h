#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include<QDebug>
#include<QMessageBox>
#include<QStringlist>
#include<QSqlQuery>
#include<QSqlDatabase>
#include<QTimer>
#include<QDateTime>
#include<QTextCodec>
#include<QBitmap>
#include<QPainter>
#include<QPoint>
#include<QMouseEvent>
#include<QLabel>
#include<QToolButton>
#include<QTcpSocket>
#include<QHostAddress>

#define VNAME(name) (#name)//用来输出变量名
extern QString _UserName_;//使用main.cpp中定义的全局变量

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    bool user_exist_true(QString user,QString passwd);
    void Set_Time();
    QString readMessage();
    void displayError(QAbstractSocket::SocketError);  //显示错误
private:
    Ui::login *ui;
    QPoint relativePos;
    bool mouse_move_tag;
    QTcpSocket * login_tcpSocket;
    //QSqlDatabase db;
protected :
    void mouseMoveEvent ( QMouseEvent * e ); //鼠标移动事件响应
    void mousePressEvent ( QMouseEvent * e ); //鼠标单击事件响应
    void mouseReleaseEvent (  QMouseEvent * e ); //鼠标松开事件响应
};

#endif // LOGIN_H
