#include "rclcpp/rclcpp.hpp"


class <SERVICE_NAME>Server : public rclcpp::Node {

public:
    <SERVICE_NAME>Server() : Node("<SERVICE_NODE_NAME>") {
        RCLCPP_INFO(this->get_logger(), "...");

        server_ = this->create_service<<SRV_DATA_TYPE>>(
            "<SERVICE_NAME>", 
            std::bind(&<SERVICE_NAME>Server::<CLBCK_FUNC_NAME>, this, std::placeholders::_1, ...));
    }

private:
    void <CLBCK_FUNC_NAME>(const std::shared_ptr<<SRV_DATA_TYPE>::Request> request,
                        std::shared_ptr<<SRV_DATA_TYPE>::Response> response) 
    {
        response-><SRV_RESPONSE_FIELD> = request-><SRV_REQUEST_FIELD> ...
        RCLCPP_INFO(this->get_logger(), "..%s..", request-><SRV_REQUEST_FIELD>.c_str());    
    }

    rclcpp::Service<<SRV_DATA_TYPE>>::SharedPtr server_;
};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<<SERVICE_NAME>Server>());
    rclcpp::shutdown();
    return 0;
}