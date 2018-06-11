#ifndef SAVE_H
#define SAVE_H

#include <QDialog>
#include <QTableWidgetItem>

extern int curvesNum;
extern int curves[];

namespace Ui {
class Save;
}

class Save : public QDialog
{
    Q_OBJECT

public:
    explicit Save(QWidget *parent = 0);
    ~Save();

signals:
    void setData();

private slots:
    void on_PB_save_clicked();

    void on_PB_cancel_clicked();

private:
    Ui::Save *ui;
};

#endif // SAVE_H
