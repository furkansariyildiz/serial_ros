#!/usr/bin/env python3

import os
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='serial_ros2',
            executable='serial_ros2_test',
            name='serial_ros2_test_node',
            output='screen',
            parameters=[os.path.join(
                get_package_share_directory('serial_ros2'), 
                'config', 'config.yaml')])
    ])