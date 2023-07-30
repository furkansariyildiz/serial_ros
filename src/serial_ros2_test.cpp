#include <serial_ros2/serial_ros2_test.h>


SerialROS::SerialROS():
Node("serial_ros_node")
{
    _read_timer = this->create_wall_timer(1ms, std::bind(&SerialROS::readFromSerialPort, this));
    _write_timer = this->create_wall_timer(10ms, std::bind(&SerialROS::writeToSerailPort, this));

    declare_parameter("port_name", "/dev/ttyACM0");
    declare_parameter("baudrate", "19200");
    declare_parameter("character_size", 150);

    _port_name = this->get_parameter("port_name").as_string();
    _baudrate = this->get_parameter("baudrate").as_int();
    _character_size = this->get_parameter("character_size").as_int();

    RCLCPP_INFO_STREAM(this->get_logger(), "Serial Port Name: " << _port_name);
    RCLCPP_INFO_STREAM(this->get_logger(), "Serial Baudrate: " << _baudrate);
    RCLCPP_INFO_STREAM(this->get_logger(), "Readed character size as byte: " << _character_size);

    Serial serial = Serial("/dev/ttyACM0", B19200);
    _serial_pointer = &serial;
}


void SerialROS::readFromSerialPort(void)
{
    _readed_data = _serial_pointer->readSerialPort(_character_size);
    RCLCPP_INFO_STREAM(this->get_logger(), "Readed Data From Serial: " << _readed_data);
}


void SerialROS::writeToSerailPort(void)
{
    _data_to_be_written = "Hello From ROS2 Serial...";
    _serial_pointer->writeSerialPort(_data_to_be_written);
}


int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<SerialROS>());
    return 0;
}