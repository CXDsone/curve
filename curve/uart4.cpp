#include "uart4.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/time.h>
#include <dirent.h>
#include <string.h>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QElapsedTimer>
#include <QCoreApplication>
#include <QByteArray>

QSerialPort* myCom;
int load;

void waitTaskInfo(int tim)
{
    QElapsedTimer t;
    t.start();
    while(t.elapsed()<tim)
    {
        QCoreApplication::processEvents();
    }
}

bool createSerialPort(unsigned int baudRate)
{
    myCom= new QSerialPort();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        qDebug() << "Name        : " << info.portName();
        qDebug() << "Description : " << info.description();
        qDebug() << "Manufacturer: " << info.manufacturer();
        myCom->setPortName(info.portName());

    }
    if(myCom->open(QIODevice::ReadWrite))
    {
        myCom->setFlowControl(QSerialPort::NoFlowControl);
        myCom->setBaudRate(baudRate);
        myCom->setDataBits(QSerialPort::Data8);
        myCom->setParity(QSerialPort::NoParity);
        myCom->setStopBits(QSerialPort::OneStop);
        return true;
    }
    else
        return false;
}

void setSerialPort(unsigned int baudRate)
{
    myCom->setBaudRate(baudRate);
}

void closeSerialPort()
{
    myCom->close();
    qDebug("串口关闭");
}
unsigned short GetRevCrc_16(unsigned char * pData, int nLength,unsigned short init, const unsigned short *ptable)
{
  unsigned short cRc_16 = init;
  unsigned char temp;

  while(nLength-- > 0)
  {
    temp = cRc_16 & 0xFF;
    cRc_16 = (cRc_16 >> 8) ^ ptable[(temp ^ *pData++) & 0xFF];
  }

  return cRc_16;
}

//Demo -- modbus-crc16测试
unsigned short CRC_GetModbus16(unsigned char *pdata, int len)
{
    //MODBUS CRC-16表 8005 逆序
    const unsigned short g_McRctable_16[256] =
    {
        0x0000, 0xC0C1, 0xC181, 0x0140, 0xC301, 0x03C0, 0x0280, 0xC241,
        0xC601, 0x06C0, 0x0780, 0xC741, 0x0500, 0xC5C1, 0xC481, 0x0440,
        0xCC01, 0x0CC0, 0x0D80, 0xCD41, 0x0F00, 0xCFC1, 0xCE81, 0x0E40,
        0x0A00, 0xCAC1, 0xCB81, 0x0B40, 0xC901, 0x09C0, 0x0880, 0xC841,
        0xD801, 0x18C0, 0x1980, 0xD941, 0x1B00, 0xDBC1, 0xDA81, 0x1A40,
        0x1E00, 0xDEC1, 0xDF81, 0x1F40, 0xDD01, 0x1DC0, 0x1C80, 0xDC41,
        0x1400, 0xD4C1, 0xD581, 0x1540, 0xD701, 0x17C0, 0x1680, 0xD641,
        0xD201, 0x12C0, 0x1380, 0xD341, 0x1100, 0xD1C1, 0xD081, 0x1040,
        0xF001, 0x30C0, 0x3180, 0xF141, 0x3300, 0xF3C1, 0xF281, 0x3240,
        0x3600, 0xF6C1, 0xF781, 0x3740, 0xF501, 0x35C0, 0x3480, 0xF441,
        0x3C00, 0xFCC1, 0xFD81, 0x3D40, 0xFF01, 0x3FC0, 0x3E80, 0xFE41,
        0xFA01, 0x3AC0, 0x3B80, 0xFB41, 0x3900, 0xF9C1, 0xF881, 0x3840,
        0x2800, 0xE8C1, 0xE981, 0x2940, 0xEB01, 0x2BC0, 0x2A80, 0xEA41,
        0xEE01, 0x2EC0, 0x2F80, 0xEF41, 0x2D00, 0xEDC1, 0xEC81, 0x2C40,
        0xE401, 0x24C0, 0x2580, 0xE541, 0x2700, 0xE7C1, 0xE681, 0x2640,
        0x2200, 0xE2C1, 0xE381, 0x2340, 0xE101, 0x21C0, 0x2080, 0xE041,
        0xA001, 0x60C0, 0x6180, 0xA141, 0x6300, 0xA3C1, 0xA281, 0x6240,
        0x6600, 0xA6C1, 0xA781, 0x6740, 0xA501, 0x65C0, 0x6480, 0xA441,
        0x6C00, 0xACC1, 0xAD81, 0x6D40, 0xAF01, 0x6FC0, 0x6E80, 0xAE41,
        0xAA01, 0x6AC0, 0x6B80, 0xAB41, 0x6900, 0xA9C1, 0xA881, 0x6840,
        0x7800, 0xB8C1, 0xB981, 0x7940, 0xBB01, 0x7BC0, 0x7A80, 0xBA41,
        0xBE01, 0x7EC0, 0x7F80, 0xBF41, 0x7D00, 0xBDC1, 0xBC81, 0x7C40,
        0xB401, 0x74C0, 0x7580, 0xB541, 0x7700, 0xB7C1, 0xB681, 0x7640,
        0x7200, 0xB2C1, 0xB381, 0x7340, 0xB101, 0x71C0, 0x7080, 0xB041,
        0x5000, 0x90C1, 0x9181, 0x5140, 0x9301, 0x53C0, 0x5280, 0x9241,
        0x9601, 0x56C0, 0x5780, 0x9741, 0x5500, 0x95C1, 0x9481, 0x5440,
        0x9C01, 0x5CC0, 0x5D80, 0x9D41, 0x5F00, 0x9FC1, 0x9E81, 0x5E40,
        0x5A00, 0x9AC1, 0x9B81, 0x5B40, 0x9901, 0x59C0, 0x5880, 0x9841,
        0x8801, 0x48C0, 0x4980, 0x8941, 0x4B00, 0x8BC1, 0x8A81, 0x4A40,
        0x4E00, 0x8EC1, 0x8F81, 0x4F40, 0x8D01, 0x4DC0, 0x4C80, 0x8C41,
        0x4400, 0x84C1, 0x8581, 0x4540, 0x8701, 0x47C0, 0x4680, 0x8641,
        0x8201, 0x42C0, 0x4380, 0x8341, 0x4100, 0x81C1, 0x8081, 0x4040
    };
  return GetRevCrc_16(pdata, len, 0xFFFF, g_McRctable_16);
}

char uartCheckSum(char* data, int num) //校验码
{
    char sum = 0;
    int i = 0;
    for(i = 0; i < num; i++)
        sum += *(data + i);
    return sum;
}



void PackageSend1(QSerialPort* uartfd,int DID, struct Package1 data)
{
    data.DevID = DID;
    unsigned char pdata[6];
    pdata[0] = data.DevID;
    pdata[1] = data.CmdID;
    pdata[2] = data.RegisterAddress[0];
    pdata[3] = data.RegisterAddress[1];
    pdata[4] = data.RegisterNum[0];
    pdata[5] = data.RegisterNum[1];
    unsigned short CRC = CRC_GetModbus16(pdata,6);
    data.CheckSum[0] = CRC%256;
    data.CheckSum[1] = CRC/256;

    QByteArray dataMsg;
    dataMsg.resize(8);
    memcpy(dataMsg.data(),&data,8);
    uartfd->write(dataMsg,8);
}

void GetLoad(QSerialPort* uartfd,int DID)//0x03 获取载重
{
    struct Package1 Pack;
    Pack.CmdID =CID_GET_LOAD;
    Pack.RegisterAddress[0] = 0x00;
    Pack.RegisterAddress[1] = 0x00;

    Pack.RegisterNum[0] = 0x00;
    Pack.RegisterNum[1] = 0x02;

    PackageSend1(uartfd,DID,Pack);
}


void GetSwitch(QSerialPort *uartfd, int DID)
{
    struct Package1 Pack;
    Pack.CmdID = CID_GET_SWITCH;
    Pack.RegisterAddress[0] = 0x00;
    Pack.RegisterAddress[1] = 0x00;

    Pack.RegisterNum[0] = 0X00;
    Pack.RegisterNum[1] = 0X08;

    PackageSend1(uartfd,DID,Pack);
}

int wait4GetLoad(int DID)//发送获取载重指令
{
    int i,j;
    for(i=0;i<3;i++)
    {
        GetLoad(myCom,DID);
        for(j=0;j<5;j++)
        {
            int rtnState = readData1(DID);
            if (rtnState == STATE_GET_LOAD)
            {
                if(load>0xf0000000)
                    return 0;
                qDebug("Get Load OK!");
                return load;
            }
        }
    }
    return -1;
}

int wait4GetSwitch(int DID)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        GetSwitch(myCom,DID);
        for(j=0;j<5;j++)
        {
            int rtnState = readData1(DID);
            if (rtnState == STATE_SWITCH_OFF)
            {
                qDebug("SWITCH OFF!");
                return 0;
            }
            else if(rtnState ==STATE_SWITCH_ON)
            {
                qDebug("SWITCH ON!");
                return 1;
            }
        }
    }
    return -1;
}

int readData1(int DID)
{
    int i,j;
    for(j=0;j<10;j++)
    {
        waitTaskInfo(50);
        if(myCom->bytesAvailable()>=6)
        {
            QByteArray alldata = myCom->readAll();
//            qDebug("Data recv %d.", alldata.count());
            for(i=0;i<=alldata.size();i++)
             {
                 if((alldata.at(i) == DID))
                     break;
             }
            int pHead = i;
            unsigned char CID = 0;
            CID=(unsigned char)(alldata.at(pHead+1));
            if(CID == CID_GET_SWITCH)
            {
                if((alldata.size()-pHead) < 6)
                {
                    waitTaskInfo(10);
                    alldata += myCom->readAll();
                }
                unsigned char checkSum[2];
                unsigned char data[4];
                memset(checkSum,0,2);
                memset(data,0,4);
                for(i=pHead;i<pHead+4;i++)
                    data[i-pHead] = (unsigned char)(alldata.at(i));
                unsigned short CRC = CRC_GetModbus16(data,4);
                checkSum[0] = CRC%256;
                checkSum[1] = CRC/256;
                if((unsigned char)(alldata.at(i)) != checkSum[0]||(unsigned char)(alldata.at(i+1)) != checkSum[1])
                {
                    qDebug("Check Sum Error!\n");
                    alldata.clear();
                    return STATE_ERROR;
                }
                else
                {
                    if(data[3]==0x01)
                    {
                        qDebug("CID:I4 ON");
                        return STATE_SWITCH_ON;
                    }
                    else if(data[3] == 0x00)
                    {
                        qDebug("CID:I4 OFF");
                        return STATE_SWITCH_OFF;
                    }
                    else
                        return STATE_ERROR;
                }
            }
            else if(CID == CID_GET_LOAD)
            {
                while((alldata.size()-pHead) < 9)
                {
                    waitTaskInfo(10);
                    alldata += myCom->readAll();
                }
                unsigned char checkSum[2];
                unsigned char data[7];
                memset(checkSum,0,2);
                memset(data,0,7);
                for(i=pHead;i<pHead+7;i++)
                    data[i-pHead] = (unsigned char)(alldata.at(i));
                unsigned short CRC = CRC_GetModbus16(data,7);
                checkSum[0] = CRC%256;
                checkSum[1] = CRC/256;
                if((unsigned char)(alldata.at(i)) != checkSum[0]||(unsigned char)(alldata.at(i+1)) != checkSum[1])
                {
                    qDebug("Check Sum Error!\n");
                    alldata.clear();
                    return STATE_ERROR;
                }
                else
                {
                    load = (unsigned char)(alldata.at(pHead+4))
                          +((unsigned char)(alldata.at(pHead+3))<<8)
                          +((unsigned char)(alldata.at(pHead+6))<<16)
                          +((unsigned char)(alldata.at(pHead+5))<<32);
                    return STATE_GET_LOAD;
                }
            }
            else
            {
                qDebug("CID ERROR");
                return STATE_ERROR;
            }
        }
    }
    return STATE_ERROR;
}

/*********************************控制电机************************************/
void PackageSend2(QSerialPort* uartfd,int DID, struct Package2 data)
{
    data.Header[0] = 0xff;
    data.Header[1] = 0xaa;
    data.DevID[0] = DID;
    data.DevID[1] = 0x03;
    data.CheckSum = uartCheckSum(&data.Header[0],9);

    QByteArray dataMsg;
    dataMsg.resize(10);
    memcpy(dataMsg.data(),&data,10);
    uartfd->write(dataMsg,10);
}

void getStop(QSerialPort *uartfd, int DID)
{
    struct Package2 P1;
    P1.CmdID = CID_GET_STOP;
    memset(P1.Data,0,4);

    PackageSend2(uartfd,DID,P1);
}

void Forward(QSerialPort *uartfd, int DID)
{
    struct Package2 P1;
    P1.CmdID = CID_FORWARD;
    memset(P1.Data,0,4);

    PackageSend2(uartfd,DID,P1);
}

void StopRun(QSerialPort *uartfd, int DID)
{
    struct Package2 P1;
    P1.CmdID = CID_STOP_RUN;
    memset(P1.Data,0,4);

    PackageSend2(uartfd,DID,P1);
}

void SetPul(QSerialPort *uartfd, int DID, int pulnum)
{
    struct Package2 P1;
    P1.CmdID = CID_SET_PUL;
    P1.Data[0] = pulnum%256;
    P1.Data[1] = pulnum%65536/256;
    P1.Data[2] = pulnum/65536;
    P1.Data[3] = 0x00;

    PackageSend2(uartfd,DID,P1);
}

void Setup(QSerialPort* uartfd,int DID,int direction, int frequency) //0 反转，1 正转
{
    struct Package2 P1;
    P1.CmdID = CID_SETUP;
    P1.Data[0] = direction;
    P1.Data[1] = frequency%256;
    P1.Data[2] = frequency/256;
    P1.Data[3] = 0x00;

    PackageSend2(uartfd,DID,P1);
}

void RunMotor(QSerialPort *uartfd, int DID)
{
    struct Package2 P1;
    P1.CmdID = CID_RUN_MOTOR;
    memset(P1.Data,0,4);

    PackageSend2(uartfd,DID,P1);
}


int wait4GetStop(int DID)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        getStop(myCom,DID);
        for(j=0;j<5;j++)
        {
            int rtnState = readData2();
            if (rtnState == STATE_STOP_FALSE)
            {
                qDebug("RUN!");
                return 1;
            }
            else if (rtnState == STATE_STOP_TURE)
            {
                qDebug("STOP");
                return 0;
            }
        }
    }
    return -1;
}

int wait4Forward(int DID)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        Forward(myCom,DID);
        for(j=0;j<5;j++)
        {
            int rtnState = readData2();
            if (rtnState == STATE_FORWARD)
            {
                qDebug("Forward OK!");
                return 1;
            }
        }
    }
    return -1;
}

int wait4StopRun(int DID)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        StopRun(myCom,DID);
        for(j=0;j<5;j++)
        {
            int rtnState = readData2();
            if (rtnState == STATE_STOP_RUN)
            {
                qDebug("Stop Run OK!");
                return 1;
            }
        }
    }
    return -1;
}

int wait4SetPul(int DID, int pulnum)
{
    int i,j;
    for(i=0;i<3;i++)
    {
        SetPul(myCom,DID,pulnum);
        for(j=0;j<5;j++)
        {
            int rtnState = readData2();
            if (rtnState == STATE_SET_PUL)
            {
                qDebug("STATE_SET_PUL OK!");
                return 1;
            }
        }
    }
    return -1;
}

int wait4Setup(int DID,int direction,int frequency)//设置电机方向以及频率 0 反转，1 正转
{
    int i,j;
    for(i=0;i<3;i++)
    {
        Setup(myCom,DID,direction,frequency);
        for(j=0;j<5;j++)
        {
            int rtnState = readData2();
            if (rtnState == STATE_SETUP)
            {
                qDebug("SETUP OK!");
                return 1;
            }
        }
    }
    return -1;
}

int wait4RunMotor(int DID)//运行电机
{
    int i,j;
    for(i=0;i<3;i++)
    {
        RunMotor(myCom,DID);
        for(j=0;j<5;j++)
        {
            int rtnState = readData2();
            if (rtnState == STATE_RUN_MOTOR)
            {
                qDebug("Run Motor OK!");
                return 1;
            }
        }
    }
    return -1;
}

int readData2()
{
    int i,j;
    for(j=0;j<10;j++)
    {
        waitTaskInfo(50);
        if(myCom->bytesAvailable()>=7)
        {
            QByteArray alldata = myCom->readAll();
            qDebug("Data recv:%d.", alldata.count());
            for(i=0;i<=alldata.size()-2;i++)
            {
             if((alldata.at(i+2) == 0x01))
                 break;
            }
            int pHead = i;
            while((alldata.size()-pHead) < 7)
            {
                waitTaskInfo(10);
                alldata += myCom->readAll();
            }
            unsigned char CID = 0;
            CID=(unsigned char)(alldata.at(pHead+4));
            if(CID == CID_SETUP)
            {
                qDebug("CID:SETUP");
                return STATE_SETUP;
            }
            else if(CID == CID_RUN_MOTOR)
            {
                qDebug("CID:RUN MOTOR");
                return STATE_RUN_MOTOR;
            }
            else if(CID == CID_SET_PUL)
            {
                qDebug("CID:SET PUL");
                return STATE_SET_PUL;
            }
            else if(CID == CID_GET_STOP)
            {
                if(alldata.at(i+5) == 0x00)
                {
                    qDebug("CID:FALSE");
                    return STATE_STOP_FALSE;
                }
                else
                {
                    qDebug("CID:TURE");
                    return STATE_STOP_TURE;
                }
            }
            else if(CID == CID_FORWARD)
            {
                qDebug("CID:FORWARD");
                return STATE_FORWARD;
            }
            else if(CID == CID_STOP_RUN)
            {
                qDebug("CID:STOP RUN");
                return STATE_STOP_RUN;
            }
            else
            {
                qDebug("CID:ERROR");
                return STATE_ERROR;
                }
        }
    }
}



