#ifndef SERIAL_H
#define SERIAL_H

#include <rclcpp/rclcpp.hpp>
#include <iostream>
#include <string>
#include <cstring>
#include <fcntl.h>
#include <termios.h>


using namespace std;

class Serial
{
    private:
        int serial_port_;
        int baudrate_;


    protected:

    public:
        Serial(string port_name, int baudrate);
        ~Serial(void);

        int openSerialPort(void);
        int prepareSerialPort(void);
        int writeSerialPort(string data);
        int readSerialPort(void);


        struct termios _tty;

        int _serial_port;

        string _port_name;
        
        int _baudrate;

        char _buffer[256];

        string _readed_data = "";



};

#endif