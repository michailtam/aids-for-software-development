#include "rclcpp/rclcpp.hpp"
#include /*<SERVICE_MESSAGE_PATH>*/

using /*<SERVICE_MESSAGE_ALIAS>*/ = /*<SERVICE_MESSAGE_PATH>*/;


class /*"<NODE_NAME>"*/Server : public rclcpp::Node {

public:
    /*"<NODE_NAME>"*/Server() : Node(/*"<NODE_NAME>"*/) {
        RCLCPP_INFO(this->get_logger(), /*"Started ... Node"*/);

        server_ = this->create_service</*SERVICE_MESSAGE_ALIAS*/>(
            /*"<SERVICE_NAME_OBJECT>"*/, 
            std::bind(&/*"<NODE_NAME>"*/Server::/*<CLBCK_FUNC_NAME>*/, this, std::placeholders::_1, ...));
    }

private:
    void /*<CLBCK_FUNC_NAME>*/(const std::shared_ptr</*SERVICE_MESSAGE_ALIAS*/>::Request> request,
                        std::shared_ptr</*SERVICE_MESSAGE_ALIAS*/>::Response> response) 
    {
        response->/*<SERVICE_MESSAGE_RESPONSE_FIELD>*/ = request->/*<SERVICE_MESSAGE_REQUEST_FIELD>*/ ...
        RCLCPP_INFO(this->get_logger(), "..%s..", request->/*<SERVICE_MESSAGE_REQUEST_FIELD>*/.c_str());    
    }

    rclcpp::Service</*SERVICE_MESSAGE_ALIAS>*/::SharedPtr server_;
};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared</*"<NODE_NAME>"*/Server>());
    rclcpp::shutdown();
    return 0;
}