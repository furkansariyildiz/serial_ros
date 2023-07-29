#include <serial_ros2/serial_ros2.h>

Serial::Serial(string port_name, int baudrate)
{
    _port_name = port_name;
    _baudrate = baudrate;
}


int Serial::openSerialPort(void)
{
    _serial_port = open(_port_name.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
    
    if(_serial_port < 0)
    {
        std::cerr << "Can not open serial port. Please check your USB or serial_name." << std::endl;
        return -1;        
    }

    return 0;
}


int Serial::prepareSerialPort(void)
{
    memset(&_tty, 0, sizeof(_tty));

    if(tcgetattr(_serial_port, &_tty) != 0)
    {
        std::cerr << "Can not prepare serial port. Check your USB connection." << std::endl;
        return -1;
    }

    cfsetospeed(&_tty, (speed_t)_baudrate);
    cfsetispeed(&_tty, (speed_t)_baudrate);

    _tty.c_cflag     &=  ~PARENB;           
    _tty.c_cflag     &=  ~CSTOPB;
    _tty.c_cflag     &=  ~CSIZE;
    _tty.c_cflag     |=  CS8;

    _tty.c_cflag     &=  ~CRTSCTS;           
    _tty.c_cc[VMIN]   =  1;                  
    _tty.c_cc[VTIME]  =  5;                  
    _tty.c_cflag     |=  CREAD | CLOCAL;      

    cfmakeraw(&_tty);
    tcflush(_serial_port, TCIFLUSH);

    if(tcsetattr(_serial_port, TCSANOW, &_tty) != 0)
    {
        std::cerr << "Can not configure Serial Port." << std::endl;
        return -1;
    }

    std::cout << "Serial configuration is completed." << std::endl;
    return 0;
}