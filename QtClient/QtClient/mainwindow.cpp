#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "username is :"<<_UserName_;
    //创建套接字
    city_code_Socket       = new QTcpSocket(this);
    register_city_Socket   = new QTcpSocket(this);
    user_info_Socket       = new QTcpSocket(this);
    weather7day_Socket     = new QTcpSocket(this);
    weather7day_full_Socket= new QTcpSocket(this);
    //若套接字出错，则调用displayError函数输出套接字名及其错误信息
    connect(city_code_Socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
    connect(register_city_Socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
    connect(user_info_Socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
    connect(weather7day_Socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
    connect(weather7day_full_Socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));

    timer_updateClock.start(1000);//定时器，用来刷新时钟部件
    connect(&timer_updateClock,SIGNAL(timeout()),this,SLOT(updateClock()));

    get_user_info();//获取一次关注的城市列表，并追加到list_widget上


/*
//样式举例，图qwtPlot_5：
    //设置y轴下面标识：
    ui->qwtPlot_5->setAxisTitle(QwtPlot::yLeft,QObject::trUtf8("temp"));
    //设置x轴下面标识：
    ui->qwtPlot_5->setAxisTitle(QwtPlot::xBottom,QObject::trUtf8("time"));
    //计算曲线数据
    double temp[8]={20.0,19.0,24.0,31.0,33.0,33.0,26.0,24.0};
    int count=sizeof(temp)/sizeof(int);
    QVector<double> xs;
    QVector<double> ys;    
    for(int i =0;i<8;i+=1){
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
    ui->qwtPlot_5->replot();
*/



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

/*
TimeScaleDrawR::TimeScaleDrawR(const QDateTime &base):  m_scaleBaseTime(base){

}
QwtText TimeScaleDrawR::label(double v) const{
    //应该是在 m_scaleBaseTime(currentTime)的基础上，增加了(qint64)v秒
    QDateTime upTime = m_scaleBaseTime.addSecs( (qint64)v );
    return upTime.toString("yyyy-MM-dd\n hh:mm:ss");
}
*/

void MainWindow::displayError(QAbstractSocket::SocketError)
{
    //当有套接字出错时，会在这里输出出错的套接字与错误信息
    if(city_code_Socket->errorString() != QString("Unknown error")){
         qDebug()<<VNAME(city_code_Socket) <<"--> : "<<city_code_Socket->errorString();
    }
    if(register_city_Socket->errorString() != QString("Unknown error")){
         qDebug()<<VNAME(register_city_Socket) <<"--> : "<<register_city_Socket->errorString();
    }
    if(user_info_Socket->errorString() != QString("Unknown error")){
         qDebug()<<VNAME(user_info_Socket) <<"--> : "<<user_info_Socket->errorString();
    }
    if(weather7day_Socket->errorString() != QString("Unknown error")){
         qDebug()<<VNAME(weather7day_Socket) <<"--> : "<<weather7day_Socket->errorString();
    }
    if(weather7day_full_Socket->errorString() != QString("Unknown error")){
         qDebug()<<VNAME(weather7day_full_Socket) <<"--> : "<<weather7day_full_Socket->errorString();
    }

}

void MainWindow::get_user_info(){
    QString buf;
    user_info_Socket->abort(); //取消已有的连接
    QString request = "2";
    QString info = _UserName_;
    user_info_Socket->connectToHost(QHostAddress("192.168.19.128"),8955);
    user_info_Socket->write(request.toLocal8Bit());
    user_info_Socket->write(info.toLocal8Bit());
    if(user_info_Socket->waitForReadyRead(3000)){ //有数据可读则返回
        buf = readMessage(user_info_Socket);//读取数据
        QStringList list;
        list = buf.split(",");
        for(int i = 0;i <list.size();i++){
            if(list.at(i)=="") continue;
            vector_user_info.push_back(list.at(i));
            ui->listWidget->addItem(list.at(i));
            qDebug() << list.at(i);
        }
    }
}

void MainWindow::get_register_city(){

}

void MainWindow::get_city_code(){

}

void MainWindow::get_weather7day(){

}

void MainWindow::get_weather7day_full(){
    QString buf;
    weather7day_full_Socket->abort(); //取消已有的连接
    QString request = "4";
    QString info = _UserName_;
    weather7day_full_Socket->connectToHost(QHostAddress("192.168.19.128"),8955);
    weather7day_full_Socket->write(request.toLocal8Bit());
    weather7day_full_Socket->write(info.toLocal8Bit());
    if(user_info_Socket->waitForReadyRead(3000)){ //有数据可读则返回
        buf = readMessage(weather7day_full_Socket);//读取数据
        QStringList item_list;
        item_list = buf.split(";");
        for(int i = 0;i <item_list.size();i++){
            QStringList value_list;
            value_list = item_list.at(i).split(",");
            for(int j =0;j< value_list.size();j++){

            }


            vector_user_info.push_back(list.at(i));
            ui->listWidget->addItem(list.at(i));
            qDebug() << item_list.at(i);
        }
    }
}




//读取指定套接字的缓冲区，并将数据保存为QString 返回给调用者
QString MainWindow::readMessage(QTcpSocket *tcpSocket)
{
    QByteArray buffer;
    //读取缓冲区数据
    buffer = tcpSocket->readAll();
    QString buf = QString::fromLocal8Bit(buffer);
    return buf;

}
