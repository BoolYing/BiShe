#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    //设置背景图片
    QPixmap pixmap(":/image/bc1");
    QPalette palette=this->palette();
    palette.setBrush(QPalette::Background,QBrush(pixmap));
    this->setPalette(palette);
    //设置标题栏
    this->setWindowTitle("Login");
    //设置密码框
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);

    //显示当前系统时间
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(Set_Time()));
    timer->start(100);
    //去掉标题栏
    //setWindowFlags(Qt::FramelessWindowHint);

    //鬼畜设置
    //this->setAttribute(Qt::WA_TranslucentBackground, true);

    //汉字编码支持
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));

    //设置界面圆角
    QBitmap objBitmap(size());
         //QPainter用于在位图上绘画
    QPainter painter(&objBitmap);
         //填充位图矩形框(用白色填充)
    painter.fillRect(rect(),Qt::white);
    painter.setBrush(QColor(0,0,0));
         //在位图上画圆角矩形(用黑色填充)
    painter.drawRoundedRect(this->rect(),10,10);
         //使用setmask过滤即可
    setMask(objBitmap);

    this->setMouseTracking( true);
    //自动跟踪鼠标（默认情况下，mouseMoveEvent响应你按下鼠标的某个键的鼠标移动。）
    int t_width = width();
    QToolButton *minButton = new QToolButton(this);
    QToolButton *closeButton= new QToolButton(this);
    QPixmap minPix  = style()->standardPixmap(QStyle::SP_TitleBarMinButton);
    QPixmap closePix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
    minButton->setIcon(minPix);
    closeButton->setIcon(closePix);
    minButton->setGeometry(t_width-55,5,20,20);
    closeButton->setGeometry(t_width-30,5,20,20);
    minButton->setToolTip(tr("最小化"));
    closeButton->setToolTip(tr("关闭"));
    minButton->setStyleSheet("background-color:transparent;");
    closeButton->setStyleSheet("background-color:transparent;");


    connect(minButton,SIGNAL(clicked()),this,SLOT(showMinimized()));
    connect(closeButton,SIGNAL(clicked()),this,SLOT(close()));

}

login::~login()
{
    delete ui;
}
bool login::user_exist_true(QString user,QString passwd){

    return true;
}

void login::Set_Time(){
    QDateTime systime = QDateTime::currentDateTime();
    QString str = systime.toString("yyyy-MM-dd hh:mm:ss ");
    ui->label_6->setText(str);

}

void login::on_pushButton_clicked()
{
    QString user=ui->lineEdit->text();
    QString passwd=ui->lineEdit_2->text();
    if( !user_exist_true(user,passwd) ){

        QMessageBox::warning(this,tr("oh"),tr("User name or Password Wrong"),QMessageBox::Yes);
        ui->lineEdit_2->clear();
    }
    else{
        qDebug()<<"OK"<<endl;
        accept();
    }
}

void login::on_pushButton_2_clicked()
{
    exit(0);
}
void login::mousePressEvent ( QMouseEvent * e )//鼠标单击事件响应
{

   if(e->button()==Qt::LeftButton){

       mouse_move_tag = true;
       relativePos=this->pos()- e->globalPos();
       e->accept();

       //qDebug()<<"Qt::LeftButton Pressd.";
   }
   else if(e->button()==Qt::RightButton){
             //qDebug()<<"Qt::RightButton Pressd.";
           }
          else if(e->button()==Qt::MidButton){
       //qDebug()<<"Qt::MidButton Pressd.";

         }
}
void login::mouseReleaseEvent ( QMouseEvent * e )//鼠标松开事件响应
{
    mouse_move_tag = false;
}

void login::mouseMoveEvent(QMouseEvent *e) //鼠标移动事件响应
{
    if (mouse_move_tag && (e->buttons() && Qt::LeftButton)) {
        move(e->globalPos() + relativePos);
        e->accept();
    }
}
