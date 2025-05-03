/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *SensorKnop;
    QPushButton *SchuifDeurKnop;
    QPushButton *DraaiDeurKnop1;
    QPushButton *DraaiDeurKnop2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        SensorKnop = new QPushButton(centralwidget);
        SensorKnop->setObjectName("SensorKnop");
        SensorKnop->setGeometry(QRect(510, 110, 51, 24));
        SchuifDeurKnop = new QPushButton(centralwidget);
        SchuifDeurKnop->setObjectName("SchuifDeurKnop");
        SchuifDeurKnop->setGeometry(QRect(520, 300, 41, 24));
        DraaiDeurKnop1 = new QPushButton(centralwidget);
        DraaiDeurKnop1->setObjectName("DraaiDeurKnop1");
        DraaiDeurKnop1->setGeometry(QRect(310, 260, 41, 24));
        DraaiDeurKnop2 = new QPushButton(centralwidget);
        DraaiDeurKnop2->setObjectName("DraaiDeurKnop2");
        DraaiDeurKnop2->setGeometry(QRect(250, 150, 41, 24));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(600, 140, 113, 24));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(360, 280, 71, 24));
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(290, 180, 71, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        SensorKnop->setText(QCoreApplication::translate("MainWindow", "s1", nullptr));
        SchuifDeurKnop->setText(QCoreApplication::translate("MainWindow", "VD", nullptr));
        DraaiDeurKnop1->setText(QCoreApplication::translate("MainWindow", "d2", nullptr));
        DraaiDeurKnop2->setText(QCoreApplication::translate("MainWindow", "d1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
