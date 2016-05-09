#include <ros/ros.h>
#include <arscontrol_simulations/ReqLaunch.h>
#include <stdlib.h>

bool launcher(arscontrol_simulations::ReqLaunch::Request &req,
         arscontrol_simulations::ReqLaunch::Response &res)
{
  ROS_INFO("Launching the following string.\n%s", req.str.c_str());
  system("echo -n '1. Current Directory is '; pwd");
//  std::string command("rosrun turtlesim turtlesim_node ");
  std::string command("echo");
  command = command + " '" + req.str.c_str() +"' | roslaunch - ";
  ROS_WARN("%s", command.c_str());
  system(command.c_str());
  res.data.data=true;
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "launch_by_service");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("launch_by_service", launcher);
  ROS_INFO("Ready to launch.");
  ros::spin();

  return 0;
}

