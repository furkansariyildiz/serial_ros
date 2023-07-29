#include <serial_ros2/serial_ros2_test.h>


SerialROS::SerialROS():
Node("serial_ros_node")
{
    _read_timer = this->create_wall_timer(1ms, std::bind(&SerialROS::readFromSerialPort, this));
    _write_timer = this->create_wall_timer(10ms, std::bind(&SerialROS::writeToSerailPort, this));
}
