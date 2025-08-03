#include <rclcpp/rclcpp.hpp>
#include <rclcpp_action/rclcpp_action.hpp>
#include /*<ACTION_MESSAGE_PATH>*/

using /*<ACTION_MESSAGE_ALIAS>*/ = /*<ACTION_MESSAGE_PATH>*/;
using GoalHandle = rclcpp_action::ServerGoalHandle</*<ACTION_MESSAGE_PATH>*/>;


class /*"<NODE_NAME>"*/Server : public rclcpp::Node {
  
public:
    /*"<NODE_NAME>"*/() : Node(/*"<NODE_NAME>"*/) {
  
    //OPTIONAL: RCLCPP_INFO(this->get_logger(), /*"Started ... Action Client Node"*/);
    action_server_ = rclcpp_action::create_server</*ACTION_MESSAGE_ALIAS*/>(
      this,
      /*"<CUSTOM_ACTION_NAME>"*/,
      std::bind(&/*"<NODE_NAME>"*/Server::handle_goal, this, std::placeholders::_1, std::placeholders::_2),
      std::bind(&/*"<NODE_NAME>"*/Server::handle_cancel, this, std::placeholders::_1),
      std::bind(&/*"<NODE_NAME>"*/Server::handle_accepted, this, std::placeholders::_1)
    );
  }

private:
  rclcpp_action::Server</*ACTION_MESSAGE_ALIAS*/>::SharedPtr action_server_;

  rclcpp_action::GoalResponse handle_goal(const rclcpp_action::GoalUUID &uuid, 
        std::shared_ptr<const /*<ACTION_MESSAGE_ALIAS>*/::Goal> goal) {
    (void)uuid; // Silence unused parameter warning
    return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
  }

  void handle_accepted(const std::shared_ptr<GoalHandle> goal_handle) {
    (void)goal_handle; // Silence unused parameter warning
    std::thread{std::bind(&/*"<NODE_NAME>"*/::execute, this, std::placeholders::_1), goal_handle}.detach();
  }

  rclcpp_action::CancelResponse handle_cancel(const std::shared_ptr<GoalHandle> goal_handle) {
    (void)goal_handle;  // Silence unused parameter warning
    RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
    return rclcpp_action::CancelResponse::ACCEPT;
  }

  void execute(const std::shared_ptr<GoalHandle> goal_handle) {
    const auto goal = goal_handle->get_goal();
    auto result = std::make_shared</*ACTION_MESSAGE_ALIAS*/::Result>();
    auto feedback = std::make_shared</*ACTION_MESSAGE_ALIAS*/::Feedback>();

    for (int i = 1; i <= goal->goal_value; ++i) {
      feedback->progress = i ;
      goal_handle->publish_feedback(feedback);
      rclcpp::sleep_for(std::chrono::milliseconds(500));
    }

    result->result_value = goal->goal_value;
    goal_handle->succeed(result);
    RCLCPP_INFO(this->get_logger(), "Goal succeeded");
  }
};

int main(int argc, char **argv) {
  rclcpp::init(argc, argv);
  auto node = std::make_shared</*"<NODE_NAME>"*/>();
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}