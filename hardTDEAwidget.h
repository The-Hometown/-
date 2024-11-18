﻿#ifndef HARDTDEAWIDGET_H
#define HARDTDEAWIDGET_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <random>
#include <ctime>
#include <QWidget>
#include <QDebug>
//#include <chrono>
//#include <thread>
#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>

using namespace std;

namespace Ui { class hardTDEAwidget; }

class hardTDEAwidget : public QWidget
{
    Q_OBJECT

public:
    explicit hardTDEAwidget(QWidget *parent = 0);
    ~hardTDEAwidget();

private slots:
    void genpushButton_click();
    void filepushButton_click();
    void keypushButton_click();
    void encryptpushButton_click();
    void decryptpushButton_click();
    void backpushButton_click();

signals:
    void sendsignal();

private:
    Ui::hardTDEAwidget *ui;

    void serial_inf();
    void chartostring(unsigned char s);
    std::string charToHex(unsigned char ch);
    QByteArray stringtoarray(string s);
    unsigned char stringtochar(string s);
    std::string intToHex(int value);
    int hexToInt(std::string hexStr);

    void genKey(std::string outputname);
    void getKey(std::string filename);
    void encrypt(std::string in_hex_str);
    void decrypt(std::string in_hex_str);
    bool encrypt_file(const string filename);
    bool decrypt_file(const string filename);
    void dataRead();
    string dataProcess();

    QByteArray des3_cmd;
    QByteArray encrypt_signal;     // 加密信号
    QByteArray decrypt_signal;     // 解密信号
    QByteArray recvd;
    QByteArray set_key1;
    QByteArray set_key2;
    QByteArray set_key3;
    QByteArray set_key;     // 设置密钥信号
//    QByteArray send_key;    // 发送密钥信号
    QByteArray set_pt;     // 设置明文信号
    QByteArray send_pt;    // 发送明文信号


    QSerialPort *serial_port;
    QString port_name;

    string infile_path;
    string key_path;

    string key_str;
    string key1_str;
    string key2_str;
    string key3_str;
    QByteArray readdata;
};

#endif // HARDTDEAWIDGET_H
