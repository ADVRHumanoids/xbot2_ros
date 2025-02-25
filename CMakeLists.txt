cmake_minimum_required(VERSION 3.16)
project(xbot2_ros)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

set(COMMON_TARGETS 
  rclcpp::rclcpp
  std_msgs::std_msgs__rosidl_typesupport_cpp
  )

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

# build
add_executable(robot_description_publisher src/robot_description_publisher.cpp)
target_link_libraries(robot_description_publisher 
  ${COMMON_TARGETS}
  )

add_executable(topic_echo src/topic_echo.cpp)
target_link_libraries(topic_echo 
${COMMON_TARGETS}
  )

install(TARGETS
  robot_description_publisher topic_echo
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
