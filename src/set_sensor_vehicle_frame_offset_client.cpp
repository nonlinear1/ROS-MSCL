#include "ros/ros.h"
#include "ros_mscl/SetSensorVehicleFrameOffset.h"
#include <cstdlib>


int main(int argc, char **argv){

  ros::init(argc, argv, "set_sensor_vehicle_frame_offset");

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<ros_mscl::SetSensorVehicleFrameOffset>("SetSensorVehicleFrameOffset");
  ros_mscl::SetSensorVehicleFrameOffset srv;

  srv.request.offset.x = atoll(argv[1]);
  srv.request.offset.y = atoll(argv[2]);
  srv.request.offset.z = atoll(argv[3]);


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
