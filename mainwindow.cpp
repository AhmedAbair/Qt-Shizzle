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
    //Deuren vector
    verschillendeDeuren.push_back(std::make_shared<Schuifdeur>(503, 250, 80, dynamic_cast<HallSensor*>(s1)));
    verschillendeDeuren.push_back(std::make_shared<Draaideur>(295,290,30,true));
    verschillendeDeuren.push_back(std::make_shared<Draaideur>(248,140,40, false));
    //Sloten vectoren
    auto s1 = std::make_shared<Sleutelslot>("Ahmed", true);  // index 0
    auto c1 = std::make_shared<Codeslot>(1111, true);        // index 1
    auto s2 = std::make_shared<Sleutelslot>("Bas", true);    // index 2
    auto c2 = std::make_shared<Codeslot>(2222, true);        // index 3
    auto c3 = std::make_shared<Codeslot>(3333, true);        // index 4

    // SLOTEN TOEVOEGEN AAN LIJST
    verschillendeSloten.push_back(s1);  // 0
    verschillendeSloten.push_back(c1);  // 1
    verschillendeSloten.push_back(s2);  // 2
    verschillendeSloten.push_back(c2);  // 3
    verschillendeSloten.push_back(c3);  // 4

    // DEUREN TOEVOEGEN
    verschillendeDeuren[0]->addSlot(s1);  // schuifdeur
    verschillendeDeuren[0]->addSlot(c1);
    verschillendeDeuren[1]->addSlot(s2);  // draaideur 1
    verschillendeDeuren[1]->addSlot(c2);
    verschillendeDeuren[2]->addSlot(c3);  // draaideur 2
    // verschillendeSloten.push_back(std::make_shared<Sleutelslot>("Ahmed",true));
    // verschillendeSloten.push_back(std::make_shared<Codeslot>(1234,true));
    // verschillendeSloten.push_back(std::make_shared<Codeslot>(5678,true));

 //    auto sleutel1 = std::make_shared<Sleutelslot>("Ahmed", true);
 //    auto code1 = std::make_shared<Codeslot>(1111, true);
 //    auto sleutel2 = std::make_shared<Sleutelslot>("Bas", true);
 //    auto code2 = std::make_shared<Codeslot>(2222, true);
 //    auto code3 = std::make_shared<Codeslot>(3333, true);

 //    verschillendeSloten.push_back(sleutel1);
 //    verschillendeSloten.push_back(code1);
 //    verschillendeSloten.push_back(sleutel2);
 //    verschillendeSloten.push_back(code2);
 //    verschillendeSloten.push_back(code3);

 //    //sloten voor schuifdeur
 //  //  verschillendeDeuren[0]->addSlot(verschillendeSloten[0]);
 //    verschillendeDeuren[0]->addSlot(sleutel1);
 //    verschillendeDeuren[0]->addSlot(code1);
 //    //Sloten voor draaideur 1
 //  //  verschillendeDeuren[1]->addSlot(verschillendeSloten[1]);
 //    verschillendeDeuren[1]->addSlot(sleutel2);
 //    verschillendeDeuren[1]->addSlot(code2);
 //    //Sloten voor draaideur twee
 // //   verschillendeDeuren[2]->addSlot(verschillendeSloten[2]);
 //    verschillendeDeuren[2]->addSlot(code3);

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
            verschillendeSloten.at(1)->vergrendel();

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
        verschillendeSloten.at(4)->vergrendel();
    } else{
        if (!verschillendeSloten.at(4)->isVergrendeld()) {
            verschillendeDeuren.at(2)->open();}
    }
    update();
}


void MainWindow::on_DraaiDeurKnop1_clicked()
{


        if (verschillendeDeuren.at(1)->isDeurOpen()){
            verschillendeDeuren.at(1)->sluit();
            verschillendeSloten.at(2)->vergrendel();
            verschillendeSloten.at(3)->vergrendel();
        }
        else {
            if (!verschillendeSloten.at(3)->isVergrendeld() &&
                !verschillendeSloten.at(2)->isVergrendeld()) {

                verschillendeDeuren.at(1)->open();
            }
        }
        update();
    }

void MainWindow::on_lineEdit_returnPressed(){ //schuifdeur sleutelslot
    int index = 0;
    std::string ingevoerdeWaarde = ui->lineEdit->text().toStdString();
    ui->lineEdit->clear();

    for (auto it = verschillendeSloten.begin(); it != verschillendeSloten.end(); ++it, ++index) {
        if (index == 0 || index == 1) {
            (*it)->ontgrendel(ingevoerdeWaarde);
        }
    }

}

void MainWindow::on_lineEdit_2_returnPressed() //draaideur codeslot 1
{
    int index = 0;
    std::string ingevoerdeCode1 = ui->lineEdit_2->text().toStdString();
    ui->lineEdit_2->clear();

    for (auto it = verschillendeSloten.begin(); it != verschillendeSloten.end(); ++it, ++index) {
        if (index == 2 || index == 3) {
            (*it)->ontgrendel(ingevoerdeCode1);
        }
    }
}

void MainWindow::on_lineEdit_3_returnPressed() //draaideur code slot 2
{
    int index = 0;
    std::string ingevoerdeCode2 = ui->lineEdit_3->text().toStdString();
    ui->lineEdit_3->clear();

    for (auto it = verschillendeSloten.begin(); it != verschillendeSloten.end(); ++it, ++index) {
        if (index == 4) {
            (*it)->ontgrendel(ingevoerdeCode2);
        }
 // verschillendeSloten.at(4)->ontgrendel(ingevoerdeCode2);
   // verschillendeSloten.at(2)->ontgrendel(ingevoerdeCode2);
}
}
