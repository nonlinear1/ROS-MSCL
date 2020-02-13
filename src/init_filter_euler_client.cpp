#include "ros/ros.h"
#include "ros_mscl/SetBias.h"
#include <cstdlib>


int main(int argc, char **argv){

  ros::init(argc, argv, "set_bias_client");

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<ros_mscl::SetBias>("SetBias");
  ros_mscl::SetBias srv;

  srv.request.code = atoll(argv[1]);
  srv.request.bias_data_vector_1.x = atoll(argv[2]);
  srv.request.bias_data_vector_1.y = atoll(argv[3]);
  srv.request.bias_data_vector_1.z = atoll(argv[4]);


  if (client.call(srv))
  {
      if (srv.response.success)
      {
        ROS_INFO("success");
      }
  }
  else
  {
    ROS_INFO("Failed to call service");
  }
  return 0;
}
