#include "ros/ros.h"
#include "std_msgs/String.h"

#include <iiwa_msgs/JointPosition.h>
#include <iiwa_msgs/JointQuantity.h>

#include <sstream>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "iiwa_test");
    ros::NodeHandle n;

    ros::Publisher iiwa_joint_pub = n.advertise<iiwa_msgs::JointPosition>("/iiwa/command/JointPosition", 1000);

    ros::Rate loop_rate(10);
    iiwa_msgs::JointPosition home_pos;

    while (ros::ok())
    {
        home_pos.position.a1 = 0.0;
        home_pos.position.a2 = 0.0;
        home_pos.position.a3 = 0.0;
        home_pos.position.a4 = 0.0;
        home_pos.position.a5 = 0.0;
        home_pos.position.a6 = 0.0;
        home_pos.position.a7 = 0.0;

        iiwa_joint_pub.publish(home_pos);

        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}