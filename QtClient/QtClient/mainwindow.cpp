#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "username is :"<<_UserName_;
    //创建七条曲线，用来存储未来七天数据。
    curve_0=new QwtPlotCurve("Temp");
    curve_1=new QwtPlotCurve("Temp");
    curve_2=new QwtPlotCurve("Temp");
    curve_3=new QwtPlotCurve("Temp");
    curve_4=new QwtPlotCurve("Temp");
    curve_5=new QwtPlotCurve("Temp");
    curve_6=new QwtPlotCurve("Temp");
    //创建字符串到qwt指针变量的映射
    str_2_qwt.insert("qwtPlot_0",ui->qwtPlot_0);
    str_2_qwt.insert("qwtPlot_1",ui->qwtPlot_1);
    str_2_qwt.insert("qwtPlot_2",ui->qwtPlot_2);
    str_2_qwt.insert("qwtPlot_3",ui->qwtPlot_3);
    str_2_qwt.insert("qwtPlot_4",ui->qwtPlot_4);
    str_2_qwt.insert("qwtPlot_5",ui->qwtPlot_5);
    str_2_qwt.insert("qwtPlot_6",ui->qwtPlot_6);
    //创建字符串到cur指针变量的映射
    str_2_cur.insert("curve_0",curve_0);
    str_2_cur.insert("curve_1",curve_1);
    str_2_cur.insert("curve_2",curve_2);
    str_2_cur.insert("curve_3",curve_3);
    str_2_cur.insert("curve_4",curve_4);
    str_2_cur.insert("curve_5",curve_5);
    str_2_cur.insert("curve_6",curve_6);



    //设置所有qwtplot的轴的意义解释
    for(int i=0;i<7;i++){
        char str[10];
        sprintf(str,"%d",i);
        str_2_qwt[QString("qwtPlot_")+QString(str)]->setAxisTitle(QwtPlot::yLeft,QObject::trUtf8("temp"));
        str_2_qwt[QString("qwtPlot_")+QString(str)]->setAxisTitle(QwtPlot::xBottom,QObject::trUtf8("time"));
        str_2_qwt[QString("qwtPlot_")+QString(str)]->setAxisScale( QwtPlot::xBottom, 0.0, 24.0 );
        str_2_qwt[QString("qwtPlot_")+QString(str)]->setAxisMaxMajor( QwtPlot::xBottom, 8 );
        str_2_qwt[QString("qwtPlot_")+QString(str)]->setAxisScale( QwtPlot::yLeft, 10.0, 35.0 );


        QwtPlotCurve *curve = str_2_cur[QString("curve_")+QString(str)];
        //创建曲线对象，并将数据添加进去
        curve->setPen(QPen(Qt::blue));//线条颜色设置为蓝色
        curve->setRenderHint(QwtPlotItem::RenderAntialiased);//启用抗锯齿
        curve->setStyle(QwtPlotCurve::Lines);//直线形式
        curve->setCurveAttribute(QwtPlotCurve::Fitted, true);//是曲线更光滑
        curve->setPen(QPen(Qt::blue));//设置画笔
        //设置样本点的颜色、大小,Ellipse椭圆或圆，brush填充内部颜色，QPen节点的轮廓颜色
        QwtSymbol * symbol = new QwtSymbol( QwtSymbol::Ellipse,
            QBrush(Qt::red), QPen(Qt::white,1), QSize(6,6));
        curve->setSymbol(symbol);
    }



    //创建套接字
    city_code_Socket       = new QTcpSocket(this);
    register_city_Socket   = new QTcpSocket(this);
    user_info_Socket       = new QTcpSocket(this);
    weather7day_Socket     = new QTcpSocket(this);
    weather7day_full_Socket= new QTcpSocket(this); 

    update_weather_info();
    update_ui(vector_user_info[0]);

    timer_updateClock.start(1000);//定时器，用来刷新时钟部件
    connect(&timer_updateClock,SIGNAL(timeout()),this,SLOT(updateClock()));
    //若套接字出错，则调用displayError函数输出套接字名及其错误信息
    connect(city_code_Socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
    connect(register_city_Socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
    connect(user_info_Socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
    connect(weather7day_Socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
    connect(weather7day_full_Socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(displayError(QAbstractSocket::SocketError)));
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
        //qDebug()<<buf;
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

void MainWindow::set_register_city(){

}

void MainWindow::get_city_code(){

}

void MainWindow::get_weather7day(){
    QString buf;
    weather7day_Socket->abort(); //取消已有的连接
    QString request = "3";
    QString info = _UserName_;
    weather7day_Socket->connectToHost(QHostAddress("192.168.19.128"),8955);
    weather7day_Socket->write(request.toLocal8Bit());
    weather7day_Socket->write(info.toLocal8Bit());
    if(weather7day_Socket->waitForReadyRead(3000)){ //有数据可读则返回
        buf = readMessage(weather7day_Socket);//读取数据
        qDebug()<<buf.size()<<"    -->"<<buf;
        QStringList item_list;
        item_list = buf.split(";");
        for(int i = 0;i <item_list.size();i++){
            if(item_list.at(i)=="") continue;
            qDebug()<<item_list.at(i);
            QStringList value_list = QString(item_list.at(i)).split(",");
            Item item;
            for(int j = 0;j< value_list.size();j++){
                if(value_list.at(j) == "") continue;
                item.str[j] = value_list.at(j);
                //qDebug()<<value_list.at(j);
            }
            vector_weather7day.push_back(item);
            //qDebug()<<item[0]<<","<<item[1]<<","<<item[2]<<","<<item[3]<<","<<item[4]<<","<<item[5]<<","<<item[6]<<","<<item[7];
        }
    }
}

void MainWindow::get_weather7day_full(){
    QString buf;
    weather7day_full_Socket->abort(); //取消已有的连接
    QString request = "4";
    QString info = _UserName_;
    weather7day_full_Socket->connectToHost(QHostAddress("192.168.19.128"),8955);
    weather7day_full_Socket->write(request.toLocal8Bit());
    weather7day_full_Socket->write(info.toLocal8Bit());
    if(weather7day_full_Socket->waitForReadyRead(3000)){ //有数据可读则返回
        buf = readMessage(weather7day_full_Socket);//读取数据

        qDebug()<<buf.size()<<"    -->"<<buf;
        QStringList item_list;
        item_list = buf.split(";");
        for(int i = 0;i <item_list.size();i++){
            if(item_list.at(i)=="") continue;
            qDebug()<<item_list.at(i);
            QStringList value_list = QString(item_list.at(i)).split(",");
            Item item;
            for(int j = 0;j< value_list.size();j++){
                if(value_list.at(j) == "") continue;
                item.str[j] = value_list.at(j);
            }
            vector_weather7day_full.push_back(item);
            //qDebug()<<item[0]<<","<<item[1]<<","<<item[2]<<","<<item[3]<<","<<item[4]<<","<<item[5]<<","<<item[6]<<","<<item[7];
        }
    }
}




//读取指定套接字的缓冲区，并将数据保存为QString 返回给调用者
QString MainWindow::readMessage(QTcpSocket *tcpSocket)
{
    QByteArray buffer;
    //读取缓冲区数据
    buffer = tcpSocket->readAll();
    QString buf = QString::fromUtf8(buffer);
    return buf;

}
//点击listWidget会触发这个时间，将更新图、标内容。
void MainWindow::on_listWidget_clicked(const QModelIndex &index)
{
    QString city_code=ui->listWidget->currentItem()->text();//获取当前选中条目的文本
    qDebug()<<city_code;
    update_ui(city_code);//根据这个城市代码，提取数据，并更新ui

}

void MainWindow::update_ui(QString city_code){
    QVector<Item> temp;     //未来6天的走向
    QVector<Item> temp_full;//保存当前城市七天内的详细数据
    QVector<Item>::iterator it;
    QVector<Item>::iterator jt;
    for(it = vector_weather7day.begin();it != vector_weather7day.end();it++){
        if(it->str[0] == city_code){
            temp.push_back(*it);
        }
    }
    for(it = vector_weather7day_full.begin();it != vector_weather7day_full.end();it++){
        if(it->str[0] == city_code){
            temp_full.push_back(*it);
        }
    }
    int cnt = 0;
    for(it = temp.begin();it != temp.end();it++,cnt++){
        xs.clear();//清除保存的数据
        ys.clear();
        char cnt_str[10];
        sprintf(cnt_str,"%d",cnt);
        int date1;
        QString date_week;
        date1 = it->str[1].toInt();
        date_week = it->str[2];
        ui->tabWidget_2->setTabText(cnt,date_week);
        for(jt = temp_full.begin();jt != temp_full.end();jt++){
            int date2 = QString(QString(jt->str[1][0]) + QString(jt->str[1][1])).toInt();
            if(date1 == date2){
                int time = QString(QString(jt->str[1][3])+QString(jt->str[1][4])).toInt();
                int value= QString(QString(jt->str[3][0])+QString(jt->str[3][1])).toInt();
                xs.push_back(time *1.0);
                ys.push_back(value*1.0);
            }
        }

        QwtPlotCurve *curve = str_2_cur[QString("curve_")+QString(cnt_str)];
        //创建曲线对象，并将数据添加进去
        //QwtPlotCurve *curve=new QwtPlotCurve("Temp");
        curve->setSamples(xs,ys);
        curve->attach(str_2_qwt[QString("qwtPlot_")+QString(cnt_str)]);

        //str_2_qwt[QString("qwtPlot_")+QString(cnt_str)]->setAxisScale( QwtPlot::yLeft, 10.0, 35.0 );

        str_2_qwt[QString("qwtPlot_")+QString(cnt_str)]->replot();


    }

    qDebug()<<"testtttttttt-->"<<temp_full[0].str[1];
    qDebug()<<"String size-->"<<temp_full[0].str[1].size();

    qDebug()<<"Date-->"<<QString(
                                 QString(temp_full[0].str[1][0])
                                +QString(temp_full[0].str[1][1])
                                ).toInt();
    qDebug()<<"Time-->"<<QString(
                                 QString(temp_full[0].str[1][3])
                                +QString(temp_full[0].str[1][4])
                                ).toInt();



}

void MainWindow::update_weather_info(){
    get_user_info();//获取一次关注的城市列表，并追加到list_widget上
    get_weather7day_full();//未来七天详细信息
    get_weather7day();//七天天气走向
}
