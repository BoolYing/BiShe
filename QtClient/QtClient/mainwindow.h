#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include<QVector>
#include <qwt_plot.h>
#include <qwt_point_data.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>
#include <QTcpSocket>
#include <QVector>
#include <QString>
#include <QByteArray>
#include <QStringList>
#include <QHostAddress>
#include <map>
#include <algorithm>
#include <ostream>
#include <QMap>
#include<QtSql/QSqlDatabase>
#include<QDebug>
#include<QThread>
#include<QSqlError>
#include<QSqlQuery>
#include<QSqlRelationalTableModel>
#include<QSqlError>


#define VNAME(name) (#name)//用来输出变量名
extern QString _UserName_;//使用main.cpp中定义的全局变量

typedef struct Item{
    QString str[9];
}Item;



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer timer_updateClock; //每秒一次，更新时钟。
    QTcpSocket * city_code_Socket; //用来查询全部城市信息的套接字指针
    QTcpSocket * register_city_Socket;//用来注册城市的套接字指针
    QTcpSocket * user_info_Socket; //用来查询用户信息的套接字指针
    QTcpSocket * weather7day_Socket;//用来查询大致天气的套接字指针
    QTcpSocket * weather7day_full_Socket;//用来查询未来七天详细信息的套接字指针
    QTcpSocket * city_Socket; //用来通过城市代码查询城市名的套接字指针

    QVector<QString> vector_user_info;//存储用户注册城市的vector
    QVector<Item> vector_weather7day;//用来存储大致天气信息的vrctor
    QVector<Item> vector_weather7day_full;//用来存储详细天气信息的vector
    QVector<Item> vector_city_code;//用来存储城市代码列表的vector

    QSet<QString> province_set;//用来存储省、市、区域的集合
    QSet<QString> city_set;
    QSet<QString> area_set;

    QMap<QString,QwtPlot *>str_2_qwt;
    QMap<QString,QwtPlotCurve *>str_2_cur;
    QVector<double> xs;//x轴数据
    QVector<double> ys;//y轴数据

    QwtPlotCurve *curve_0;
    QwtPlotCurve *curve_1;
    QwtPlotCurve *curve_2;
    QwtPlotCurve *curve_3;
    QwtPlotCurve *curve_4;
    QwtPlotCurve *curve_5;
    QwtPlotCurve *curve_6;

    QSqlRelationalTableModel * model; //历史数据-->表格
    QSqlDatabase db;


private slots:
    //更新时钟与低栏时间的槽函数
    void updateClock();
    void displayError(QAbstractSocket::SocketError);  //显示错误
    QString readMessage(QTcpSocket * tcpSocket);
    void get_user_info();
    void get_weather7day();
    void get_weather7day_full();

    void get_city_code();
    QString get_city(QString city_code);
    //void get_province();
    //void get_city();
    //void get_area();

    void update_weather_info();
    void update_ui(QString city_code);
    void on_listWidget_clicked(const QModelIndex &index);
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_listWidget_2_clicked(const QModelIndex &index);
    void on_listWidget_3_clicked(const QModelIndex &index);

    void on_pushButton_clicked();
};

/*
 * 查看 QwtScaleDraw类，不难发现它继承自QwtAbstractScaleDraw，而QwtAbstractScaleDraw中有一个虚函数
 * virtual QwtText label(double v) const ;
 * 因此，我们只要重写这个虚函数就能满足我们的需要——以时间为横轴 。
 */
/*
class TimeScaleDrawR : public QwtScaleDraw
{
public:
    TimeScaleDrawR(const QDateTime &base);
    virtual QwtText label(double v) const ;
private:
    QDateTime m_scaleBaseTime;
};

*/





#endif // MAINWINDOW_H
