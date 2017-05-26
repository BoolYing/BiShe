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

private:
    Ui::login *ui;
    QPoint relativePos;
    bool mouse_move_tag;
    //QSqlDatabase db;
protected :
    void mouseMoveEvent ( QMouseEvent * e );
    void mousePressEvent ( QMouseEvent * e );
    void mouseReleaseEvent (  QMouseEvent * e );
    // void mouseDoubleClickEvent( QMouseEvent * e );

};

#endif // LOGIN_H