#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer_updateClock.start(1000);
    connect(&timer_updateClock,SIGNAL(timeout()),this,SLOT(updateClock()));
    /*
     * ui->label_3->setText("五月25日");
    ui->label_5->setText("27℃");
    ui->label_7->setText("晴");
    ui->label_9->setText("3-4级");
    ui->label_11->setText("东南风");
    ui->label_13->setText("101110101");
    */
    ui->listWidget->addItem("101110101");
    ui->listWidget->addItem("101110102");
    ui->listWidget->addItem("101110103");
    ui->listWidget->addItem("101110104");

    //设置y轴下面标识：
    ui->qwtPlot_5->setAxisTitle(QwtPlot::yLeft,QObject::trUtf8("temp"));
    //设置x轴下面标识：
    ui->qwtPlot_5->setAxisTitle(QwtPlot::xBottom,QObject::trUtf8("time"));

    //计算曲线数据
    double temp[8]={20.0,19.0,24.0,31.0,33.0,33.0,26.0,24.0};
    int count=sizeof(temp)/sizeof(int);
    QVector<double> xs;
    QVector<double> ys;
    for(int i =0;i<=8;i+=1){
        xs.append(i*1.0);
        ys.push_back(temp[i]);
    }

    QwtPlotCurve *curve=new QwtPlotCurve("Temp");
    curve->setSamples(xs,ys);

    curve->setPen(QPen(Qt::blue));//线条颜色设置为蓝色
    curve->setRenderHint(QwtPlotItem::RenderAntialiased);//启用抗锯齿
    curve->setStyle(QwtPlotCurve::Lines);//直线形式
    curve->setCurveAttribute(QwtPlotCurve::Fitted, true);//是曲线更光滑
    curve->setPen(QPen(Qt::blue));//设置画笔

    //设置样本点的颜色、大小,Ellipse椭圆或圆，brush填充内部颜色，QPen节点的轮廓颜色
    QwtSymbol *symbol = new QwtSymbol( QwtSymbol::Ellipse,
        QBrush(Qt::red), QPen(Qt::white,1), QSize(6,6));
    //添加样本点形状
    curve->setSymbol(symbol);

    //ui->qwtPlot_5->show();
    curve->attach(ui->qwtPlot_5);
    ui->qwtPlot->replot();




}

MainWindow::~MainWindow()
{
    delete ui;
}
//更新时钟为最新时间
void MainWindow::updateClock(){
    //每秒更新一次钟表的时间
    ui->AnalogClock->setTime(QTime::currentTime());
    ui->AnalogClock->update();
    //每秒更新一下statusBar上的时间
    ui->statusBar->showMessage(QString("   ") + QString("%1").arg(QTime::currentTime().toString("H:m a")));
}

TimeScaleDrawR::TimeScaleDrawR(const QDateTime &base):  m_scaleBaseTime(base){

}

QwtText TimeScaleDrawR::label(double v) const{
    //应该是在 m_scaleBaseTime(currentTime)的基础上，增加了(qint64)v秒
    QDateTime upTime = m_scaleBaseTime.addSecs( (qint64)v );
    return upTime.toString("yyyy-MM-dd\n hh:mm:ss");
}











