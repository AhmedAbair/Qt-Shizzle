#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "sensor.h"
#include "deur.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    s1 = new HallSensor(515, 160);

    std::shared_ptr<Sleutelslot> sleutelslotje1 = std::make_shared<Sleutelslot>("Ahmed");
    std::shared_ptr<Codeslot> code1 = std::make_shared<Codeslot>(12345);
    std::shared_ptr<Codeslot> code2 = std::make_shared<Codeslot>(00000);

      verschillendeDeuren.push_back(std::make_shared<Schuifdeur>(503, 250, 80, sleutelslotje1, dynamic_cast<HallSensor*>(s1)));

    verschillendeDeuren.push_back(std::make_shared<Draaideur>(295,290,30,true,code1));
    verschillendeDeuren.push_back(std::make_shared<Draaideur>(248,140,40, false,code2));

}

void MainWindow::paintEvent(QPaintEvent *event){

    QPainter painter(this);
    QPen pen;
    QImage image("D:\\C++\\Qt-Shizzle\\Gebouw.png");

    pen.setColor(Qt::green);
    pen.setWidth(4);
    painter.setPen(pen);
    painter.drawImage(10,10,image);

    s1->teken(this);
    verschillendeDeuren.at(0)->teken(this);
    verschillendeDeuren.at(1)->teken(this);
    verschillendeDeuren.at(2)->teken(this);
    }


MainWindow::~MainWindow()
{
    delete ui;
    delete s1;
}

void MainWindow::on_SensorKnop_clicked()
{
    if(!s1->isGeactiveerd()){
        s1->activeer();
       // verschillendeDeuren.at(0)->open();
    }
    else {
        s1->deactiveer();
    }
    update();
}


void MainWindow::on_SchuifDeurKnop_clicked()
{
    if (verschillendeDeuren.at(0)->isDeurOpen()) {

        if (!s1->isGeactiveerd()) {
            verschillendeDeuren.at(0)->sluit();
        }

    } else {

        verschillendeDeuren.at(0)->open();
    }

    update();
}

void MainWindow::on_DraaiDeurKnop2_clicked()
{
    if (!verschillendeDeuren.at(2)->isDeurOpen()){
        verschillendeDeuren.at(2)->open();
    }
    else{
        verschillendeDeuren.at(2)->sluit();
    }
    update();
}


void MainWindow::on_DraaiDeurKnop1_clicked()
{
    if (verschillendeDeuren.at(1)->isDeurOpen()){
        verschillendeDeuren.at(1)->sluit();
    }
    else{
        verschillendeDeuren.at(1)->open();
    }
    update();
}


void MainWindow::on_lineEdit_returnPressed()
{

}

