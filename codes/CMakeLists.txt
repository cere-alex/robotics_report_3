cmake_minimum_required(VERSION 2.8.3)
project(basic_pkg)
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  std_msgs
)

catkin_package()
include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(int32_publisher src/int32_publisher.cpp)
add_dependencies(int32_publisher cerealex)
target_link_libraries(int32_publisher ${catkin_LIBRARIES})
