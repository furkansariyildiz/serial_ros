cmake_minimum_required(VERSION 3.8)
project(serial_ros2)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

include_directories(include ${BOOST_INCLUDE_DIRS})
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

add_library(serial_ros2 src/serial_ros2.cpp)


ament_target_dependencies(serial_ros2 rclcpp)
ament_export_targets(serial_ros2 HAS_LIBRARY_TARGET)


add_executable(serial_ros2_test src/serial_ros2_test.cpp)
target_link_libraries(serial_ros2_test ${catkin_LIBRARES})
ament_target_dependencies(serial_ros2_test rclcpp)

install(TARGETS
        serial_ros2_test
        DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY
        launch
        config
        DESTINATION share/${PROJECT_NAME}/
)

install(TARGETS
  serial_ros2
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/serial_ros2
        DESTINATION include
)


install(
  TARGETS serial_ros2
  EXPORT serial_ros2
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
  INCLUDES DESTINATION include
)

ament_export_include_directories(include)

ament_package()
