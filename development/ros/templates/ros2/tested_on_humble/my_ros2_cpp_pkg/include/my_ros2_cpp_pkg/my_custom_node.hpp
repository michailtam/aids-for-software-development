#ifndef _MY_CUSTOM_NODE_
#define _MY_CUSTOM_NODE_

#include "rclcpp/rclcpp.hpp"
#include <iostream>
#include <string>


class MyCustomNode : public rclcpp::Node
{
public:
    MyCustomNode() : Node("node_name") 
    {
        std::cout << "This is the node <node_name>" << std::endl;
    }
    ~MyCustomNode(); // Destructor if needed.
    void methodA();
    void methodB();

private:
    
};

#endif