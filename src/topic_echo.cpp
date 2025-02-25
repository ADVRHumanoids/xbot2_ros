#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>
#include <rclcpp/wait_for_message.hpp>

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = rclcpp::Node::make_shared("topic_echo");

    // get timeout from parameter
    auto timeout = std::chrono::seconds(node->declare_parameter("timeout", 10));

    // check arg was given
    if(argc != 2)
    {
        RCLCPP_ERROR(node->get_logger(), "No topic name given");
        return 1;
    }

    std::string topic_name = argv[1];

    // wait for message on given topic, print it, exit

    auto callback = [](std_msgs::msg::String::SharedPtr msg)
    {
        // print message to stdout
        std::cout << msg->data << std::endl;

        // exit
        rclcpp::shutdown();
    };

    auto sub = node->create_subscription<std_msgs::msg::String>(
        topic_name,
        rclcpp::QoS(1).transient_local(),
        callback);

    // set timer to shutdown if no message received
    auto timer = node->create_wall_timer(timeout, [&](){
        RCLCPP_ERROR(node->get_logger(), "No message received on topic %s", topic_name.c_str());
        rclcpp::shutdown();
    });
    
    // wait for message
    rclcpp::spin(node);
    

}