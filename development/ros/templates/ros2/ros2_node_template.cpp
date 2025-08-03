#include "rclcpp/rclcpp.hpp"


class /*"<NODE_NAME>"*/Node : public rclcpp::Node {

public:
    /*"<NODE_NAME>"*/Node() : Node(/*"<NODE_NAME>"*/) {
        RCLCPP_INFO(this->get_logger(), /*"Started ... Node"*/);  
        auto qos_profile = rclcpp::QoS(rclcpp::KeepLast(10)).reliable().transient_local();

        /*<PUB_NAME>*/_ = this->create_publisher<...>(/*"<TOPIC_NAME>"*/, qos_profile);
        timer_ = this->create_wall_timer(std::chrono::seconds(1), 
            std::bind(&<Name>Node::/*<CLBCK_FUNC_NAME>*/, this));
    }

    void /*<CLBCK_FUNC_NAME>*/() {
        RCLCPP_INFO(this->get_logger(), "..%s..", ...);
        publisher_->publish(...);
    }

private:
    rclcpp::Publisher</*"<MESSAGE_TYPE>"*/>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};


int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared</*"<NODE_NAME>"*/>());
    rclcpp::shutdown();
    return 0;
}