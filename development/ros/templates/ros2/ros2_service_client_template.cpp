#include "rclcpp/rclcpp.hpp"
#include /*<SERVICE_MESSAGE_PATH>*/

using /*<SERVICE_MESSAGE_ALIAS>*/ = /*<SERVICE_MESSAGE_PATH>*/;


class /*"<NODE_NAME>"*/Client : public rclcpp::Node {

public:
    /*"<NODE_NAME>"*/Client() : Node(/*"<NODE_NAME>"*/) {

        RCLCPP_INFO(this->get_logger(), /*"Started ... Node"*/);  
        client_ = this->create_client</*SERVICE_MESSAGE_ALIAS*/>(/*<SERVICE_NAME>*/);
    }

    void send_request(const /*<SERVICE_MESSAGE_ALIAS>*/& /*<PARAMETER_NAME>*/, ...) {
        auto request = std::make_shared</*<SERVICE_MESSAGE_ALIAS>*/>::Request>();
        
        while (!client_->wait_for_service(std::chrono::seconds(1))) {
            if(!rclcpp::ok()) {
                RCLCPP_ERROR(this->get_logger(), "Interrupted while waiting for the service. Exiting.");
                return;
            }
            RCLCPP_INFO(this->get_logger(), "service not available, waiting again...");
        }

        auto future_result = client_->async_send_request(request);
        
        if (rclcpp::spin_until_future_complete(this->get_node_base_interface(), future_result) 
            == rclcpp::FutureReturnCode::SUCCESS) {
                /*<TO DO>*/
            }
        else {
            RCLCPP_ERROR(this->get_logger(), "Failed to call service /*<SERVICE_NAME>*/");
        }
    }

private:
    rclcpp::Client</*SERVICE_MESSAGE_ALIAS*/>::SharedPtr client_;
};


int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    auto client = std::make_shared</*"<NODE_NAME>"*/Client>();
    client->send_request(/*<REQUEST_PARAMETER>*/);
    rclcpp::shutdown();
    return 0;
}

