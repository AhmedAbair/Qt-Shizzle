#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hallsensor.h"
#include "deur.h"
#include "hallsensor.h"
#include "schuifdeur.h"
#include "draaideur.h"
#include "sleutelslot.h"
#include <memory.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class Sensor;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    ~MainWindow();

private slots:

    void on_SensorKnop_clicked();

    void on_SchuifDeurKnop_clicked();

    void on_DraaiDeurKnop2_clicked();

    void on_DraaiDeurKnop1_clicked();

    void on_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
    Sensor *s1;
    //HallSensor *hallsensortje;
    vector <shared_ptr<Deur>> verschillendeDeuren;
    std::shared_ptr<Sleutelslot> sleutelslotje1;
};
#endif // MAINWINDOW_H
