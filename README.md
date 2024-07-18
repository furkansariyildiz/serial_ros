# serial_ros
<p align="left">
  <img src="documents/ros2.png" style="width: 10%; height: 10%"/>
  <img src="documents/cpp.png" style="width: 10%; height: 10%"/>
</p>

### To build serial_ros2 package

```bash
cd ~ros2_ws/src && git clone https://github.com/furkansariyildiz/serial_ros.gitgit
```

```bash
cd ~ros2_ws && colcon build --symlink-install --packages-select serial_ros2
```

### For serial_ros2_test via ros2 run command
```bash
cd ~ros2_ws && source install/setup.bash
ros2 run serial_ros2 serial_ros2_test
```

### For serial_ros2_test via ros2 launch command
```bash
cd ~ros2_ws && source install/setup.bash
ros2 launch serial_ros2 serial_ros2_test.launch.py
```

### If you are using ros2 launch, you can configure config.yaml to set ROS2 parameters
```yaml
/serial_ros2_test_node:
  ros__parameters:
    timer_period: 0.01 # Main loop period
    port_name: "/dev/ttyX" # Port name of Serial Port
    baudrate: 115200 # Baudrate of serial Port 
    read_period: 0.01 # Read Period for serial
    write_period: 0.1 # Write Period for serial
    
```

### Contact with me all around the web:
[![LinkedIn Badge](https://img.shields.io/badge/LinkedIn-Profile-informational?style=flat&logo=linkedin&logoColor=white&color=0D76A8)](https://www.linkedin.com/in/furkan-sariyildiz/)
