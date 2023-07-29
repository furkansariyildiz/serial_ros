#include <serial_ros2/serial_ros2.h>

Serial::Serial(string port_name, int baudrate)
{
    _port_name = port_name;
    baudrate_ = baudrate;
}

Serial::~Serial(void)
{
    close(serial_port_);
}

int Serial::openSerialPort(void)
{
    serial_port_ = open(_port_name.c_str(), O_RDWR | O_NOCTTY | O_NDELAY);
    
    if(serial_port_ < 0)
    {
        std::cerr << "Can not open serial port. Please check your USB or serial_name." << std::endl;
        close(serial_port_);
        return -1;        
    }

    return 0;
}


int Serial::prepareSerialPort(void)
{
    memset(&_tty, 0, sizeof(_tty));

    if(tcgetattr(serial_port_, &_tty) != 0)
    {
        std::cerr << "Can not prepare serial port. Check your USB connection." << std::endl;
        close(serial_port_);
        return -1;
    }

    cfsetospeed(&_tty, (speed_t)baudrate_);
    cfsetispeed(&_tty, (speed_t)baudrate_);

    _tty.c_cflag     &=  ~PARENB;           
    _tty.c_cflag     &=  ~CSTOPB;
    _tty.c_cflag     &=  ~CSIZE;
    _tty.c_cflag     |=  CS8;

    _tty.c_cflag     &=  ~CRTSCTS;           
    _tty.c_cc[VMIN]   =  1;                  
    _tty.c_cc[VTIME]  =  5;                  
    _tty.c_cflag     |=  CREAD | CLOCAL;      

    cfmakeraw(&_tty);
    tcflush(serial_port_, TCIFLUSH);

    if(tcsetattr(serial_port_, TCSANOW, &_tty) != 0)
    {
        std::cerr << "Can not configure Serial Port." << std::endl;
        close(serial_port_);
        return -1;
    }

    std::cout << "Serial configuration is completed." << std::endl;
    return 0;
}


string Serial::readSerialPort(int character_size)
{
    _readed_data = "";
    
    while(_readed_data.size() <= (std::size_t)character_size)
    {
        _bytes = read(serial_port_, _buffer, sizeof(_buffer));
        _readed_data = _readed_data + string(_buffer, _bytes);
    }

    return _readed_data;
}


int Serial::writeSerialPort(string data)
{
    write(serial_port_, data.c_str(), data.size());
    return 0;
}

