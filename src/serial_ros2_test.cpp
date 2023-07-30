#include <serial_ros2/serial_ros2_test.h>


SerialROS::SerialROS():
Node("serial_ros_node")
{
    _read_timer = this->create_wall_timer(1ms, std::bind(&SerialROS::readFromSerialPort, this));
    _write_timer = this->create_wall_timer(10ms, std::bind(&SerialROS::writeToSerailPort, this));

    declare_parameter("port_name", "/dev/ttyACM0");
    declare_parameter("baudrate", "19200");

    _port_name = this->get_parameter("port_name").as_string();
    _baudrate = this->get_parameter("baudrate").as_int();

    RCLCPP_INFO_STREAM(this->get_logger(), "Serial Port Name: " << _port_name);
    RCLCPP_INFO_STREAM(this->get_logger(), "Serial Baudrate: " << _baudrate);

    Serial serial = Serial("/dev/ttyACM0", B19200);
    _serial_pointer = &serial;
}


void SerialROS::readFromSerialPort(void)
{

}


void SerialROS::writeToSerailPort(void)
{

}


int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SerialROS>());
    return 0;
}