from setuptools import setup

package_name = 'package_name'

setup(
    name=package_name,
    version='0.0.0',
    packages=[package_name],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ed',
    maintainer_email='ed@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            "node_name = package_name.py_file_name:function_to_launch"
            # EXAMPLE: "number_counter = ros2_app_py.number_counter:main"
        ],
    },
)