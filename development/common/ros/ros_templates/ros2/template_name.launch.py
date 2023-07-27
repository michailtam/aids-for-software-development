import os
from launch import LaunchDescription
from launch.substitutions import (Command, LaunchConfiguration)
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from launch_ros.parameter_descriptions import ParameterValue


def generate_launch_description():
    # Sets the path to required packages.
    pkg_share = FindPackageShare(package='robot_package').find('robot_package')

    # Sepcifies launch arguments received from the command line.
    use_sim_time = LaunchConfiguration('use_sim_time', default='true')
    
    # Process the URDF file
    urdf_path = os.path.join(pkg_share,'urdf', 'robot_description.xacro')
    robot_description = ParameterValue(Command(['xacro ', urdf_path]), value_type=str)
    
    # Subscribes to the joint states of the robot, and publishes the 3D pose of each link.
    ros2_or_custom_node = Node(
        package='package_name',
        executable='executable_name',
        name='optional_name',
        output='screen',
        parameters=[{
            'use_sim_time': use_sim_time, 
            'robot_description': robot_description}],
        )

    ...

    # Creates the launch description and populate.
    ld = LaunchDescription()
    
    # Adds the actions.
    ld.add_action(ros2_or_custom_node)
    ...
    
    return ld



