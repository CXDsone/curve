#ifndef DIALOGSETUP_H
#define DIALOGSETUP_H

#include <QDialog>
#include <QFile>
#include <QButtonGroup>
#include <QTextStream>


namespace Ui {
class DialogSetup;
}

class DialogSetup : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSetup(QWidget *parent = 0);
    ~DialogSetup();

signals:
    void setData();

private slots:
    void on_PB_ok_clicked();

    void on_PB_cancel_clicked();

private:
    Ui::DialogSetup *ui;

    QButtonGroup *btnGrout;
};

#endif // DIALOGSETUP_H
