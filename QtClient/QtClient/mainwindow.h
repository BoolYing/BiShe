#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include<QVector>
#include <qwt_plot.h>
#include <qwt_point_data.h>
#include <qwt_plot_curve.h>
#include <qwt_symbol.h>

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
private slots:
    //更新时钟与低栏时间的槽函数
    void updateClock();
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
