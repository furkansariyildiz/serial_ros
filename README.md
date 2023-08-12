# serial_ros
<p align="left">
  <img src="documents/ros2.png" style="width: 10%; height: 10%"/>
  <img src="documents/cpp.png" style="width: 10%; height: 10%"/>
</p>

### To build serial_ros2 package

```bash
cd ~ros2_ws/src && git clone git@github.com:furkansariyildiz/serial_ros.git
```

```bash
cd ~ros2_ws && colcon build --symlink-install --packages-select serial_ros2
```

### For serial_ros2_test via using ros2 run command
```bash
cd ~ros2_ws && source install/setup.bash
ros2 run serial_ros2 serial_ros2_test
```

### For serial_ros2_test via using ros2 launch command
```bash
cd ~ros2_ws && source install/setup.bash
ros2 launch serial_ros2 serial_ros2_test.launch.py
```

### Contact with me all around the web:
[![LinkedIn Badge](https://img.shields.io/badge/LinkedIn-Profile-informational?style=flat&logo=linkedin&logoColor=white&color=0D76A8)](https://www.linkedin.com/in/furkan-sariyildiz/)
