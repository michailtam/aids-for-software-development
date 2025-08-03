#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include /*<ACTION_MESSAGE_PATH>*/

using /*<ACTION_MESSAGE_ALIAS>*/ = /*<ACTION_MESSAGE_PATH>*/;
using GoalHandle = rclcpp_action::ClientGoalHandle</*<ACTION_MESSAGE>*/>;


class /*"<NODE_NAME>"*/ : public rclcpp::Node {

public:

  /*"<NODE_NAME>"*/() : Node(/*"<NODE_NAME>"*/) {
  
    RCLCPP_INFO(this->get_logger(), "Started ... Node");  
    client_ = rclcpp_action::create_client</*<ACTION_MESSAGE_ALIAS>*/>(this, /*"<CUSTOM_ACTION_NAME>"*/);
    send_goal();
  }

  void send_goal() {
    if (!client_->wait_for_action_server()) {
      RCLCPP_ERROR(this->get_logger(), "Action server not available");
      return;
    }

    auto goal_msg = MyCustomAction::Goal();
    goal_msg.goal_value = 10;

    auto send_goal_options = rclcpp_action::Client</*<ACTION_MESSAGE_ALIAS>*/>::SendGoalOptions();
    send_goal_options.feedback_callback = [this](GoalHandle::SharedPtr, const std::shared_ptr<const /*<ACTION_MESSAGE_ALIAS>*/::Feedback> feedback) {
      RCLCPP_INFO(this->get_logger(), "Feedback: %.2f", feedback->progress);
    };
    send_goal_options.result_callback = [this](const GoalHandle::WrappedResult &result) {
      RCLCPP_INFO(this->get_logger(), "Result: %d", result.result->result_value);
    };

    client_->async_send_goal(goal_msg, send_goal_options);
  }

private:
  rclcpp_action::Client</*<ACTION_MESSAGE_ALIAS>*/>::SharedPtr client_;
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared</*"<NODE_NAME>"*/>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}