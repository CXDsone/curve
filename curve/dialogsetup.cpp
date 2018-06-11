#include "dialogsetup.h"
#include "ui_dialogsetup.h"

DialogSetup::DialogSetup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSetup)
{
    ui->setupUi(this);
    btnGrout = new QButtonGroup(this);
    btnGrout->addButton(ui->RB_N,0);
    btnGrout->addButton(ui->RB_G,1);
    btnGrout->addButton(ui->radioButton_3,2);
    QString fileName = "./setup.csv";
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QStringList tempbar = in.readAll().split(",");
    QString str = tempbar.at(0);
    switch (str.toInt()) {
    case 0:
        ui->RB_N->setChecked(true);
        break;
    case 1:
        ui->RB_G->setChecked(true);
        break;
    case 2:
        ui->radioButton_3->setChecked(true);
    }
    ui->lineEdit_4->setText(tempbar.at(1));
    ui->lineEdit->setText(tempbar.at(2));
    ui->lineEdit_2->setText(tempbar.at(3));
    ui->lineEdit_3->setText(tempbar.at(4));
    ui->lineEdit_5->setText(tempbar.at(5));
    ui->lineEdit_6->setText(tempbar.at(6));
    file.close();
}

DialogSetup::~DialogSetup()
{
    delete ui;
}

void DialogSetup::on_PB_ok_clicked()
{
    QString fileName = "./setup.csv";
    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QTextStream out(&file);
    QString str_rbID,armLength,maxAngle,touchAngle,runAngle,range_X,range_Y;
    int rbID = btnGrout->checkedId();
    str_rbID = QString::number(rbID,10);
    armLength = ui->lineEdit_4->text();
    maxAngle = ui->lineEdit->text();
    touchAngle = ui->lineEdit_2->text();
    runAngle = ui->lineEdit_3->text();
    range_X = ui->lineEdit_5->text();
    range_Y = ui->lineEdit_6->text();
    out<<str_rbID<<","<<armLength<<","<<maxAngle<<","<<touchAngle<<","<<runAngle<<","<<range_X<<","<<range_Y<<",";
    file.close();
    emit setData();
    this->deleteLater();
}

void DialogSetup::on_PB_cancel_clicked()
{
    this->deleteLater();
}
