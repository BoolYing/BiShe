#include "mainwindow.h"
#include <QApplication>
#include "login.h"

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
