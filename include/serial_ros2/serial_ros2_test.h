#ifndef SERIAL_ROS2_TEST_H
#define SERIAL_ROS2_TEST_H

#include <rclcpp/rclcpp.hpp>
#include <serial_ros2/serial_ros2.h>
#include "../../src/serial_ros2.cpp"


using namespace std;


class SerialROS: public rclcpp::Node
{
    private:

    public:
        SerialROS();
        ~SerialROS();

        rclcpp::TimerBase::SharedPtr _read_timer;
        rclcpp::TimerBase::SharedPtr _write_timer;

        void readFromSerialPort(void);
        void writeToSerailPort(void);

        string _port_name;

        int _baudrate;

        int _character_size;

        string _readed_data = "";

        string _data_to_be_written = "";

        Serial *_serial_pointer;

};  

#endif