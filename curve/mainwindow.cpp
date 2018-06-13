#include "mainwindow.h"
#include "ui_mainwindow.h"

QT_CHARTS_USE_NAMESPACE

int serial;
int curvesNum = 0;
int curves[512];
int row_save;
int loadPoint[512];
float anglePoint[512];
int tim = 0;
int msec = 200;
int middle = 0;
QByteArray dataRead;
float set_angle;
float min_angle;
float multiple;

/**
 * @brief setParameters
 * 0：单位，0 N ,1 g
 * 1：力臂长
 * 2：破坏性最大角度
 * 3：接触前步距
 * 4：接触后步距
 * 5：x轴最大
 * 6：y轴最大
 */
int setParameters[7];



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(!createSerialPort(9600))
    {
        qDebug("串口打开失败");
        delete ui;
    }
    btnGrout = new QButtonGroup(this);
    btnGrout->addButton(ui->RB_Destructive,0);
    btnGrout->addButton(ui->RB_noDestructive,1);
    ui->RB_noDestructive->setChecked(true);
    btnGrout2 = new QButtonGroup(this);
    btnGrout2->addButton(ui->RB_N,0);
    btnGrout2->addButton(ui->RB_G,1);
    ui->RB_G->setChecked(true);
    QString fileName = "./angle.csv";
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QStringList tempbar = in.readAll().split(",");
    QString str;
    str = tempbar.at(0);
    ui->LE_angel->setText(str);
    file.close();
    chart = new QChart();
    axisX = new QValueAxis; //定义X轴
    axisX->setGridLineVisible(true); //设置是否显示网格线
    axisX->setMinorTickCount(4); //设置小刻度线的数目
    // axisX->setLabelsVisible(false); //设置刻度是否显示

    axisY = new QValueAxis;
    axisY->setTitleText("角度");
    axisY->setLabelFormat("%.1f");
    axisY->setGridLineVisible(true);
    axisY->setMinorTickCount(4);
    //导入设置参数
    Parameters();
    chart->legend()->hide();
}

MainWindow::~MainWindow()
{
    QString fileName = "./angle.csv";
    QFile file(fileName);
    file.open(QIODevice::WriteOnly | QIODevice::Truncate);
    QTextStream out(&file);
    QString str;
    str = ui->LE_angel->text();
    out<<str<<",";
    file.close();
    delete ui;
}

void MainWindow::setItem(int row,int col,float value)
{
    QTableWidgetItem *item = new QTableWidgetItem;
    qDebug("%f",value);
    QString data = QString("%1").arg(value);
    item->setText(data);
    ui->TW_csv->setItem(row,col,item);
}

int MainWindow::Touch()
{
    int message;
    if(wait4RunMotor(1)==-1)
        return -1;
    while(wait4GetStop(1));
    message = wait4GetSwitch(1);
    if(message == 1)
        return 1;
    else if(message == 0)
        return 0;
    else
        return -1;
}

int MainWindow::getValue()
{
    long load;
    load = wait4GetLoad(2);
    if(load == -1)
        return -1;
    else
    {
        return load;
    }
}

void MainWindow::noDestructive()
{
    QTime *t = new QTime();
    t->start();
    int value = getValue();
    int message = wait4GetStop(1);
    if(message == 1)
    {
        tim++;
        loadPoint[tim] = value;
        anglePoint[tim] = tim*((double)360/60000*msec);
        qDebug("%d",t->elapsed());
    }
    else if(message == 0)
    {
        timer->stop();
        qDebug("tim：");
        qDebug("%d",tim);
        timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()),this,SLOT(noDesTimeRun()));
        wait4Setup(1,0,10);
        middle = tim;
        wait4RunMotor(1);
        timer->start(msec);
    }
}

void MainWindow::noDesTimeRun()
{
    int value = getValue();
    int message = wait4GetStop(1);
    if(message == 1)
    {
        tim++;
        loadPoint[tim] = value;
        anglePoint[tim] = anglePoint[tim-1]-((double)360/60000*msec);
        if(anglePoint[tim]<0)
        {
            anglePoint[tim] = 0;
        }

    }
    else if(message == 0)
    {
        tim++;
        loadPoint[tim] = value;
        anglePoint[tim] = anglePoint[tim-1]-((double)360/60000*msec);
        if(anglePoint[tim]<0)
        {
            anglePoint[tim] = 0;
        }
        timer->stop();
        int i = 0;
        QLineSeries *Series = new QLineSeries();
        QLineSeries *Series2= new QLineSeries();
        for(; i <= middle;i++)
        {
            Series->append((loadPoint[i]-loadPoint[0])*multiple,anglePoint[i]);
        }
        for(i=middle;i<tim+1;i++)
        {
            Series2->append((loadPoint[i]-loadPoint[0])*multiple,anglePoint[i]);
        }
        qDebug("Charts");
        chart->addSeries(Series);
        chart->setAxisX(axisX, Series);
        chart->setAxisY(axisY, Series);
        QPen pen = Series->pen();
        Series2->setPen(pen);
        chart->legend()->hide();
        chart->addSeries(Series2);
        chart->setAxisX(axisX, Series2);
        chart->setAxisY(axisY, Series2);
        ui->graphicsView->setChart(chart);
        int row_count = ui->TW_csv->rowCount();
        int col_count = ui->TW_csv->columnCount();
        ui->TW_csv->setColumnCount(col_count+2);
        if(row_count<tim+1)
            ui->TW_csv->setRowCount(tim+1);
        for(int j = 0;j < tim+1;j++)
        {
            setItem(j,col_count,anglePoint[j]);
            setItem(j,col_count+1,loadPoint[j]-loadPoint[0]);
        }
        QTableWidgetItem *item = ui->TW_csv->item(middle,col_count);
        item->setBackgroundColor(QColor(255,255,0));
        item = ui->TW_csv->item(middle,col_count+1);
        item->setBackgroundColor(QColor(255,255,0));
    }
}

void MainWindow::Destructive()
{
    GetLoad(2);
    waitTaskInfo(50);
//    dataRead += serialRead();
    GetSwitch(1);
    waitTaskInfo(10);
    dataRead += serialRead();
//    readDes();
}

void MainWindow::readDes()
{
    int signal = 0;
    QByteArray loadHead;
    loadHead[0] = 0x02;
    loadHead[1] = 0x03;
    QByteArray switchHead;
    switchHead[0] = 0x01;
    switchHead[1] = 0x02;
    while(dataRead.size()>=6)
    {
        if(signal%2 == 0)
        {
            //查询压力值
            int head = dataRead.indexOf(loadHead);
            if(head>=0)
            {
                dataRead.remove(0,head);
                if(dataRead.size() >= 9)
                {
                    unsigned char checkSum[2];
                    unsigned char data[7];
                    memset(checkSum,0,2);
                    memset(data,0,7);
                    for(int i=0;i<7;i++)
                        data[i] = (unsigned char)(dataRead.at(i));
                    unsigned short CRC = CRC_GetModbus16(data,7);
                    checkSum[0] = CRC%256;
                    checkSum[1] = CRC/256;
                    if((unsigned char)(dataRead.at(7)) == checkSum[0]&&(unsigned char)(dataRead.at(8)) == checkSum[1])
                    {
                        loadPoint[signal/2] = (unsigned char)(dataRead.at(4))
                              +((unsigned char)(dataRead.at(3))<<8)
                              +((unsigned char)(dataRead.at(6))<<16)
                              +((unsigned char)(dataRead.at(5))<<32);
                        anglePoint[signal/2] = (signal/2)*((double)360/60000*msec);
                        qDebug("%d",loadPoint);
                    }
                    signal++;
                    dataRead.remove(0,9);
                }
            }
        }
        if(signal%2 == 1)
        {
            int head = dataRead.indexOf(switchHead);
            if(head>=0)
            {
                dataRead.remove(0,head);
                if(dataRead.size() >= 6)
                {
                    unsigned char checkSum[2];
                    unsigned char data[4];
                    memset(checkSum,0,2);
                    memset(data,0,4);
                    for(int i=0;i<4;i++)
                        data[i] = (unsigned char)(dataRead.at(i));
                    unsigned short CRC = CRC_GetModbus16(data,4);
                    checkSum[0] = CRC%256;
                    checkSum[1] = CRC/256;
                    if((unsigned char)(dataRead.at(4)) == checkSum[0]||(unsigned char)(dataRead.at(5)) == checkSum[1])
                    {
                        dataRead.remove(0,6);
                        if(data[3] == 0x00)
                        {
                            qDebug("CID:I4 OFF");
                            break;
                        }

                    }
                    signal++;
                    dataRead.remove(0,6);
                }
            }
        }
    }
    //绘制曲线
    wait4StopRun(1);
    timer->stop();
    QLineSeries *series = new QLineSeries();
    int row_count = ui->TW_csv->rowCount();
    int col_count = ui->TW_csv->columnCount();
    ui->TW_csv->setColumnCount(col_count+2);
    if(row_count<tim+1)
        ui->TW_csv->setRowCount(tim+1);
    for(int i = 0; i < tim; i++) {
        series->append((loadPoint[i]-loadPoint[0])*multiple,i*((double)360/60000*msec));
        setItem(i,col_count,i*((double)360/60000*msec));
        setItem(i,col_count+1,loadPoint[i]-loadPoint[0]);
    }
    series->append(0,(tim+1)*((double)360/60000*msec));
    setItem(tim+1,col_count,(tim+1)*((double)360/60000*msec));
    setItem(tim+1,col_count+1,0);
    chart->addSeries(series);
    chart->setAxisX(axisX, series);
    chart->setAxisY(axisY, series);
    ui->graphicsView->setChart(chart);
    qDebug("%f",(double)360/60000*msec);
    //最大值高亮
}

void MainWindow::on_PB_check_clicked()
{
    int rbID = btnGrout->checkedId();
    timer = new QTimer(this);
    memset(loadPoint,0,512);
    memset(anglePoint,0,512);
    dataRead.clear();
    wait4Setup(1,1,10);
    wait4SetPul(1,40000*setParameters[2]/360);
    wait4RunMotor(1);
    while(!wait4GetSwitch(1));
    wait4StopRun(1);
    //破坏性测试
    if(rbID == 0)
    {
        connect(timer,SIGNAL(timeout()),this,SLOT(Destructive()));
        wait4SetPul(1,40000*setParameters[2]/360);
        wait4RunMotor(1);
        timer->start(msec);
    }
    //非破坏性测试
    else if(rbID == 1)
    {
        QString str = ui->LE_angel->text();
        int angel = str.toInt();
        connect(timer,SIGNAL(timeout()),this,SLOT(noDestructive()));
        tim = 0;
        loadPoint[tim] = getValue();
        anglePoint[tim] = 0;
        wait4SetPul(1,40000*angel/360);
        wait4RunMotor(1);
        timer->start(msec);
    }
    else
    {
        QMessageBox *messagebox = new QMessageBox(QMessageBox::Warning,"警告","请选择测试模式");
        QTimer::singleShot(10000,messagebox,SLOT(accept()));
        messagebox->show();
    }
}

void MainWindow::on_PB_save_clicked()
{
    row_save = ui->TW_csv->rowCount();
    curvesNum = ui->TW_csv->columnCount();
    curvesNum = curvesNum/2;
    waitTaskInfo(10);
    save = new Save;
    connect(save,SIGNAL(setData()),this,SLOT(saveCurve()));
    save->exec();
}

void MainWindow::saveCurve()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("save Config"),qApp->applicationDirPath(),tr("File(*.csv"));
    if (fileName.isEmpty())
          return;
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }
    QTextStream out(&file);
    int len = curves[0];
    qDebug("len:%d",len);
    for (int i = 0;i<len;i++)
    {
        int col = curves[i+1];
        for(int j = 0; j < row_save; j++)
        {
            if(ui->TW_csv->item(j,(col*2-2))==0)
            {
                break;
            }
            else
            {
                QString string = ui->TW_csv->item(j,(col*2-2))->text();
                out << string << ",";// 写入文件
            }
        }
        out<<"\n";
        for(int j = 0; j < row_save; j++)
        {
            if(ui->TW_csv->item(j,(col*2-1))==0)
            {
                break;
            }
            else
            {
                QString string = ui->TW_csv->item(j,(col*2-1))->text();
                out << string << ",";// 写入文件
            }
        }
        out<<"\n";
    }
    file.close();
}

void MainWindow::Parameters()
{
    QString fileName = "./setup.csv";
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QTextStream in(&file);
    QStringList tempbar = in.readAll().split(",");
    QString str;
    for(int i = 0;i<7;i++)
    {
        str = tempbar.at(i);
        if(i==3||i==4)
            setParameters[i] = str.toFloat()*10000/36;
        else
        {
            setParameters[i] = str.toInt();
        }
    }
    set_angle = setParameters[4]*0.0036;
    min_angle = setParameters[3]*0.0036;
    char buf[10];
    sprintf(buf, "%.3f", set_angle);
    sscanf(buf, "%f", &set_angle);
    char buf2[10];
    sprintf(buf2, "%.3f", min_angle);
    sscanf(buf2, "%f", &min_angle);
    if(setParameters[0] == 0)
    {
        multiple = 0.0098;
        axisX->setRange(0,setParameters[5]*multiple); //设置范围
        axisX->setTitleText("力(N)"); //设置X轴的标题
        axisY->setRange(0,setParameters[6]);
    }
    else if(setParameters[0] == 1)
    {
        multiple = 1;
        axisX->setRange(0, setParameters[5]); //设置范围
        axisX->setTitleText("力(g)"); //设置X轴的标题
        axisY->setRange(0,setParameters[6]);
    }
}

void MainWindow::on_PB_load_clicked()
{
    int col_count = ui->TW_load->columnCount();
    QString fileName = QFileDialog::getOpenFileName(this,tr("Excel file"),qApp->applicationDirPath(),tr("Files(*.csv)"));
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&file);
    QStringList tempOption = in.readAll().split("\n");

    int col = tempOption.count()-1;
    ui->TW_load->setColumnCount(col_count+col);
    for(int i = 0; i < col; i++)
    {
        QStringList tempbar = tempOption.at(i).split(",");
        int row = tempbar.count()-1;
        int row_count = ui->TW_load->rowCount();
        if(row_count<row)
            ui->TW_load->setRowCount(row);
        for(int j = 0;j<row;j++)
        {
            ui->TW_load->setItem(j,col_count+i,new QTableWidgetItem(tempbar.at(j)));
        }
    }
    file.close();

    int load_col = ui->TW_load->columnCount();
    int load_row = ui->TW_load->rowCount();

    for(int i = 0; i<load_col/2;i++)
    {
        QLineSeries *Series = new QLineSeries();
        QLineSeries *Series2= new QLineSeries();
        int sign = 0;
        double int_angle = 0;
        double int_value;
        for(int j = 0;j<load_row;j++)
        {
            double int_angle_last = int_angle;
            QString str_value;
            str_value = ui->TW_load->item(j,i*2+1)->text();
            int_value = str_value.toDouble();
            QString str_angle;
            str_angle = ui->TW_load->item(j,i*2)->text();
            int_angle = str_angle.toDouble();
            if(int_angle_last > int_angle)
            {
                sign = 1;
                Series2->append(int_value*multiple,int_angle);
            }
            else
            {
                Series->append(int_value*multiple,int_angle);
            }
        }
        chart->addSeries(Series);
        chart->setAxisX(axisX, Series);
        chart->setAxisY(axisY, Series);
        if(sign == 1)
        {
            QPen pen =  Series->pen();
            Series2->setPen(pen);
            chart->addSeries(Series2);
            chart->legend()->hide();
            chart->setAxisX(axisX, Series2);
            chart->setAxisY(axisY, Series2);
        }
        ui->graphicsView->setChart(chart);
    }
}

void MainWindow::on_PB_clean_clicked()
{
    ui->TW_csv->setColumnCount(0);
    ui->TW_csv->setRowCount(0);
    chart = new QChart();
    ui->graphicsView->setChart(chart);
    int load_col = ui->TW_load->columnCount();
    int load_row = ui->TW_load->rowCount();
    for(int i = 0; i<load_col/2;i++)
    {
        QLineSeries *Series = new QLineSeries();
        QLineSeries *Series2= new QLineSeries();
        int sign = 0;
        double int_angle = 0;
        double int_value;
        for(int j = 0;j<load_row;j++)
        {
            double int_angle_last = int_angle;
            QString str_value;
            str_value = ui->TW_load->item(j,i*2+1)->text();
            int_value = str_value.toDouble();
            QString str_angle;
            str_angle = ui->TW_load->item(j,i*2)->text();
            int_angle = str_angle.toDouble();
            if(int_angle_last > int_angle)
            {
                sign = 1;
                Series2->append(int_value*multiple,int_angle);
            }
            else
            {
                Series->append(int_value*multiple,int_angle);
            }
        }
        chart->addSeries(Series);
        chart->setAxisX(axisX, Series);
        chart->setAxisY(axisY, Series);
        if(sign == 1)
        {
            QPen pen =  Series->pen();
            Series2->setPen(pen);
            chart->legend()->hide();
            chart->addSeries(Series2);
            chart->setAxisX(axisX, Series2);
            chart->setAxisY(axisY, Series2);
        }
        ui->graphicsView->setChart(chart);
    }
}

void MainWindow::on_PB_allClean_clicked()
{
    ui->TW_csv->setColumnCount(0);
    ui->TW_csv->setRowCount(0);
    ui->TW_load->setColumnCount(0);
    ui->TW_load->setRowCount(0);
    chart = new QChart();
    ui->graphicsView->setChart(chart);
}

void MainWindow::on_PB_clockwise_clicked()
{
    wait4SetPul(1,275);
    wait4Setup(1,1,500);
    wait4RunMotor(1);
    while(wait4GetStop(1));
    wait4SetPul(1,250);
}

void MainWindow::on_PB_antiCLockwise_clicked()
{
    wait4SetPul(1,275);
    wait4Setup(1,0,500);
    wait4RunMotor(1);
    while(wait4GetStop(1));
}

void MainWindow::on_pushButton_clicked()
{
    wait4SetPul(1,1375);
    wait4Setup(1,0,500);
    wait4RunMotor(1);
}

void MainWindow::on_pushButton_2_clicked()
{
    wait4SetPul(1,1375);
    wait4Setup(1,1,500);
    wait4RunMotor(1);
}

void MainWindow::on_pushButton_3_clicked()
{
    int value = getValue();
    int rbID = btnGrout2->checkedId();
    if(rbID == 0)
    {
        QString str = QString("%1").arg(value*0.0098);
        ui->LE_value->setText(str);
    }
    else if(rbID == 1)
    {
        QString str = QString("%1").arg(value);
        ui->LE_value->setText(str);
    }
}

void MainWindow::on_setup_triggered()
{
    dialogSetup = new DialogSetup;
    connect(dialogSetup,SIGNAL(setData()),this,SLOT(Parameters()));
    dialogSetup->exec();
}

void MainWindow::on_pushButton_4_clicked()
{
    wait4SetPul(1,55);
    wait4Setup(1,0,500);
    wait4RunMotor(1);
}

void MainWindow::on_pushButton_5_clicked()
{
    wait4SetPul(1,55);
    wait4Setup(1,1,500);
    wait4RunMotor(1);
}

void MainWindow::on_PB_saveImage_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("save Config"),qApp->applicationDirPath(),tr("File(*.png"));
    if (fileName.isEmpty())
          return;
    QScreen * screen = QGuiApplication::primaryScreen();
    QPixmap p = screen->grabWindow(ui->graphicsView->winId());
    QImage image = p.toImage();
    image.save(fileName);
}
