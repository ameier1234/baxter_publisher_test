#include "ros/ros.h"
#include "baxter_core_msgs/JointCommand.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "publisher");
  ros::NodeHandle n;
  ros::Publisher pub  = n.advertise<baxter_core_msgs::JointCommand>("/robot/limb/left/joint_command", 1000);


  baxter_core_msgs::JointCommand cmd;


  cmd.mode = baxter_core_msgs::JointCommand::POSITION_MODE;
  cmd.names.push_back("left_w0");
  cmd.names.push_back("left_w1");
  cmd.names.push_back("left_w2");
  cmd.names.push_back("left_e0");
  cmd.names.push_back("left_e1");
  cmd.names.push_back("left_s0");
  cmd.names.push_back("left_s1");
  cmd.command.resize(cmd.names.size());

  for(int i = 0; i < 7; i++)
    {
      cmd.command[i] = 0;
    }
  ros::Rate loop_rate(10);
  while(ros::ok())
    {
      cmd.command[3] += 0.5;
      pub.publish(cmd);


    }
  pub.publish(cmd);

  return 0;


}
