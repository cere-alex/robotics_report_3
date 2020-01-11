#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <sstream>
int main(int argc, char **argv)
{
  ros::init(argc, argv, "int32_publisher"); //remmaping that were obtenined at command line 
  ros::NodeHandle n; //access point communication to ROS 
  ros::Publisher chatter_pub = n.advertise<std_msgs::Int32>("number_int", 1000);//This invokes a call to ROS master node, this create a publisher object that allow you publish messages, 1000 is the size ofte message queue use to publish 
  ros::Rate loop_rate(1);//It's a rate to our programm publish 
  int count = 0;
  while (ros::ok())
  {
    std_msgs::Int32 msg; //This the message object 
    msg.data = count; // filling the message
    ROS_INFO("%d", msg.data); // ros console publish
    chatter_pub.publish(msg); //sending the message
    ros::spinOnce(); //run once
    loop_rate.sleep();
    ++count;
  }
  return 0;
}