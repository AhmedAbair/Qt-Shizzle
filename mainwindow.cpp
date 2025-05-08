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


    verschillendeSloten.push_back(std::make_shared<Sleutelslot>("Ahmed",true));
    verschillendeSloten.push_back(std::make_shared<Codeslot>(1234,true));
    verschillendeSloten.push_back(std::make_shared<Codeslot>(5678,true));

    verschillendeDeuren.push_back(std::make_shared<Schuifdeur>(503, 250, 80, dynamic_cast<HallSensor*>(s1)));
    verschillendeDeuren.push_back(std::make_shared<Draaideur>(295,290,30,true));
    verschillendeDeuren.push_back(std::make_shared<Draaideur>(248,140,40, false));

    verschillendeDeuren[0]->addSlot(verschillendeSloten[0]);
    verschillendeDeuren[1]->addSlot(verschillendeSloten[1]);
    verschillendeDeuren[2]->addSlot(verschillendeSloten[2]);
}

void MainWindow::paintEvent(QPaintEvent *event){

    QPainter painter(this);
    QPen pen;
   // QImage image("D:\\C++\\Qt-Shizzle\\Gebouw.png");
    QImage image("C:\\C++\\Qt-Shizzle\\Gebouw.png");


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
            verschillendeSloten.at(0)->vergrendel();

        }

    } else {

        verschillendeDeuren.at(0)->open();
    }

    update();
}

void MainWindow::on_DraaiDeurKnop2_clicked()
{
    if (verschillendeDeuren.at(2)->isDeurOpen()){
        verschillendeDeuren.at(2)->sluit();
        verschillendeSloten.at(2)->vergrendel();
    } else{
        if (!verschillendeSloten.at(2)->isVergrendeld()) {
            verschillendeDeuren.at(2)->open();}
    }
    update();
}


void MainWindow::on_DraaiDeurKnop1_clicked()
{


        if (verschillendeDeuren.at(1)->isDeurOpen()){
            verschillendeDeuren.at(1)->sluit();
            verschillendeSloten.at(1)->vergrendel();
        }
        else {
            if (!verschillendeSloten.at(1)->isVergrendeld()) {

                verschillendeDeuren.at(1)->open();
            }
        }
        update();
    }

void MainWindow::on_lineEdit_returnPressed() //schuifdeur sleutelslot
{
    std::string ingevoerdeWaarde = ui->lineEdit->text().toStdString();
    ui->lineEdit->clear();


    verschillendeSloten.at(0)->ontgrendel(ingevoerdeWaarde);

}


void MainWindow::on_lineEdit_2_returnPressed() //draaideur codeslot 1
{
    std::string ingevoerdeCode1 = ui->lineEdit_2->text().toStdString();
    ui->lineEdit_2->clear();

    verschillendeSloten.at(1)->ontgrendel(ingevoerdeCode1);
}

void MainWindow::on_lineEdit_3_returnPressed() //draaideur code slot 2
{
    std::string ingevoerdeCode2 = ui->lineEdit_3->text().toStdString();
    ui->lineEdit_3->clear();

    verschillendeSloten.at(2)->ontgrendel(ingevoerdeCode2);
}
