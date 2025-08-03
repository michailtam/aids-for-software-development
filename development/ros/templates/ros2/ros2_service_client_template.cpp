#include "rclcpp/rclcpp.hpp"


class <CLIENT_NAME>Client : public rclcpp::Node {

public:
    <CLIENT_NAME>Client() : Node("<CLIENT_NODE_NAME>") {

        RCLCPP_INFO(this->get_logger(), "...");  
        <CLIENT_NAME>_ = this->create_client<<SRV_DATA_TYPE>>("<SERVICE_NAME>");
    }

    void send_request(const <SRV_REQUEST_FIELD>& <PARAMETER_NAME>, <OPTIONAL_ADDITIONAL_SRV_REQUEST_FIELDS>) {
        auto request = std::make_shared<<SRV_DATA_TYPE>>::Request>();
        
        while (!client_->wait_for_service(std::chrono::seconds(1))) {
            if(!rclcpp::ok()) {
                RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for the service. Exiting.");
                return;
            }
            RCLCPP_INFO(this->get_logger(), "service not available, waiting again...");
        }

        auto future_result = <CLIENT_NAME>_->async_send_request(request);
        
        if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), future_result) 
            == rclcpp::FutureReturnCode::SUCCESS) {
                RCLCPP_INFO(this->get_logger(), "..%s..", future_result.get()-><SRV_REPLY_FIELD>.c_str());
            }
        else {
            RCLCPP_ERROR(this->get_logger(), "Failed to call service <SERVICE_NAME>");
        }
    }

private:
    rclcpp::Client<<SRV_DATA_TYPE>>::SharedPtr <CLIENT_NAME>_;
};


int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    auto client = std::make_shared<<CLIENT_NAME>Client>();
    client->send_request(...);
    rclcpp::shutdown();
    return 0;
}

