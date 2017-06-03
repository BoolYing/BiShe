#include "mainwindow.h"
#include <QApplication>
#include "login.h"
#include <QString>

QString _UserName_;//全局变量，在登录界面上登陆成功，会将用户名保存到全局变量中，以便在主界面中使用。

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    login log;
    if(log.exec()==QDialog::Accepted){
        log.close();
        MainWindow w;
        w.show();
        return a.exec();
    }

    else
        return 0;
}
