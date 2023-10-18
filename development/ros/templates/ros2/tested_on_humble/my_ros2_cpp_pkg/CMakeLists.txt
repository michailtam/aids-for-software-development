cmake_minimum_required(VERSION 3.8)
project(my_ros2_cpp_pkg)

### Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)

### Create your libraries and link them against the rclcpp library (and others if desired) 
add_library(my_custom_node_lib src/my_custom_node.cpp)
ament_target_dependencies(my_custom_node_lib rclcpp)

### Add executables and link them against the createde libraries
add_executable(main_app src/main.cpp)
ament_target_dependencies(main_app rclcpp)
target_link_libraries(main_app my_custom_node_lib)

### Add the header files
include_directories(include)

### Install the executables
install(TARGETS
  main_app
  DESTINATION lib/${PROJECT_NAME}/
)

### Install the required folders
# install(DIRECTORY
#   launch urdf -> additional folders like config, sdf etc.
#   DESTINATION share/${PROJECT_NAME}/
# )

# if(BUILD_TESTING)
#   find_package(ament_lint_auto REQUIRED)
#   set(ament_cmake_copyright_FOUND TRUE)
#   set(ament_cmake_cpplint_FOUND TRUE)
#   ament_lint_auto_find_test_dependencies()
# endif()

ament_package()
