/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QLabel *label;
    QLabel *label_6;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLabel *label_5;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(544, 382);
        label = new QLabel(login);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(190, 40, 151, 16));
        label_6 = new QLabel(login);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(370, 340, 131, 20));
        layoutWidget = new QWidget(login);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(130, 150, 241, 23));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        layoutWidget_2 = new QWidget(login);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(130, 190, 241, 23));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        lineEdit_2 = new QLineEdit(layoutWidget_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);

        label_2 = new QLabel(login);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(220, 100, 71, 16));
        pushButton_2 = new QPushButton(login);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 260, 75, 23));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton:hover:!pressed\n"
"{\n"
"   color: white;\n"
"  background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #99e, stop: 0.49 #77c, stop: 0.5 #66b, stop: 1 #77c);\n"
"  border-width: 1px;\n"
"  border-color: #339;\n"
"  border-style: solid;\n"
"  border-radius: 7;\n"
"  padding: 3px;\n"
"  font-size: 13px;\n"
"  padding-left: 5px;\n"
"  padding-right: 5px;\n"
"  min-width: 50px;\n"
"  max-width: 50px;\n"
"  min-height: 13px;\n"
"  max-height: 13px;\n"
"}"));
        pushButton = new QPushButton(login);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(160, 260, 75, 23));
        pushButton->setStyleSheet(QLatin1String("QPushButton:hover:!pressed\n"
"{\n"
"   color: white;\n"
"  background-color: QLinearGradient( x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #88d, stop: 0.1 #99e, stop: 0.49 #77c, stop: 0.5 #66b, stop: 1 #77c);\n"
"  border-width: 1px;\n"
"  border-color: #334;\n"
"  border-style: solid;\n"
"  border-radius: 7;\n"
"  padding: 3px;\n"
"  font-size: 13px;\n"
"  padding-left: 5px;\n"
"  padding-right: 5px;\n"
"  min-width: 50px;\n"
"  max-width: 50px;\n"
"  min-height: 13px;\n"
"  max-height: 13px;\n"
"}"));
        label_5 = new QLabel(login);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(100, 340, 141, 16));

        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("login", " \345\244\251\346\260\224\346\220\234\347\264\242\345\256\242\346\210\267\347\253\257", Q_NULLPTR));
        label_6->setText(QString());
        label_3->setText(QApplication::translate("login", "\350\264\246\345\217\267\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("login", "\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("login", "\347\231\273\345\275\225\347\252\227\345\217\243", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("login", "\351\200\200\345\207\272", Q_NULLPTR));
        pushButton->setText(QApplication::translate("login", "\347\231\273\345\275\225", Q_NULLPTR));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
