# `xbot_ros` Package

This package provides a ROS 2 node called `robot_description_publisher` that reads a robot's URDF and optional SRDF files and publishes them on corresponding ROS 2 topics.

---


## Node: `robot_description_publisher`

### Purpose
The `robot_description_publisher` node:
- Publishes the URDF robot description on the topic `/robot_description`.
- Publishes the SRDF semantic robot description on the topic `/robot_description_semantic`.

---



## How to Run the Node

Run the node using the `ros2 run` command and provide the required parameters for the robot descriptions:
```bash
    ros2 run xbot_ros robot_description_publisher \
    --ros-args \
    -p robot_description:="path/to/your_robot.urdf)" \
    -p robot_description_semantic:="path/to/your_robot.srdf"
```
