#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "uart4.h"
#include "save.h"
#include "dialogsetup.h"
#include <QMainWindow>
#include <QChartView>
#include <QButtonGroup>
#include <QMessageBox>
#include <QTimer>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QScreen>
#include <QTime>

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QChart>
#include <QtCharts/QChartGlobal>
#include <QtCharts/QValueAxis>
#include <QtCharts/QSplineSeries>

QT_CHARTS_BEGIN_NAMESPACE
class QChart;
QT_CHARTS_END_NAMESPACE
QT_CHARTS_USE_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void DesTimeRun();
    void noDestructive();       //非破坏性测试
    void noDesTimeRun();
private slots:

    void on_PB_check_clicked();

    void on_PB_save_clicked();

    void saveCurve();

    void Parameters();

    void on_PB_load_clicked();

    void on_PB_clean_clicked();

    void on_PB_allClean_clicked();

    void on_PB_clockwise_clicked();

    void on_PB_antiCLockwise_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_setup_triggered();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_PB_saveImage_clicked();

private:
    Ui::MainWindow *ui;

    Save *save;
    DialogSetup *dialogSetup;
    QTimer *timer;

    QChart *chart;
    QValueAxis *axisX;
    QValueAxis *axisY;
    QButtonGroup *btnGrout;
    QButtonGroup *btnGrout2;

    int Touch();
    int getValue();

    int Destructive();                  //破坏性测试
    void drawChart();
    void setItem(int row,int col,float value);
};

#endif // MAINWINDOW_H
