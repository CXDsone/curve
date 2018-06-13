#ifndef UART4_H
#define UART4_H
#include <QSerialPort>
#include <QSerialPortInfo>

#define CID_GET_LOAD            0x03        //获取载重
#define CID_GET_STOP            0x02        //读取电机是否运行到位
#define CID_SET_PUL             0x03        //设置脉冲
#define CID_SETUP               0x04        //设置电机方向以及频率
#define CID_GETI4               0x0c        //读取输入信号
#define CID_RUN_MOTOR           0x09        //运行电机
#define CID_FORWARD             0X07        //正向一直运转
#define CID_STOP_RUN             0x06        //停止运行

#define CID_GET_SWITCH          0X02        //获取接触状态

enum
{
    STATE_GET_LOAD,                         //获取载重
    STATE_SWITCH_OFF,
    STATE_SWITCH_ON,

    STATE_STOP_TURE,
    STATE_STOP_FALSE,
    STATE_SETUP,
    STATE_STOP_RUN,
    STATE_FORWARD,
    STATE_SET_PUL,
    STATE_RUN_MOTOR,
    STATE_GETI4_OFF,
    STATE_GETI4_ON,

    STATE_ERROR
};

struct Package1
{
    char DevID;
    char CmdID;
    char RegisterAddress[2];                //从保持寄存器某一地址开始读取
    char RegisterNum[2];                    //读取寄存器的个数
    char CheckSum[2];
};

struct Package2
{
    char Header[2];
    char DevID[2];
    char CmdID;
    char Data[4];
    char CheckSum;
};

void waitTaskInfo(int tim);
bool createSerialPort(unsigned int baudRate);
void setSerialPort(unsigned int baudRate);
void closeSerialPort();
unsigned short CRC_GetModbus16(unsigned char *pdata, int len);


void PackageSend1(QSerialPort* uartfd,int DID, struct Package1 data);

void GetLoad(int DID);   //0x03 获取载重
void GetSwitch(int DID); //0x02 输入状态

int wait4GetLoad(int DID);                  //发送获取载重指令
int wait4GetSwitch(int DID);                //发送获取输入状态
int readData1(int DID);

void PackageSend2(QSerialPort* uartfd,int DID[2], struct Package2 data);
void getStop(QSerialPort* uartfd,int DID);
void SetPul(QSerialPort* uartfd,int DID,int pulnum);
void Setup(QSerialPort* uartfd,int DID,int direction,int frequency);  //0x04 设置电机方向以及频率
void RunMotor(QSerialPort* uartfd,int DID);                           //0x09 运行电机
void Forward(QSerialPort *uartfd, int DID);                           //0x07 电机一直正向运行
void StopRun(QSerialPort *uartfd, int DID);                           //0x06 电机停止运行

int wait4GetStop(int DID);
int wait4SetPul(int DID,int pulnum);
int wait4Setup(int DID,int direction,int frequency);
int wait4RunMotor(int DID);
int wait4Forward(int DID);
int wait4StopRun(int DID);
int readData2();

QByteArray serialRead();

#endif // UART4STM_H
