#ifndef SERIAL_H
#define SERIAL_H

#include <rclcpp/rclcpp.hpp>
#include <iostream>
#include <string>
#include <cstring>
#include <fcntl.h>
#include <termios.h>
#include <unistd.h>


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
        string readSerialPort(int character_size);


        struct termios _tty;

        int _serial_port;

        string _port_name;
        
        int _baudrate;

        int _bytes = 0;

        char _buffer[256];

        string _readed_data = "";



};

#endif