### NOTE
# If you encounter the following error while executing colcon build 
# ModuleNotFoundError: No module named 'em', then install empy of python version 3.x:
# $ pip install empy -i https://pypi.tuna.tsinghua.edu.cn/simple and 
# $ pip install lark -i https://pypi.tuna.tsinghua.edu.cn/simple
# Source: https://daobook.github.io/ros-book/docs/other/errors.html

cmake_minimum_required(VERSION 3.8)
project(my_custom_msgs_srvs_actions)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/CustomMessage.msg"
  "srv/CustomService.srv" 
  "action/CountUntil.action"
)

ament_export_dependencies(rosidl_default_runtime)

ament_package()
