#include "save.h"
#include "ui_save.h"


Save::Save(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Save)
{
    ui->setupUi(this);
    qDebug("%d",curvesNum);
    ui->tableWidget->setRowCount((curvesNum-1)/5+1);
    for(int i = 0;i<curvesNum;i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(QString::number(i+1,10));
        ui->tableWidget->setItem(i/5,i%5,item);
    }
}

Save::~Save()
{
    delete ui;
}

void Save::on_PB_save_clicked()
{

    QList<QTableWidgetItem*>items = ui->tableWidget->selectedItems();
    int count = items.count();
    qDebug("len:%d",count);
    curves[0] = count;
    qDebug("len:%d",curves[0]);
    for(int i = 0;i<count;i++)
    {
        QString str= items.at(i)->text();
        curves[i+1] = str.toInt();
    }
    emit setData();
    this->close();
}

void Save::on_PB_cancel_clicked()
{
    this->deleteLater();
}
